//% ----------------------------------------------------------------------- %//
				//% USES AND DEFINES %//
//% ----------------------------------------------------------------------- %//
/* Для того, чтобы работалы современные функции. */
#define _WIN32_IE 0x301
#define WINVER 0x0500
#define _WIN32_WINNT 0x0501

#include <windows.h> 

#define touchIf(scanCode1, vkCode2, scanCode2) if (scanCode == scanCode1) { scanCodeB = scanCode2; vkCodeB = vkCode2; hTickThread = CreateThread( NULL, 0, &tickThreadProcVk3, wParam, 0, NULL ); ButtonPressed = true; }

//% ----------------------------------------------------------------------- %//
				//% GLOBAL VAR %//
//% ----------------------------------------------------------------------- %//
HHOOK hhook;
HANDLE hTickThread;
int scanCode = 0;
int vkCode = 0;
int extraInf = 0;
int vkCodeB;
int scanCodeB;
int vkCodeB7;
int scanCodeB7;
DWORD AltTime = GetTickCount();
bool keyUp;
bool keyDown;
bool ButtonPressed;
bool AltPressed = false;
bool modDown = false;
WPARAM wParam1;

//% ----------------------------------------------------------------------- %//
				//% PROCEDURES %//
//% ----------------------------------------------------------------------- %//
DWORD WINAPI tickThreadProcVk3(WPARAM wParam1) {
	/* Нажимается клавиша со скан-кодом. */
	INPUT inin;

	inin.type = INPUT_KEYBOARD;
	inin.ki.time = 0;
	inin.ki.wScan = scanCodeB;
	inin.ki.dwExtraInfo = 777;
	inin.ki.dwFlags = 0;

	if (wParam1 == WM_KEYUP) {
		inin.ki.dwFlags = KEYEVENTF_KEYUP;
	};

	inin.ki.wVk = vkCodeB;
	SendInput(1,&inin,sizeof(INPUT));
}

DWORD WINAPI tickThreadProcVk4(WPARAM wParam1) {
	/* Нажимается клавиша со скан-кодом. */
	INPUT inin;

	inin.type = INPUT_KEYBOARD;
	inin.ki.time = 0;
	inin.ki.wScan = scanCodeB7;
	inin.ki.dwExtraInfo = 777;
	inin.ki.dwFlags = 0;

	if (wParam1 == WM_KEYUP) {
		inin.ki.dwFlags = KEYEVENTF_KEYUP;
	};

	inin.ki.wVk = vkCodeB7;
	SendInput(1,&inin,sizeof(INPUT));
}

void pressedB(bool *pb, int scanCode1) {
	/* Определяет зажата или отпущена ли клавиша 1, и изменяет в соответствии с этим особые переменные. */
	keyUp = (wParam1 == WM_KEYUP);
	keyDown = (wParam1 == WM_KEYDOWN);

	if ((keyDown) && (scanCode == scanCode1)) {
		*pb = true;
		ButtonPressed = true;
	}

	if ((keyUp) && (scanCode == scanCode1)) {
		*pb = false;
		ButtonPressed = true;
	}
};

LRESULT __stdcall keyproc( int code, WPARAM wParam, LPARAM lParam ) {
	/* Начальные присвоения. */
	vkCode = ((KBDLLHOOKSTRUCT*) lParam)->vkCode;
	scanCode = ((KBDLLHOOKSTRUCT*) lParam)->scanCode;
	int flags = ((KBDLLHOOKSTRUCT*) lParam)->flags;
	extraInf = ((KBDLLHOOKSTRUCT*) lParam)->dwExtraInfo;
	ButtonPressed = false;
	wParam1 = wParam;

	/* ------------------------------------------------------------------------- */

	/* Замена одних клавиш на другие. */
	if (extraInf != 777) {
		/* 	 ScanOrig	VkNew	ScanNew */ 
		touchIf( 58,	 	8,	14 ); /* Caps = BackSpace */
		touchIf( 86,	 	134,	110 ); /* L\| = Mod */
		
		/* RAlt = LCtrl */
		if (vkCode == 165) {  
			touchIf( 56,	 	162,	29 );
		}
		
		/* RMenu = LAlt */
		if (scanCode == 93) {
			if (((flags >> 7) % 2) == 1) {
				wParam = WM_KEYUP;
			}
			touchIf( 93,	 	164,	56 ); 
		}
		
		
		/* RShift = Shift + . (, в Русском) */
		if (scanCode == 42) {
			touchIf( 42,	 	160,	42 );
			Sleep(5);
			touchIf( 42,	 	191,	53 );
		}
		
		/* LCtrl = смена языка */ 
		if ((vkCode == 162) && (scanCode == 29) && (wParam == WM_KEYDOWN)) {
			PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 2, 0);
			ButtonPressed = true;
		}
		
		/* LAlt = LShift */
		if ((vkCode == 164) && (scanCode == 56)) {
			/* Отпускаем клавишу альт, чтобы она нам не мешалась. */
			if (AltPressed == false) {
				scanCodeB7 = 56; vkCodeB7 = 164;
				hTickThread = CreateThread( NULL, 0, &tickThreadProcVk4, WM_KEYUP, 0, NULL );
				/* И нам ее нужно отпускать только один раз, поэтому ставим флаг. */
				AltPressed = true;
				AltTime = GetTickCount();
			}
			
			/* Если клавиша отпускается, то при следущем нажатии нам нужно будет отпустить альт, поэтому убираем флаг. */
			if ((wParam == WM_KEYUP) || ((AltTime - GetTickCount()) < 200)) {
				AltPressed = false;
			}
			
			/* Нажимаем шифт после всех действий. */
			touchIf( 56,	 	160,	42 ); 
		}
	};
	
	/* ------------------------------------------------------------------------- */
	
	/* Получаем информацию о том, нажата ли клавиша Мод. */
	pressedB(&modDown, 110);
        
	/* Заменяем комбинации клавиш на нажатие другой клавиши. */
	/* ------------------------------------------------------------------------- */
	
	if (modDown) {
		/* Mod + KEYS: */
		touchIf(36, 37, 75); /* Mad + J = Left */
		touchIf(37, 38, 72); /* Mod + K = Up */
		touchIf(38, 40, 80); /* Mod + L = Down */
		touchIf(39, 39, 77); /* Mod + : = Right */
        	
		touchIf(22, 36, 71); /* Mod + U = Home */
		touchIf(23, 35, 79); /* Mod + I = End */
		touchIf(24, 33, 73); /* Mod + O = Pg Up */
		touchIf(25, 34, 81); /* Mod + P = Pg Down */
        	
		touchIf(51, 46, 83); /* Mod + < = Del */
		
		touchIf(34, 13, 28); /* Mod + G = Enter */
	}
	
	/* ------------------------------------------------------------------------- */
        
	/* Выключение программы по Mod + Esc. */
	if (modDown && (scanCode == 1)) {
		PostQuitMessage( 0 );
		
		UnhookWindowsHookEx(hhook);
		
		ButtonPressed = true;
	}
	
	/* ------------------------------------------------------------------------- */
	
	/* Если это нажатие нам не надо заменить, то оно посылется, иначе нет. */
	if (ButtonPressed) {} else {
		return CallNextHookEx( hhook, code, wParam, lParam );
	};
};

//% ----------------------------------------------------------------------- %//

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	/* Создание хука и вывод сообщения если он не может быть создан. */
	hhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyproc, NULL, 0);
	if (NULL == hhook) {
	    MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
	
	/* Основной цикл работы программы. */
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
	    TranslateMessage(&msg);
	    DispatchMessage(&msg);
	}
}