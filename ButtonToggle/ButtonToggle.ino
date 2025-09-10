// A simple Code to setup an LED toggle on arduino.
// The LED is connected to pin 13.
// A push button is connected to pin 2 and ground. `

// As a reminder, this is an example of Polling.
// The system is continously checking if the event has been triggered.
// This takes the processor away from the rest of its capabilities and 
// is the least efficient form of checking for a trigger.

// Remember that in arduino, the setup() function runs once at the start of the code 
// execution and the loop() function runs continously.

// Based on this video: https://www.youtube.com/watch?v=wIcC8-g9Lnw

// LED and switch connections
const byte ledPin = 13; 
const byte buttonPin = 2;

// A bool to indicate the state of the toggle
// Volatile tells the compiler that the the variable is not constant and can be changed by external events.
volatile bool toggleState = false; 

void checkSwitch(){
    //Check status of the switch 
    // Toggle LED if button is pressed

    // digitalRead() returns HIGH or LOW depending on what value is found at a PIN
    // HIGH and LOW are preprocessor directives for 0x01 and 0x00
    if (digitalRead(buttonPin) == LOW){
      // Switch was pressed
      // Slight delay to debounce
      delay(200);

      // Change state of toggle
      toggleState = !toggleState;

      // digitalWrite() accepts HIGH and LOW or 1 and 0
      // Booleans convert to ints with true = 1, false = 0
      digitalWrite(ledPin, toggleState); 
    }
}

void setup() {
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);

  // Set switch pin as INPUT with pullup
  // Remember that pullup resistors are needed for active low states to 
  // keep the base value at a high voltage so the system can change if 
  // the button connects the voltage to ground. 
  pinMode(buttonPin, INPUT_PULLUP);

  // Set up serial monitor with 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  checkSwitch();

  // Add a 5 second time delay
  Serial.println("Delay Started");
  delay(5000);
  Serial.println("Delay Finished");
  Serial.println("..............");
}
