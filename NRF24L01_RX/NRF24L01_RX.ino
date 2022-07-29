
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define LED 4
#define SHOCK A3

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

bool buttonState = false;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_MIN); //set RF power output to minimum RF24_PA_MIN (change to RF24_PA_MAX if required)
  radio.startListening();
  //  Serial.println(radio.isChipConnected());

  pinMode(LED, OUTPUT);
  pinMode(SHOCK, OUTPUT);
  digitalWrite(LED, 0);
  analogWrite(SHOCK, 0);
}

void loop() {
  if (radio.available()) {
    radio.read(&buttonState, sizeof(buttonState));
    //    delay(100);
  }
  if (buttonState == 1) {
    analogWrite(SHOCK, 255);
  }
  else {
    analogWrite(SHOCK, 0);
  }
  digitalWrite(LED, buttonState);
}
