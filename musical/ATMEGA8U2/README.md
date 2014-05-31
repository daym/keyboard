mkdir ../LUFA
cd ../LUFA
git clone git@github.com:daym/lufa.git
cd lufa/Demos/Device/ClassDriver/MIDI2/
make
cd ../../../../../../keyboard/tools/flash-custom-bfu MIDI.hex
