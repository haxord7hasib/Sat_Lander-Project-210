#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// CE and CSN pin assignments
RF24 radio(9, 10); // Change these pins if needed

// Address for the communication channel
const byte address[6] = "00001";

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();
}

void loop() {
    if (radio.available()) {
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.print("Received message: ");
        Serial.println(text);
    }
}
