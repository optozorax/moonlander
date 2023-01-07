# Раскладка Ильи Шепрута

Про эту раскладку я написал большую статью, которую можно прочитать по ссылке ниже.

# [Читать статью](https://optozorax.github.io/p/my-keyboard-layout/)

# Как прошить

Если вы попробуете скачать исходный код вашей раскладки, сделанной на Oryx, то она будет работать только с [форком QMK от ZSA](https://github.com/zsa/qmk_firmware) и на ветке [firmware20](https://github.com/zsa/qmk_firmware/tree/firmware20). Конечно, можно использовать обычный QMK, но там вроде чего-то не хватает. Поэтому первым делом надо скачать этот форк (команды ниже не работают для винды).

```bash
git clone https://github.com/zsa/qmk_firmware zsa_qmk
cd zsa_qmk
./util/qmk_install.sh
git submodule init
git submodule update
```

Затем нужно создать символьную ссылку на папку с вашей раскладкой. Делать именно символьную ссылку нужно, чтобы не хранить свою раскладку где-то в дебрях этого форка QMK:

```bash
ln -s /home/optozorax/my/moonlander ~/zsa_qmk/keyboards/moonlander/keymaps/optozorax
```

Чтобы прошить, нужно внутри этого форка вызвать такую команду:
```bash
make moonlander:optozorax:flash
```

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
