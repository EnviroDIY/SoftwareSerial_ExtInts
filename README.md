# SoftwaterSerial_ExtInts
A modified version of the Arduino built-in SoftwareSerial_ExtInts library which depends on an external Interrupt library to call the interrupts for it.

This will NOT work alone.  To work you must first import another interrupt library and use the functions in that library to set up the interrupts for this like so:

```cpp
#include <EnableInterrupt.h>
#include <SoftwareSerial_ExtInts.h>

// Create the software serial object
SoftwareSerial_ExtInts mySerial(RXpin, TXpin); // RX, TX

void setup() {
  // Enable interrupts for the recieve pin
  enableInterrupt(RXpin, SoftwareSerial_ExtInts::handle_interrupt, CHANGE);

  // set the data rate for the SoftwareSerial_ExtInts port
  mySerial.begin(BAUD);
}
```
