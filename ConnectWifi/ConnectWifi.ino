#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "fire-alarm-system-c4407-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH ""
#define WIFI_SSID "HSU_Students"
#define WIFI_PASSWORD "dhhs12cnvch"

char c;
void setup() {
  Serial.begin(115200);
  while(!Serial) continue;
     WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  String str = "";
  while (Serial.available()) {
    c = Serial.read();
    str += c;
    delay(5);
    
  }
  
  if ( str != "")
  {
    str.remove(6);
    Firebase.setString("StatusFire",str);
  }
  delay(500);
 }
