#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LED 7

DHT dht(DHTPIN, DHTTYPE);

void controller(int incomingByte) {
  if (incomingByte == 65) {
    sendTemperature();
  } else if (incomingByte == 66) {
    sendHumidity();
  } else if (incomingByte == 67) {
    digitalWrite(LED, HIGH);
  } else if (incomingByte == 68) {
    digitalWrite(LED, LOW);
  }
}

void sendTemperature() {
  float temperature = dht.readTemperature();
  Serial.print(temperature);
}

void sendHumidity() {
  float humidity = dht.readHumidity();
  Serial.print(humidity);
}
 
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int incomingByte = Serial.read();
    controller(incomingByte);
  }
}


