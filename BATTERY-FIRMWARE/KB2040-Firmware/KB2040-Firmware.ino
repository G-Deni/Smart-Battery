//Display config
#include "HCMS39xx.h"
HCMS39xx myDisplay(4, 6, 7, 8, 9, 10);

//Button config
const int UI1 = 4; // The number of the pushbutton pin
const int UI2 = 5; // The number of the LED pin
int buttonState = 0; // Defines the default button state

// Define battery size
float BATT_HIGH = 5; // Fully charged state
float BATT_LOW = 2.33; // Fully discharged state

//Voltage divider config
#define ANALOG_IN_PIN A0
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;

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
    adc_value = analogRead(ANALOG_IN_PIN);// Read the Analog Input
    adc_voltage  = (adc_value * ref_voltage) / 1024.0; // Determine voltage at ADC input
    in_voltage = adc_voltage*(R1+R2)/R2; // Calculate voltage at divider input
    int precent_battery = ((((BATT_HIGH-in_voltage)-BATT_LOW)/BATT_HIGH)*100); //Defines precent_battery and calcutes value
    // turn LED on:
    myDisplay.begin();
    myDisplay.displayUnblank(); 
    myDisplay.print(precent_battery);
    myDisplay.print("%");
    delay(5000);
  } else {
    // turn LED off:
    myDisplay.displaySleep();
  }
}
