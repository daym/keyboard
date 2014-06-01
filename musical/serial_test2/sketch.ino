#include <Arduino.h>
#include <avr/io.h>
//#include <Keypad.h>

const byte COLS = 6;

//static uint bitmap[ROWS*COLS];

#define COLS 6
static uint8_t columnPins[COLS] = {_BV(1), _BV(2), _BV(3), _BV(4), _BV(0), _BV(5)}; /* PORTC */

static uint16_t keystate[COLS] = {0};

/* PORTC is the octave selector, and driver.
   PD0 and PD1 are free.
   PIND, PINB are the (half)tone selectors, 12 of them, pins 2,3,4,5,6,7,8,9,10,11,12,13. */
static void Keyboard_Scan(void) {
	for(uint8_t c = 0; c < COLS; ++c) {
		uint16_t prevstate, newstate;
		DDRC |= columnPins[c]; /* set octave output */
		/* breaks; am not allowed to do that! */
		PORTC &=~ columnPins[c]; /* pulse column */ /* FIXME */
		prevstate = keystate[c];
		newstate = ((uint16_t) PIND | ((uint16_t) PINB << 8)) >> 2;
		Serial.print(prevstate);
		Serial.write('/');
		Serial.print(newstate);
		Serial.write(' ');
		if(prevstate != newstate) { /* send MIDI event */
			uint8_t note;
			uint16_t changes = newstate ^ prevstate;
			for(note = 0; note < 12; ++note) {
				if((changes & (1 << note)) != 0) {
					Serial.write('n');
					Serial.print(note);
					Serial.println((newstate & _BV(note)) == 0 ? "on" : "off");
				}
			}
			keystate[c] = newstate;
		}
		/* TODO debounce? */
		PORTC |= columnPins[c]; /* end pulse */
		DDRC &=~ columnPins[c]; /* end pulse */ /* breaks it */
	}
}
static void Keyboard_Init(void) {
	DDRB = 0; /* set input */
	DDRD &= 3; /* set input */ /* don't touch RX/TX */
	PORTB = 0xFF; /* activate pull-ups */
	PORTD |= 0xFF &~ 3; /* activate pull-ups */ /* don't touch RX/TX */
	DDRC = 0; /* input for now */
	PORTC = 0xFF; /* pullup for now */
	uint8_t c;
	for(c = 0; c < COLS; ++c)
		keystate[c] = 0xFF;
}

void setup(){
  Serial.begin(9600);
  Keyboard_Init();
}

void loop(){
  Keyboard_Scan();
  Serial.write('\r');
  Serial.flush();
  delay(100);
}

