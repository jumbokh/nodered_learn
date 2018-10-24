#include <ESP8266WiFi.h>      // 提供Wi-Fi功能的程式庫
#include <ESP8266WebServer.h>  // 提供網站伺服器功能的程式庫

const char ssid[] = "your-ssid";
const char pass[] = "your-pass";

ESP8266WebServer server(80);   // 宣告網站伺服器物件與埠號


#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 5

// 定義處理首頁請求的自訂函式
void rootRouter() {
int chk = DHT11.read(DHT11PIN);

  //Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK: 
                Serial.print("OK,"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.println("Checksum error"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.println("Time out error"); 
                break;
    default: 
                Serial.println("Unknown error"); 
                break;
  }

  
  Serial.print((float)DHT11.humidity, 2);
  Serial.print("%,");
  Serial.print((float)DHT11.temperature, 2);
  String gy = String("")+"Temperature: "+DHT11.temperature +
                       "<BR> Humidity: " + DHT11.humidity + "% <BR><b>ESP8266 WiFi Bee Station 01</b>!<BR>";
  server.send(200, "text/html",gy);
}

void setup() {
  Serial.begin(115200);  
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  WiFi.begin(ssid, pass);
  /*
   *  若要指定IP位址，請自行在此加入WiFi.config()敘述。 */
   WiFi.config(IPAddress(192,168,43,xx),    // IP位址
               IPAddress(192,168,43,254),     // 閘道（gateway）位址
               IPAddress(255,255,255,0));  // 網路遮罩（netmask）
   /***/

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);   // 等待WiFi連線
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected, IP: ");
  Serial.println(WiFi.localIP());  // 顯示ESP8266裝置的IP位址

  server.on("/index.html", rootRouter);  // 處理首頁連結請求的事件
  server.on("/", rootRouter);
  
  server.onNotFound([](){   // 處理「找不到指定路徑」的事件
    server.send(404, "text/plain", "File NOT found!");
  });
  
  server.begin();
  Serial.println("HTTP server started.");
}

void loop() {
    server.handleClient();  // 處理用戶連線
}
