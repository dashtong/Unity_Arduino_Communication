
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define BTN 5

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

bool btnState = false;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  //  Serial.println(radio.isChipConnected());
}

void loop() {
  if (Serial.available()) {
    byte tmp = Serial.read();
    btnState = false;
    if (tmp == '1') {
      btnState = true;
      radio.write(&btnState, sizeof(btnState));
    }
  }
  else {
    radio.write(&btnState, sizeof(btnState));
  }
//  delay(100);
}
