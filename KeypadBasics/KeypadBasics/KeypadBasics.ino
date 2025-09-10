#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the key mapping for your 4x4 keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// Define the Arduino pins connected to the keypad rows
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad

// Define the Arduino pins connected to the keypad columns
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pinouts of the keypad

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  Serial.println("4x4 Keypad Test");
}

void loop() {
  char key = keypad.getKey(); // Read the key pressed

  // If a key is pressed, print it to the serial monitor
  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}