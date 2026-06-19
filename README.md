# Раскладка Ильи Шепрута

Про эту раскладку я написал большую статью, которую можно прочитать по ссылке ниже.

# [Читать статью](https://optozorax.github.io/p/my-keyboard-layout/)

# Как прошить

Если вы попробуете скачать исходный код вашей раскладки, сделанной на Oryx, то она будет работать только с [форком QMK от ZSA](https://github.com/zsa/qmk_firmware) и на ветке [firmware20](https://github.com/zsa/qmk_firmware/tree/firmware20). Конечно, можно использовать обычный QMK, но там вроде чего-то не хватает. 

Вот подробная установка:

```bash
git submodule init
git submodule update
mkdir _deps
cd _deps
git clone https://github.com/zsa/qmk_firmware zsa_qmk
cd zsa_qmk
git checkout firmware20
git submodule init
git submodule update
./util/qmk_install.sh
mkdir keyboards/moonlander/keymaps/optozorax
```

Далее запускаем эту команду для того чтобы скопировать раскладку в папку `zsa_qmk`. И запускайте её каждый раз когда обновляете код:

```bash
./../../update.sh
```

Затем надо применить патч для `arbitrary_keycode`, потому что он требует небольших изменений в QMK:

```bash
git apply ../../qmk.patch
```

Для компиляции запускайте
```bash
make moonlander:optozorax
```

Для прошивки запускайте эту команду:
```bash
make moonlander:optozorax:flash
```

Делать всё это либо на Linux, либо на WSL если вы на винде. На винде не запускайте команду прошивки, а лучше скачайте приложение от ZSA и прошивайте им: https://www.zsa.io/flash

Компиляция на винде через mingw не работает.

# Установка софтварных штук

## Linux

TODO

## MacOS

Для работы юникодного слоя:
1. Скопировать файл `MacXCompose.dict` в `~/Library/KeyBindings/DefaultKeyBinding.dict`.
1. Перезагрузить компьютер.

Для работы переключения между окнами:
1. Установить [Karabiner-Elements](https://karabiner-elements.pqrs.org/), настроить его.
1. Установить [goku](https://github.com/yqrashawn/GokuRakuJoudo): `brew install yqrashawn/goku/goku`.
1. Скопировать файл `karabiner.edn` в `~/.config/karabiner.edn`.
1. Выполнить команду `goku`. Должно вывестись `Done!`.
1. Изменения автоматически подтянутся без перезагрузки и прочих действий.

## Рисование раскладки

Советую рисовать раскладку в [kle.klava.org](https://kle.klava.org/#/gists/9a4b993ea6bff1ff0f9b7a33bc755623).

Чтобы выглядело красиво, надо установить расширение Stylish и добавить стили на этот сайт как говорится [тут](https://gist.github.com/optozorax/d2fc1b63f9ba09ab9b4adbd320424500).
