#include <Arduino.h>
#include <directdownload.h>

String getwifiSSID() {
  return "test";
}
String getwifiPassword() {
  return "test";
}

void setup() {

  Serial.begin(115200);
  Serial.println(F("Startup!"));

  downloadUpdate(getwifiSSID(), getwifiPassword());

}

void loop() {delay(1000);}