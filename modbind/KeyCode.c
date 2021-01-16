//% ----------------------------------------------------------------------- %//
				//% USES AND DEFINES %//
//% ----------------------------------------------------------------------- %//
/* Для того, чтобы работалы современные функции. */
#define _WIN32_IE 0x301
#define WINVER 0x0500
#define _WIN32_WINNT 0x0501

#include <windows.h>

//% ----------------------------------------------------------------------- %//
				//% TYPE %//
//% ----------------------------------------------------------------------- %//

//% ----------------------------------------------------------------------- %//
				//% CONST %//
//% ----------------------------------------------------------------------- %//

//% ----------------------------------------------------------------------- %//
				//% GLOBAL VAR %//
//% ----------------------------------------------------------------------- %//
HWND hwnd;
HHOOK hhook;
HANDLE hTickThread;
char key1[50] = "";
char key2[50] = "";
char key3[50] = "";
char key4[50] = "";
bool caps_down;
WPARAM wParam1;

//% ----------------------------------------------------------------------- %//
				//% PROCEDURES %//
//% ----------------------------------------------------------------------- %//

LRESULT __stdcall keyproc( int code, WPARAM wParam, LPARAM lParam ) {
	int vkCode = ((KBDLLHOOKSTRUCT*) lParam)->scanCode;
	
	itoa(vkCode, key1, 10);
	
	vkCode = ((KBDLLHOOKSTRUCT*) lParam)->vkCode;
	
	itoa(vkCode, key2, 10);
	
	vkCode = ((KBDLLHOOKSTRUCT*) lParam)->flags;
	
	for (int i = 0; i<8; i++) {
		if (vkCode%2 == 0) {
			key3[i] = '0';
		} else {
			key3[i] = '1';
		}
		vkCode /= 2; 
	}	
	key3[8] = '\0';
	
	//itoa(vkvk, key3, 10);
	
	vkCode = ((KBDLLHOOKSTRUCT*) lParam)->dwExtraInfo;
	
	itoa(vkCode, key4, 10);
	
	//itoa( LOWORD(GetKeyboardLayout(0)), key2, 10);
	
	wParam1 = wParam;
	
	InvalidateRect(hwnd, NULL, false);
	
	return CallNextHookEx( hhook, WH_KEYBOARD_LL, wParam, lParam );
};

/* ------------------------------------------------------------------------- */
/* Процедура обработки сообщений. */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch ( msg ) {
		case WM_DESTROY:{
			/* Когда окно разрушается. */
			PostQuitMessage( 0 );
			return 0;
		};break;case WM_CREATE:{
			/* Вызывается, когда должно быть создано окно. */
			//@ ----------------------------------------------------------------------- @//

			/* Здесь создается хук. */
			hhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyproc, NULL, 0);
			if (NULL == hhook) {
			    MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
			}
			
			//@ ----------------------------------------------------------------------- @//
			return 0;
		};break;case WM_PAINT:{
			/* Сообщение посылается, когда нужно отрисовать рабочую область. */
			static HDC hdc;
			static PAINTSTRUCT ps;
			
			hdc = BeginPaint( hwnd, &ps );
			/* Рисование здесь. */
			PatBlt(hdc, 0,0,250,100,PATCOPY);
			TextOut(hdc, 0,0, "Scan", 4);
			TextOut(hdc, 50,0, "Vk", 2);
			TextOut(hdc, 100,0, "Flags", 5);
			TextOut(hdc, 200,0, "Extra", 5);
			TextOut(hdc, 0,20, key1, strlen(key1));
			TextOut(hdc, 50,20, key2, strlen(key2));
			TextOut(hdc, 100,20, key3, strlen(key3));
			TextOut(hdc, 200,20, key4, strlen(key4));
			
			if (wParam1 == WM_KEYUP) {
				TextOut(hdc, 0,40, "KeyUp", 5);
			} else {
				TextOut(hdc, 0,40, "KeyDown", 7);
			}
			
			TextOut(hdc, 100,40, "01234567", 8);
			
			
			EndPaint( hwnd, &ps );
			return 0;
		};break;default:
			return DefWindowProc( hwnd, msg, wParam, lParam );
	};
}
/* ------------------------------------------------------------------------- */

void mySetWindowSize(int width, int height) {                                                       
	/* Процедура задает размер окна с учетом рамки. */                                          
	RECT rcClient, rcWindow;                                                                    
	POINT ptDiff;                                                                               
                                                                                                    
	GetClientRect( hwnd, &rcClient );                                                           
	GetWindowRect( hwnd, &rcWindow );                                                           
                                                                                                    
	ptDiff.x = (rcWindow.right - rcWindow.left) - rcClient.right;                               
	ptDiff.y = (rcWindow.bottom - rcWindow.top) - rcClient.bottom;                              
                                                                                                    
	/* Изменяется размер. */                                                                    
	MoveWindow( hwnd, rcWindow.left, rcWindow.top, width + ptDiff.x, height + ptDiff.y, false); 
}
                                                                                                   
//% ----------------------------------------------------------------------- %//

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	/* ------------------------------------------------------------------------- */
	/* Создание структуры окна. */
	WNDCLASSEX wc;
	wc.cbSize = sizeof( WNDCLASSEX ); /* Устанавливает размер этой структуры, в байтах. */
	wc.style = CS_DBLCLKS | CS_HREDRAW | CS_PARENTDC | CS_SAVEBITS; /* Устанавливает стиль класса. */
	wc.lpfnWndProc = WndProc; /* Указатель на оконную процедуру. */
	wc.cbClsExtra = 0; /* Устанавливает число дополнительных байт, которые размещаются вслед за структурой класса окна. */
	wc.cbWndExtra = 0; /* Устанавливает число дополнительных байтов, которые размещаются вслед за экземпляром окна. */
	wc.hInstance = hInstance; /* Дескриптор экземпляра, который содержит оконную процедуру для класса. */
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION ); /* Дескриптор значка класса. */
	wc.hCursor = LoadCursor( NULL, IDC_ARROW ); /* Дескриптор курсора класса. */
	wc.hbrBackground = (HBRUSH) COLOR_WINDOW; /* Дескриптор кисти фона класса. */
	wc.lpszMenuName = NULL; /* Имя строки, которая в файле ресурсов представляется как меню. */
	wc.lpszClassName = "hook_class"; /* Имя класса окна. */
	wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION ); /* Дескриптор маленького значка, который связан с классом окна. */
	/* Регистрация окна и обработка ошибки. */
	/* Функция регистрирует класс окна для последующего использования при вызове функции CreateWindow или CreateWindowEx. */
	if ( !RegisterClassEx(&wc) ) {
		MessageBox( NULL, "Failed to register window class.", "Error", MB_OK );
		return 0;
	}
	/* ------------------------------------------------------------------------- */

	/* ------------------------------------------------------------------------- */
	hwnd = CreateWindowEx( /* Создает окно с расширенным стилем. */
		WS_EX_OVERLAPPEDWINDOW, /* Определяет расширенный стиль создаваемого окна. */
		"hook_class", /* Указатель на строку с символом нуля в конце или атом класса, созданный предшествующим вызовом функции RegisterClassEx. */
		"Hook Test", /* Указатель на строку, с символом нуля в конце, которая устанавливает имя окна. */
		WS_TILEDWINDOW, /* Определяет стиль создаваемого окна. */
		CW_USEDEFAULT, /* Определяет начальную горизонтальную позицию окна. */
		0, /*  Определяет начальную вертикальную позицию окна. */
		200, /* Определяет ширину окна в единицах измерения для устройства. */
		30, /* Определяет высоту окна в единицах измерения устройства. */
		NULL, /* Дескриптор окна родителя или владельца создаваемого окна. */
		NULL, /* Дескриптор меню. */
		hInstance, /* Дескриптор экземпляра модуля, который будет связан с окном. */
		NULL /* Указывает на значение, переданное окну через структуру CREATESTRUCT, переданную в параметре lParam сообщения WM_CREATE. */
	);
	/* ------------------------------------------------------------------------- */
	
	mySetWindowSize(250, 70);
	
	/* Показ окна. */
	UpdateWindow( hwnd );
	ShowWindow( hwnd, SW_SHOW );
	
	/* Здесь можно рисовать или запускать потоки. */
	/* Всё что нарисовано здесь, отобразится на экране после его появления. */
	
	/* Обработка сообщений. */
	MSG msg;
	BOOL bRet;
	
	while( (bRet = GetMessage( &msg, NULL, 0, 0 )) != 0) { 
		if (bRet == -1) {
			/* Обработка ошибки и возможный выход из программы. */
		} else {
			TranslateMessage( &msg ); 
			DispatchMessage( &msg ); 
		}
	}
	
	UnhookWindowsHookEx(hhook);
	
	return 0;
}