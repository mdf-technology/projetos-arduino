/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <IRremote.h>
#define emissorIR 3

IRsend irsend;

void setup() {
  Serial.begin(9600);
  pinMode(emissorIR, OUTPUT);
}

void loop() {
  switch(Serial.read()){
    case 'a':
      digitalWrite(emissorIR, HIGH);
      delay(500);
      digitalWrite(emissorIR, LOW);
      irsend.sendPanasonic(0x100BCBD, 48);
      Serial.println("Dados Enviados!");
      delay(40);
      break;                                
  }
  delay(5000);  //5 second delay between each signal burst
}
