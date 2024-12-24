
#include "HCMS39xx.h"
HCMS39xx myDisplay(4, 6, 7, 8, 9, 10); // display config
const int UI1 = 4;  // the number of the pushbutton pin
const int UI2 = 5;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize button pins
  pinMode(UI1, INPUT);
  pinMode(UI2, INPUT);
  myDisplay.begin();          // Initialize the display
  myDisplay.displayUnblank(); // Default configuration blanks the display, so need to unblank before using

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(UI1);
  const float num1 = 100;
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    myDisplay.begin();
    myDisplay.displayUnblank(); 
    myDisplay.print(num1);
    delay(5000);
  } else {
    // turn LED off:
    myDisplay.displaySleep();
  }
}
