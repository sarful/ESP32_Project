# ESP32 Web Chat (LittleFS + WiFiManager)

A mobile-friendly ESP32 web chat hosted on-device using LittleFS and WebServer.
WiFi credentials are configured via WiFiManager captive portal.

## Features

- WiFiManager captive portal
- Serves HTML/CSS/JS from LittleFS
- Simple chat endpoints: `/send` and `/read`

## Build & Upload (PlatformIO)

1. Upload filesystem (LittleFS):
   - PlatformIO: **Upload Filesystem Image**
2. Upload firmware:
   - PlatformIO: **Upload**

## Usage

Open in browser:

- `http://<ESP32_IP>/`
