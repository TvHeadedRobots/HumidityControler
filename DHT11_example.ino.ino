#include <dht.h>

dht DHT;

#define DHT11_PIN 10
int led_pin = 18;
int pot_pin = 21;
int potVal = 0;
int humiditySet = 0;
int loopCntr = 0;

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
  
  potVal = analogRead(pot_pin);
  humiditySet = map(potVal, 0,255, 10,90);
  Serial.print("Pot Val = ");
  Serial.println(potVal);
  Serial.print("Map Pot Val = ");
  Serial.println(humiditySet);
  
  if(loopCntr = 0) {
    loopCntr = 1;
  }
  if(loopCntr = 100) {
    chkHumidity(humiditySet); //need to pass analogRead() val
  }
  else {
    loopCntr++;
  }
  
  delay(50);
}

//Humidity check function
void chkHumidity(int h)
{
  if (DHT.humidity >= h){
    digitalWrite(led_pin, LOW);
    Serial.print("Set val = ");
    Serial.println(h);
    Serial.print("GT50 Humidity = ");
    Serial.println(DHT.humidity);
  }
  else {
    digitalWrite(led_pin, HIGH);
    Serial.print("Set val = ");
    Serial.println(h);
    Serial.print("LT50 Humidity = ");
    Serial.println(DHT.humidity);
  }
}
