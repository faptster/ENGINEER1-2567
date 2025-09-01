#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#define LED_PIN 8 //ขาที่ต่อกับ LED
#define DHTPIN 2   //ขาที่ต่อเซนเซอร์ DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "0527S24ultra"; //อย่าลืมแก้ไข SSID ของ WIFI ที่จะให้ NodeMCU ไปเชื่อมต่อ
const char* password = "PICHAPOnG27"; //อย่าลืมแก้ไข PASSWORD ของ WIFI
const char* mqtt_server = "broker.hivemq.com"; //อย่าลืมแก้ไข BROKER
const int mqtt_port = 1883;
const char* mqtt_Client = "fa54c3d5-205c-4eaa-8695-pichapong";  //อย่าลืมแก้ไข ClientID
const char* mqtt_username = "";  //อย่าลืมแก้ไข Token
const char* mqtt_password = ""; //อย่าลืมแก้ไข Secret

WiFiClient espClient; 
PubSubClient client(espClient);

long lastMsg = 0;
int value = 0;
char msg[100];
String DataString;

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
  if (client.connect(mqtt_Client, mqtt_username, mqtt_password)) { //เชื่อมต่อกับ MQTT BROKER
    Serial.println("connected");
    client.subscribe("pichapong/led/status");
  }
  else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println("try again in 5 seconds");
    delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message;
  for (int i = 0; i < length; i++) {
    message = message + char(payload[i]);
    
  }
  Serial.println(message);
  if(String(topic) == "pichapong/led/status") {
    if (message == "ON"){
      digitalWrite(LED_PIN,HIGH);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"on\"}}");
      Serial.println("LED ON"); }
    else if (message == "OFF") {
      digitalWrite(LED_PIN,LOW);
      //client.publish("@shadow/data/update", "{\"data\" : {\"led\" : \"off\"}}");
      Serial.println("LED OFF"); }
    } 
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);
  dht.begin();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); //เชื่อมต่อกับ WIFI
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //เชื่อมต่อกับ WIFI สำเร็จ แสดง IP
  client.setServer(mqtt_server, mqtt_port); //กำหนด MQTT BROKER, PORT ที่ใช้
  client.setCallback(callback); //ตั้งค่าฟังก์ชันที่จะทำงานเมื่อมีข้อมูลเข้ามาผ่านการ Subscribe
  client.subscribe("pichapong/led/status");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  Serial.println("5555");
  long now = millis();
  if (now - lastMsg > 10000) { //จับเวลาส่งข้อมูลทุก ๆ 5 วินาที
    lastMsg = now;
    ++value;
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float ldr = map(analogRead(A5), 1023, 0, 0, 100);
    DataString = "{\"data\":{\"temperature\":" + (String)t + ",\"humidity\":" + (String)h + ",\"light\":" + (String)ldr + "}}";
    // Example of data : {"data":{"temperature":25 , "humidity": 60}}
    DataString.toCharArray(msg, 100);
    Serial.println("Hello NETPIE2020");
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("pichapong/subscribe", msg); // อย่าลืมแก้ไข TOPIC ที่จะทำการ PUBLISH ไปยัง MQTT BROKER
  }
  delay(1);
}