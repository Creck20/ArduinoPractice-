#include <Keypad.h>
#include <IRremote.h>

// Keyboard MACROS
#define SELECT '5'
#define UP '2'
#define DOWN '8'
#define LEFT '4'
#define RIGHT '6'
#define VOLUME_UP 'A'
#define VOLUME_DOWN 'B'
#define POWER '0'
#define HOME '*'
#define BACK '#'
#define INPUT 'D'

// LG Code Macros:
#define SELECT_CODE      0x44000000
#define UP_CODE          0x40000000
#define DOWN_CODE        0x41000000
#define LEFT_CODE        0x07000000
#define RIGHT_CODE       0x06000000   
#define VOLUME_UP_CODE   0x02000000
#define VOLUME_DOWN_CODE 0x03000000
#define POWER_CODE       0x08000000
#define HOME_CODE        0x7C000000
#define BACK_CODE        0x28000000
#define INPUT_CODE       0x0B000000

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Define the key mapping for your 4x4 keypad
char keys[ROWS][COLS] = {
  {'1', UP, '3', VOLUME_UP},
  {LEFT, SELECT, RIGHT, VOLUME_DOWN},
  {'7', DOWN, '9', 'C'},
  {HOME, POWER, BACK, INPUT}
};

// Define the Arduino pins connected to the keypad rows
byte rowPins[ROWS] = {2, 3, 4, 5}; // Connect to the row pinouts of the keypad

// Define the Arduino pins connected to the keypad columns
byte colPins[COLS] = {6, 7, 8, 9}; // Connect to the column pinouts of the keypad

// Create a Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// IRsend object
IRsend irsend(10);

// Debug Print Model
void printKey(char keyPress) {
  Serial.print("Key Pressed: ");
  switch(keyPress) {
    case '1':                         // Row One
      Serial.println("1"); 
      break;
    case UP:
      Serial.println("up");
      break;
    case '3':
      Serial.println("3");
      break;
    case VOLUME_UP:
      Serial.println("volume_up");
      break;
    case LEFT:                      // Row Two
      Serial.println("left");
      break;
    case SELECT:
      Serial.println("select");
      break;
    case RIGHT:
      Serial.println("right");
      break;
    case VOLUME_DOWN:
      Serial.println("volume_down");
      break;
    case '7':                      // Row Three
      Serial.println("7");
      break;
    case DOWN:
      Serial.println("down");
      break;
    case '9':
      Serial.println("9");
      break;
    case 'C':
      Serial.println("C");
      break;
    case HOME:                      // Row Four
      Serial.println("home");
      break;
    case POWER:
      Serial.println("power");
      break;
    case BACK:
      Serial.println("back");
      break;
    case INPUT:
      Serial.println("input");
      break;
  }
}

void sendKey(char keyPress, IRsend irsend) {
  Serial.print("Sending Key: ");
  switch(keyPress) {
    case '1':                         // Row One
      Serial.println("No Value"); 
      break;
    case UP:
      Serial.println(UP_CODE, HEX);
      irsend.sendNEC(UP_CODE, 32);
      break;
    case '3':
      Serial.println("No Value");
      break;
    case VOLUME_UP:
      Serial.println(VOLUME_UP_CODE, HEX);
      irsend.sendNEC(VOLUME_UP_CODE, 32);
      break;
    case LEFT:                      // Row Two
      Serial.println(LEFT_CODE, HEX);
      irsend.sendNEC(LEFT_CODE, 32);
      break;
    case SELECT:
      Serial.println(SELECT_CODE, HEX);
      irsend.sendNEC(SELECT_CODE, 32);
      break;
    case RIGHT:
      Serial.println(RIGHT_CODE, HEX);
      irsend.sendNEC(RIGHT_CODE, 32);
      break;
    case VOLUME_DOWN:
      Serial.println(VOLUME_DOWN_CODE, HEX);
      irsend.sendNEC(VOLUME_DOWN_CODE, 32);
      break;
    case '7':                      // Row Three
      Serial.println("No Value");
      break;
    case DOWN:
      Serial.println(DOWN_CODE, HEX);
      irsend.sendNEC(DOWN_CODE, 32);
      break;
    case '9':
      Serial.println("No Value");
      break;
    case 'C':
      Serial.println("No Value");
      break;
    case HOME:                      // Row Four
      Serial.println(HOME_CODE, HEX);
      irsend.sendNEC(HOME_CODE, 32);
      break;
    case POWER:
      Serial.println(POWER_CODE, HEX);
      irsend.sendNEC(POWER_CODE, 32);
      break;
    case BACK:
      Serial.println(BACK_CODE, HEX);
      irsend.sendNEC(BACK_CODE, 32);
      break;
    case INPUT:
      Serial.println(INPUT_CODE, HEX);
      irsend.sendNEC(INPUT_CODE, 32);
      break;
  }
}

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  Serial.println("LG TV Remote Test");
}

void loop() {
  char key = keypad.getKey(); // Read the key pressed

  if(key) {
    printKey(key); // Print key pressed
    sendKey(key, irsend); // Send KeyCode 
    Serial.print("\n");
  }
}