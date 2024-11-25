#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <EEPROM.h>
#include <DebounceEvent.h>
#include <EEPROMWearLevel.h>
#define BUTTON_PIN 5
#define LED 13

SoftwareSerial mySoftwareSerial(4, 3); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
// See https://github.com/PRosenb/EEPROMWearLevel
#define EEPROM_LAYOUT_VERSION 0
#define AMOUNT_OF_INDEXES 2
#define INDEX_CONFIGURATION_VAR1 0



bool isPlaying = false;
int currentFile = 1;


void saveState() {
  EEPROMwl.put(INDEX_CONFIGURATION_VAR1, currentFile);
  Serial.print(F("Saved current file: "));
  Serial.println(currentFile);
}

// Callback function for the button
void buttonCallback(uint8_t pin, uint8_t event, uint8_t count, uint16_t length) {
  Serial.print("Event : "); Serial.print(event);
  Serial.print(" Count : "); Serial.print(count);
  Serial.print(" Length: "); Serial.print(length);
  Serial.println();
  if (length > 20000 ) {          //Restart audiooks
      Serial.print("CurrentFile was: "); Serial.print(currentFile);
      currentFile = 1;
      Serial.print(" New value : "); Serial.print(currentFile);
      Serial.println();
      myDFPlayer.pause();
      myDFPlayer.play(currentFile);
      saveState();
  }
  else {
    if (length > 5000 ) {       //Next file

        currentFile = currentFile + 1; // Move to the next file
        saveState();

        myDFPlayer.playLargeFolder(1,currentFile);
        Serial.print(" New currentFile : "); Serial.print(currentFile);
        Serial.println();
    }
    else{
      if (length > 200 ) { // Button press detected pause or play
        if (isPlaying) {
          myDFPlayer.pause();
          isPlaying = false;
          digitalWrite(LED, LOW);
        } else {
          myDFPlayer.start();
          isPlaying = true;
          digitalWrite(LED, HIGH);
        }
      }
    }
  }
}

// Initialize the DebounceEvent instance
DebounceEvent button(BUTTON_PIN, buttonCallback, BUTTON_PUSHBUTTON | BUTTON_DEFAULT_HIGH | BUTTON_SET_PULLUP);



void loadState() {
  EEPROMwl.get(INDEX_CONFIGURATION_VAR1, currentFile);
  if (currentFile < 1 || currentFile > 9999 ) {
    currentFile = 1; // Default to the first file if the EEPROM value is invalid.
  }
  Serial.print(F("Loaded current file: "));
  Serial.println(currentFile);
}

void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  EEPROMwl.begin(EEPROM_LAYOUT_VERSION, AMOUNT_OF_INDEXES);   
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30); // Set volume value. From 0 to 30

  loadState();
  myDFPlayer.playLargeFolder(1,currentFile); // Start playing the saved file
  isPlaying = true;
}

void loop() {
  button.loop();

  if (myDFPlayer.available()) {
    uint8_t type = myDFPlayer.readType();
    int value = myDFPlayer.read();
    if (type == DFPlayerPlayFinished) {
      Serial.print(F("Finished playing file: "));
      Serial.println(value);
      currentFile = value + 1; // Move to the next file
      saveState();
      myDFPlayer.playLargeFolder(1,currentFile);
    }
  }
}
