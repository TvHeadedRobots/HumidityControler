#include <dht.h>

dht DHT;

#define DHT11_PIN 10
int led_pin = 18;

void setup(){
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  //Check DHT11 Status
  int chk = DHT.read11(DHT11_PIN);
  
  if(chk != 0) {
    Serial.println(chk);
  }
 
  if (DHT.humidity >= 80){
    digitalWrite(led_pin, LOW);
    Serial.print("GT50 Humidity = ");
    Serial.println(DHT.humidity);
  }
  else {
    digitalWrite(led_pin, HIGH);
    Serial.print("LT50 Humidity = ");
    Serial.println(DHT.humidity);
  }
  
  delay(5000);
}
