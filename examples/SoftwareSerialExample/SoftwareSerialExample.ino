/*
  Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

 Not all pins on the Leonardo and Micro support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example

 This example code is in the public domain.

 */
#include <Arduino.h>
#include <EnableInterrupt.h>
// #include <SoftwareSerial.h>
// SoftwareSerial mySerial(11, -1); // RX, TX
#include <SoftwareSerial_ExtInts.h>
SoftwareSerial_ExtInts mySerial(11, -1); // RX, TX

// #include <NeoSWSerial.h>
// NeoSWSerial mySerial(11, -1); // RX, TX
// void interrupt_fxn()
// {
//   mySerial.rxISR(11);
// }

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Reading software serial...");

  // set the data rate for the SoftwareSerial_ExtInts port
  mySerial.begin(9600);

  // Enable interrupts for the recieve pin
  pinMode(11, INPUT_PULLUP);
  enableInterrupt(11, SoftwareSerial_ExtInts::handle_interrupt, CHANGE);
  // enableInterrupt(11, interrupt_fxn, CHANGE);

  // Power up a Maxbotic to get data from something
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
}

void loop() { // run over and over
  if (mySerial.available()) {
    Serial.println(mySerial.readStringUntil('\r'));
  }
}
