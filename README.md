# SoftwaterSerial_ExternalInts
A modified version of the Arduino built-in SoftwareSerial_ExternalInts library which depends on an external Interrupt library to call the interrupts for it.

This will NOT work alone.  To work you must first import another interrupt library and use the functions in that library to set up the interrupts for this like so:

```cpp
#include <EnableInterrupt.h>
#include <SoftwareSerial_ExternalInts.h>
void ssrxISR() {
   SoftwareSerial_ExternalInts::rxISR(pin);
}
enableInterrupt(pin, ssrxISR, CHANGE);
```
