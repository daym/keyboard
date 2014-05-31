= Musical Keyboard Host Software =

Simple test programs in order to test the finished device when connected to a PC via USB.

The keyboard should show up as 

    Bus 002 Device 051: ID 03eb:2048 Atmel Corp. LUFA MIDI Demo Application

in lsusb and as 

    [547414.805508] usbcore: registered new interface driver snd-usb-audio

in dmesg.

= Usage =

make
./alsarawportlist 

Dir Device    Name
====================================
IO  hw:1,0,0  LUFA MIDI Demo MIDI 1

./alsarawmidiin

(Press some keys on the keyboard and the PC should show some messages)

See also https://ccrma.stanford.edu/~craig/articles/linuxmidi/alsa-1.0/
