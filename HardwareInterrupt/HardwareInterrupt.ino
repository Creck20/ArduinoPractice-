// Fundamentals of ISRs and Hardware Interrupts

// LED and switch connections
const byte ledPin = 13; 
const byte buttonPin = 2;

volatile bool toggleState = false; 

void checkSwitch(){
    //Check status of the switch 
    // Toggle LED if button is pressed

    // digitalRead() returns HIGH or LOW depending on what value is found at a PIN
    // HIGH and LOW are preprocessor directives for 0x01 and 0x00
    if (digitalRead(buttonPin) == LOW){
      toggleState = !toggleState;

      // digitalWrite() accepts HIGH and LOW or 1 and 0
      // Booleans convert to ints with true = 1, false = 0
      digitalWrite(ledPin, toggleState); 
    }
}

void setup() {
 // Set pinModes
 pinMode(ledPin, OUTPUT);
 pinMode(buttonPin, INPUT_PULLUP);

 Serial.begin(9600);

 attachInterrupt(digitalPinToInterrupt(buttonPin), checkSwitch, FALLING);
}

void loop() {

  // Five second time delay to show that the ISR takes priority over this loops execution
  Serial.println("Delay Started");
  delay(5000);
  Serial.println("Delay Finished");
  Serial.println("..............");
}
