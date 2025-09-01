#include <WiFi.h>
#include <WiFiClient.h>

// ตั้งค่า WiFi
const char* ssid = "0527S24ultra";          // ใส่ชื่อ WiFi ของคุณ
const char* password = "PICHAPOnG27";  // ใส่รหัสผ่าน WiFi ของคุณ

// ตั้งค่า URL ที่ต้องการเรียกข้อมูล
const char* host = "192.168.67.242";        // ใส่ชื่อโดเมนหรือ IP ของเซิร์ฟเวอร์
const int httpPort = 1880;                 // พอร์ต HTTP (ส่วนใหญ่จะใช้ 80)

// ตั้งค่าเส้นทาง URL
String urlPath = "/analog";    // เส้นทางของข้อมูลที่ต้องการดึงจากเซิร์ฟเวอร์

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // เริ่มต้นการเชื่อมต่อ WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // เชื่อมต่อกับเซิร์ฟเวอร์และส่งคำขอ HTTP GET
  makeHttpRequest();
}

void loop() {
  // วนลูปซ้ำถ้าต้องการอัปเดตข้อมูล
  delay(60000);  // รอ 1 นาที ก่อนทำคำขอใหม่
  makeHttpRequest();
}

void makeHttpRequest() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connecting to server...");
    
    // เชื่อมต่อไปยังเซิร์ฟเวอร์ที่ระบุ
    if (client.connect(host, httpPort)) {
      Serial.println("Connected to server!");

      // สร้างคำขอ HTTP GET
      client.println("GET " + urlPath + " HTTP/1.1");
      client.println("Host: " + String(host));
      client.println("Connection: close");
      client.println();  // สิ้นสุดส่วน header ของคำขอ HTTP

      // อ่านการตอบกลับจากเซิร์ฟเวอร์
      while (client.connected() || client.available()) {
        if (client.available()) {
          String line = client.readStringUntil('\n');
          Serial.println(line);  // แสดงผลการตอบกลับใน Serial Monitor
        }
      }

      client.stop();  // ปิดการเชื่อมต่อกับเซิร์ฟเวอร์
    } else {
      Serial.println("Connection to server failed");
    }
  } else {
    Serial.println("WiFi not connected");
  }
}
