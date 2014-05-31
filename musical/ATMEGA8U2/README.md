mkdir /tmp/LUFA
cd /tmp/LUFA
git clone git@github.com:daym/lufa.git
cd lufa/Demos/Device/ClassDriver/MIDI2
make
../../../../../../keyboard/tools/flash-custom-bfu MIDI.hex

Search for Arduino-usbserial-uno.hex and flash it in order to recover.

