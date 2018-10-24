#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi parameters
const char* ssid = "xxxxxx";
const char* password = "xxxxxxxxxx";

// Create an instance of the server
//WiFiServer server(80);
ESP8266WebServer server(80);

void handleRootPath() {
   server.send(200,"text/plain", "Hello world");
}

void setup() {
  // Start Serial
  Serial.begin(115200);
  delay(10);
  pinMode(device1pin, OUTPUT);
  digitalWrite(device1pin, 0);
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
   WiFi.config(IPAddress(192,168,43,xx),    // IP位址
               IPAddress(192,168,43,254),     // 閘道（gateway）位址
               IPAddress(255,255,255,0));  // 網路遮罩（netmask）
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.on("/other", []() {   //Define the handling function for the path
    server.send(200, "text / plain", "Other URL");
  });
  server.on("/", handleRootPath);
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());

}

void loop() {
 
 server.handleClient();
}

//- See more at: http://www.esp8266.com/viewtopic.php?f=32&t=10996#sthash.vQ5gHPBF.dpuf