#include <WiFi.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>
// ตั้งค่า WiFi
const char* ssid = "0527S24ultra";          // ใส่ชื่อ WiFi ของคุณ
const char* password = "PICHAPOnG27";  // ใส่รหัสผ่าน WiFi ของคุณ

// ตั้งค่า OpenWeather API
String apiKey = "d90a350f03e0e6561e0874ccaeb44b6f";          // ใส่ API Key ของ OpenWeather
String city = "Bangkok,TH";                 // ใส่ชื่อเมืองที่ต้องการดูสภาพอากาศ
String server = "api.openweathermap.org";
String units = "metric";                 // ใช้ metric units สำหรับการแสดงอุณหภูมิเป็นองศาเซลเซียส

WiFiClient client;
String jsonBuffer;

void setup() {
  Serial.begin(115200);

  // เชื่อมต่อ WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // เรียกข้อมูลสภาพอากาศ
  getWeatherData();
}

void loop() {
  // สามารถเรียก getWeatherData() ซ้ำใน loop() หากต้องการอัปเดตข้อมูลต่อเนื่อง
  delay(60000); // รอ 1 นาที ก่อนเรียกข้อมูลใหม่
}

void getWeatherData() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connecting to server...");
    
    if (client.connect(server.c_str(), 80)) {  // เชื่อมต่อกับ OpenWeather API ที่พอร์ต 80 (HTTP)
      Serial.println("Connected to server!");

      // สร้างคำขอ GET ไปยัง OpenWeather
      String url = "/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=" + units;
      Serial.print("Requesting URL: ");
      Serial.println(url);

      client.println("GET " + url + " HTTP/1.1");
      client.println("Host: " + String(server));
      client.println("Connection: close");
      client.println();  // สิ้นสุดคำขอ HTTP

      // รอรับการตอบกลับ
     String payload = "";
      while (client.connected() || client.available()) {
        if (client.available()) {
          String line = client.readStringUntil('\n');
          if (line == "\r") {
            break;  // ส่วน header ของ HTTP สิ้นสุดแล้ว
          }
        }
      }

      // อ่านส่วน body ของการตอบกลับ (ข้อมูล JSON)
      while (client.available()) {
        payload += client.readString();
      }

      Serial.println("Received payload:");
      Serial.println(payload);  // แสดงข้อมูล JSON ที่ได้รับ
      JSONVar myObject = JSON.parse(payload);
  
      // JSON.typeof(jsonVar) can be used to get the type of the var
      if (JSON.typeof(myObject) == "undefined") {
        Serial.println("Parsing input failed!");
        return;
      }
    
      Serial.print("JSON object = ");
      Serial.println(myObject);
      Serial.print("Temperature: ");
      Serial.println(myObject["main"]["temp"]);
      Serial.print("Pressure: ");
      Serial.println(myObject["main"]["pressure"]);
      Serial.print("Humidity: ");
      Serial.println(myObject["main"]["humidity"]);
      Serial.print("Wind Speed: ");
      Serial.println(myObject["wind"]["speed"]);

      client.stop();  // จบการเชื่อมต่อ
    } else {
      Serial.println("Connection to server failed");
    }
  } else {
    Serial.println("WiFi not connected");
  }
}
