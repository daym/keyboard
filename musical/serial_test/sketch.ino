#include <Arduino.h>
//#include <Keypad.h>

const byte ROWS = 12;
const byte COLS = 6;
/*

Gertboard
ATmega Port/Pin 	Ardino
Wiring Pin 	Notes
PB5 	13 	(LED)
PB4 	12 	
PB3 	11 	PWM
PB2 	10 	PWM
PB1 	9 	PWM
PB0 	8 	
PD7 	7 	
PD6 	6 	PWM
PD5 	5 	PWM
PD4 	4 	
PD3 	3 	PWM
PD2 	2 	
PD1 	1 	TxD
PD0 	0 	RxD
PC5 	Analog In 5 	SCL
PC4 	Analog In 4 	SDA
PC3 	Analog In 3 	
PC2 	Analog In 2 	
PC1 	Analog in 1 	
PC0 	Analog In 0
*/
byte rowPins[ROWS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; //connect to the row pinouts of the keypad. HIGH (driver)
byte columnPins[COLS] = {A1, A2, A3, A4, A0, A5}; //connect to the column pinouts of the keypad

//static uint bitmap[ROWS*COLS];
void setup(){
  Serial.begin(9600);
  for(byte r = 0; r < ROWS; r++)
    pinMode(rowPins[r],INPUT_PULLUP);
}

void loop(){
  Serial.print(millis());
  Serial.write(' ');
  for(byte c = 0; c < COLS; c++) {
    pinMode(columnPins[c],OUTPUT); /* which octave */
    digitalWrite(columnPins[c], LOW);  // Begin column pulse output.
    for(byte r = 0; r < ROWS; r++) {
      byte x = !digitalRead(rowPins[r]);
      //bitWrite(bitmap[r], c, x);  // keypress is active low so invert to high.
      Serial.write(x ? '#' : '.');
    }
    Serial.write(';');
    // Set pin to high impedance input. Effectively ends column pulse.
    digitalWrite(columnPins[c],HIGH);
    pinMode(columnPins[c],INPUT);
  }
  Serial.write('\r');
  Serial.flush();
  delay(100);
}

