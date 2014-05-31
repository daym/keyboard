= Musical Keyboard Firmware =

I got a broken MC-68A STEREO ELECTRONIC KEYBOARD. 

So I removed the mainboard, reverse engineered the connections and replaced it by an Arduino Uno (so far).

This tree contains:
- firmware for the USB MIDI device in the ATMEGA8U2.

Keyboard Connector
==================
The keyboard is connected by two connectors:
A small connector of 6 pins and a big connector of 12 pins.

On the small connector the cable colors are, among others, as follows:
	green: lowest octave
	yellow
	orange
	...

The big connector was in parallel with most of the big front panel connector.

The small connector selects which octave is to be scanned.
The big connector selects which (half)tone in the octave is to be scanned.

Front Panel
===========
The front panel as 43 keys, among them a digit keyboard and 5 drums. It has 8 LEDs, some without(!) resistor.
The front panel was connected to the mainboard by two connectors, a 16 pin connector and a 10 pin connector.
Most of the 16 pin connector is in parallel with the big keyboard connector.
The pinouts for those connectors, seen from below the panel, with the four leds in a square to the right side of it, are:

             [777]                                                       0 1 2 3
                                                                         B B B B
    Tone Rhythm   Sync Metro BeatUp   Tempo    Dual     Midi     Voice   - 4 5 6   Sustain  Transposer   Drum1 Drum2 Drum3 Drum4 Drum5     PercuOff  Stereo
--   ^   ^         B     B     B        ^    L  B       B    L   B       B B B B     B         ^                                                     L B
                                                                         + 7 8 9         L                 B     B     B     B     B      L B         
--   v   v         B     B     B        v    L  B   B   B    L   B       B B B B     B         v                                                       B
                  Intr Start Ending            Off Sngl Fingered Style             Vibrato                                                            Demo

Small Front Panel Connector
===========================

        [          ]
         |||||||||+-- GND for a LED, with built-in resistor
         ||||||||+--- positive terminal for a lot of LEDs
         |||||||+---- positive terminal for a lot of LEDs
         ||||||+----- GND for a LED, with built-in resistor
         |||||+------ GND for a LED, with built-in resistor
         ||||+------- GND for a LED, with built-in resistor
         |||+-------- GND for a LED, without built-in resistor
         ||+--------- GND for a LED, without built-in resistor
         |+---------- GND for a LED, without built-in resistor
         +----------- GND for a LED, without built-in resistor

Big Front Panel Connector
=========================

  [                ]
   |||||||||||||||+-- 
   ||||||||||||||+--- 
   |||||||||||||+---- 
   ||||||||||||+----- 
   |||||||||||+------ 
   ||||||||||+------- 
   |||||||||+-------- 
   ||||||||+--------- 
   |||||||+---------- 
   ||||||+----------- 
   |||||+------------ 
   ||||+------------- 
   |||+-------------- unshared
   ||+--------------- unshared
   |+---------------- unshared
   +----------------- unshared; minus of diode. Plus connects to third, second and first row in the keypad.
