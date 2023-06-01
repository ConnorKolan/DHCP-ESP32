#include <WiFi.h>
#include <WiFiUDP.h>

const char* ssid = "FRITZ!Box 7590 NK";
const char* password = "AssB!bERl!n($)";
const int udpPort = 67;       //dhcp port
const int outPin = 13;

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pinMode(outPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  udp.begin(udpPort);
  Serial.println("UDP port opened");
}

void loop() {
  int packetSize = udp.parsePacket();
  if (packetSize) {
    char buffer[255];
    int i = 0
    int len = udp.read(buffer, sizeof(buffer) - 1);
    if (len > 0) {
      
      buffer[len] = '\0';
      Serial.print("Received packet: ");
      Serial.println(buffer);
      digitalWrite(outPin, HIGH);
      delay(200);
      digitalWrite(outPin, LOW);
      i++;
    }
  }
  delay(10);
}