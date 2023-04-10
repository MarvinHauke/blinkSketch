#include <Arduino.h>

bool timer(const unsigned long eventInterval)
{
  static unsigned long previousTime = 0;
  unsigned long currentTime = millis();
  if (currentTime - previousTime >= eventInterval)
  {
    previousTime = currentTime;
    return true;
  }
  else
    return false;
}

void change_led()
{
  if (timer(100UL))// UL stands for "unsigned long"
  {
    int led_state = !digitalRead(13);
    digitalWrite(13, led_state);
  }
}

int main()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  while(true){
    change_led();
  }
}

