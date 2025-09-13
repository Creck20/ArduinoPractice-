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

// NEC commands are send with a 2 byte address and 2 byte command
// LG Command MACROS:
#define SELECT_CODE      0x22DD
#define UP_CODE          0x02FD
#define DOWN_CODE        0x827D
#define LEFT_CODE        0xE01F
#define RIGHT_CODE       0x609F
#define VOLUME_UP_CODE   0x40BF
#define VOLUME_DOWN_CODE 0xC03F
#define POWER_CODE       0x10EF
#define HOME_CODE        0xA25D
#define BACK_CODE        0x14EB
#define INPUT_CODE       0xD02F

// Address Macro
#define NEC_ADDRESS 0x20DF

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

// Sends commands
// IrSender.sendNEC(address, command, number of repeats)
void sendKey(char keyPress) {
  Serial.print("Sending Key: ");
  switch(keyPress) {
    case '1':                         // Row One
      Serial.println("No Value"); 
      break;
    case UP:
      Serial.println(UP_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, UP_CODE, 0);
      break;
    case '3':
      Serial.println("No Value");
      break;
    case VOLUME_UP:
      Serial.println(VOLUME_UP_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, VOLUME_UP_CODE, 0);
      break;
    case LEFT:                      // Row Two
      Serial.println(LEFT_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, LEFT_CODE, 0);
      break;
    case SELECT:
      Serial.println(SELECT_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, SELECT_CODE, 0);
      break;
    case RIGHT:
      Serial.println(RIGHT_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, RIGHT_CODE, 0);
      break;
    case VOLUME_DOWN:
      Serial.println(VOLUME_DOWN_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, VOLUME_DOWN_CODE, 0);
      break;
    case '7':                      // Row Three
      Serial.println("No Value");
      break;
    case DOWN:
      Serial.println(DOWN_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, DOWN_CODE, 0);
      break;
    case '9':
      Serial.println("No Value");
      break;
    case 'C':
      Serial.println("No Value");
      break;
    case HOME:                      // Row Four
      Serial.println(HOME_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, HOME_CODE, 0);
      break;
    case POWER:
      Serial.println(POWER_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, POWER_CODE, 0);
      break;
    case BACK:
      Serial.println(BACK_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, BACK_CODE, 0);
      break;
    case INPUT:
      Serial.println(INPUT_CODE, HEX);
      IrSender.sendNEC(NEC_ADDRESS, INPUT_CODE, 0);
      break;
  }
}

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  IrSender.begin(10); // Data Line is attached to pin 10
  Serial.println("LG TV Remote Test");
}

void loop() {
  char key = keypad.getKey(); // Read the key pressed

  if(key) {
    printKey(key); // Print key pressed
    sendKey(key); // Send KeyCode 
    Serial.print("\n");
  }
}