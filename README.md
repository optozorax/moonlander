# Раскладка Ильи Шепрута

Про эту раскладку я написал большую статью, которую можно прочитать по ссылке ниже.

# [Читать статью](https://optozorax.github.io/p/my-keyboard-layout/)

# Как прошить

Если вы попробуете скачать исходный код вашей раскладки, сделанной на Oryx, то она будет работать только с [форком QMK от ZSA](https://github.com/zsa/qmk_firmware) и на ветке [firmware25](https://github.com/zsa/qmk_firmware/tree/firmware25). Конечно, можно использовать обычный QMK, но там вроде чего-то не хватает.

Вот подробная установка:

```bash
git submodule init
git submodule update
mkdir _deps
cd _deps
git clone https://github.com/zsa/qmk_firmware zsa_qmk
cd zsa_qmk
git checkout firmware25
git submodule init
git submodule update
./util/qmk_install.sh
mkdir -p keyboards/zsa/moonlander/keymaps/optozorax
```

`qmk_install.sh` устанавливает системные зависимости и ARM toolchain. В WSL я
дополнительно использую локальное Python-окружение для QMK CLI, чтобы не
устанавливать Python-пакеты глобально. Оно создаётся рядом с `zsa_qmk`:

```bash
# Находясь в _deps/zsa_qmk
sudo apt install -y python3-venv
python3 -m venv ../qmk-venv
../qmk-venv/bin/python -m pip install qmk
../qmk-venv/bin/python -m pip install -r requirements.txt
```

В результате QMK CLI находится в `_deps/qmk-venv/bin/qmk`. Активировать
окружение через `source` необязательно: в командах ниже его папка временно
добавляется в `PATH`.

Далее запускаем эту команду для того чтобы скопировать раскладку в папку `zsa_qmk`. И запускайте её каждый раз когда обновляете код:

```bash
./../../update.sh
```

Затем надо применить патч. Он добавляет необходимую для
`arbitrary_keycode` поддержку и делает частоту таймера `dac_basic`
настраиваемой из `config.h`:

```bash
git apply ../../qmk.patch
```

`keymap.json` подключает модули `zsa/defaults`, `zsa/oryx` и
`zsa/navigator_trackpad`. Модуль
трекпада из `firmware25` сам включает digitizer, touchpad mode и I2C.

Для компиляции из `_deps/zsa_qmk` запускайте:

```bash
make zsa/moonlander/reva:optozorax
```

Если вы под WSL, и устанавливали зависимости через venv, то для компиляции запускайте такую команду:

```bash
PATH="$PWD/../qmk-venv/bin:$PATH" make zsa/moonlander/reva:optozorax
```

Готовый файл будет находиться в
`_deps/zsa_qmk/zsa_moonlander_reva_optozorax.bin`.

Для прошивки непосредственно из Linux запускайте:

```bash
make zsa/moonlander/reva:optozorax:flash
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
