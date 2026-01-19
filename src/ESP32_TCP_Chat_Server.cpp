#include <WiFi.h>
#include <WiFiManager.h>
#include <WebServer.h>
#include <LittleFS.h>

// 1️⃣ Web server object (GLOBAL declaration)
WebServer server(80);
String chatLog = "";

void setup() {
  Serial.begin(115200);

  // 2️⃣ WiFiManager
  WiFiManager wm;
  if (!wm.autoConnect("ESP32-WebChat")) {
    ESP.restart();
  }

  Serial.println("WiFi Connected");
  Serial.println(WiFi.localIP());

  // 3️⃣ LittleFS mount
  if (!LittleFS.begin()) {
    Serial.println("LittleFS Mount Failed");
    return;
  }

  // 4️⃣ Serve static files (IMPORTANT)
  server.serveStatic("/", LittleFS, "/index.html");
  server.serveStatic("/style.css", LittleFS, "/style.css");
  server.serveStatic("/script.js", LittleFS, "/script.js");

  // 5️⃣ Chat API
  server.on("/send", []() {
    if (server.hasArg("msg")) {
      chatLog += server.arg("msg") + "<br>";
      Serial.println(server.arg("msg"));
    }
    server.send(200, "text/plain", "OK");
  });

  server.on("/read", []() {
    server.send(200, "text/html", chatLog);
  });

  // 6️⃣ Start server
  server.begin();
  Serial.println("Web Chat Server Started");
}

void loop() {
  server.handleClient();
}
