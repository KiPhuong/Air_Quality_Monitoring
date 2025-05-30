#include "DHT.h"
#define DHTPIN 2     // Chân DATA
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Testing DHT11...");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: "); Serial.print(h);
    Serial.print(" %\tTemperature: "); Serial.print(t);
    Serial.println(" *C");
  }
  delay(2000);
}
