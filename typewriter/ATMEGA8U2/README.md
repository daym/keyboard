mkdir /tmp/LUFA
cd /tmp/LUFA
git clone git@github.com:daym/lufa.git
cd lufa/Demos/Device/ClassDriver/Keyboard2
make
../../../../../../keyboard/tools/flash-custom-bfu Keyboard.hex

(Or search for Arduino-keyboard_115200.hex for a faster keyboard device)

Search for Arduino-usbserial-uno.hex and flash it in order to recover.
