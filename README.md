# 🌐 ESP32 Network Status Monitor

![ESP32 Network Status Monitor](images/esp32-network-monitor.png)

A simple ESP32-based network monitoring project designed to monitor Wi-Fi connection status, network configuration, signal strength, and Internet connectivity.

This project is **Project 02** in my ESP32 Networking & Cyber Security project series.

---

## 🚀 Project Overview

The ESP32 connects to a Wi-Fi network and continuously monitors important network information.

The system displays the collected information through the Arduino IDE Serial Monitor and automatically checks the network every 5 seconds.

---

## ✨ Features

- 📶 Wi-Fi Connection Status
- 📡 Connected Wi-Fi SSID
- 🌐 ESP32 IP Address
- 🚪 Gateway IP Address
- 🔢 Subnet Mask
- 💻 MAC Address
- 📊 Wi-Fi Signal Strength (RSSI)
- 🌍 Internet Connectivity Check
- 📡 Ping Test using `8.8.8.8`
- ⚠️ Wi-Fi Connection Lost Detection
- ✅ Wi-Fi Connection Restored Detection
- 🔄 Automatic Network Monitoring
- 🔁 Automatic Wi-Fi Reconnection

---

## 🛠️ Hardware Requirements

| Component | Quantity |
|---|---:|
| ESP32 DevKit | 1 |
| USB Cable | 1 |
| Computer / Laptop | 1 |
| Wi-Fi Hotspot / Router | 1 |

No external sensors are required.

---

## 💻 Software Requirements

- Arduino IDE
- ESP32 Board Package
- ESPping Library
- ping32 Library

### Libraries



🔌 Hardware Connection
The ESP32 is connected to the computer using a USB cable.
        USB
         │
         ▼
   ┌─────────────┐
   │    ESP32    │
   └──────┬──────┘
          │
          │ Wi-Fi
          ▼
   ┌─────────────┐
   │ Wi-Fi Router│
   └──────┬──────┘
          │
          ▼
      Internet
⚙️ How It Works
START
  │
  ▼
Initialize Serial
  │
  ▼
Set Wi-Fi Station Mode
  │
  ▼
Connect to Wi-Fi
  │
  ▼
Check Wi-Fi Status
  │
  ├── Disconnected
  │       │
  │       ▼
  │  Show Connection Lost
  │       │
  │       ▼
  │  Try Reconnection
  │
  └── Connected
          │
          ▼
   Read Network Information
          │
          ├── SSID
          ├── IP Address
          ├── Gateway
          ├── Subnet Mask
          ├── MAC Address
          └── RSSI
          │
          ▼
     Ping Internet
          │
          ▼
   ONLINE / OFFLINE
          │
          ▼
   Update Connection State
          │
          ▼
      Wait 5 Seconds
          │
          └──────────► Repeat

📊 Network Information
SSID
Displays the name of the Wi-Fi network to which the ESP32 is connected.
SSID : Infinix HOT 40 Pro
IP Address
Displays the local IP address assigned to the ESP32 by the router.
ESP32 IP : 10.239.161.66
Gateway
Displays the default gateway/router address.
Gateway : 10.239.161.159
Subnet Mask
Displays the subnet mask used by the network.
Subnet Mask : 255.255.255.0
MAC Address
Displays the unique MAC address of the ESP32 Wi-Fi interface.
MAC Address : XX:XX:XX:XX:XX:XX
RSSI
Displays the received Wi-Fi signal strength.
RSSI : -45 dBm
A value closer to 0 generally represents a stronger signal.

🌍 Internet Connectivity Test
The project uses a ping test to check whether an Internet destination is reachable.
Target:
8.8.8.8
Example:
Testing Internet...
Internet : ONLINE
If the target cannot be reached:
Testing Internet...
Internet : OFFLINE
If Wi-Fi itself is disconnected, the Internet test is not performed:
WiFi Status : DISCONNECTED
Internet    : NOT TESTED

⚠️ Connection Lost Detection
The system compares the current Wi-Fi state with the previous state.
Previous State : CONNECTED
Current State  : DISCONNECTED

Result:
⚠️ Wi-Fi CONNECTION LOST!
✅ Connection Restored Detection

When the ESP32 reconnects:
Previous State : DISCONNECTED
Current State  : CONNECTED
The system displays:
✅ Wi-Fi CONNECTION RESTORED!
📟 Example Serial Monitor Output
--------------------------------------------------------------------------------------------
                                  NETWORK MONITOR
--------------------------------------------------------------------------------------------

WiFi Status : CONNECTED
SSID        : Infinix HOT 40 Pro
ESP32 IP    : 10.239.161.66
Gateway     : 10.239.161.159
Subnet Mask : 255.255.255.0
MAC Address : XX:XX:XX:XX:XX:XX
RSSI        : -45 dBm

Testing Internet...
Internet    : ONLINE

Next check in 5 seconds...
🔌 Connection Lost Example
WiFi Status : DISCONNECTED
Internet    : NOT TESTED
Trying to reconnect...

⚠️ Wi-Fi CONNECTION LOST!

Next check in 5 seconds...
🔄 Connection Restored Example
WiFi Status : CONNECTED
SSID        : Infinix HOT 40 Pro
ESP32 IP    : 10.239.161.66
Gateway     : 10.239.161.159
Subnet Mask : 255.255.255.0
MAC Address : XX:XX:XX:XX:XX:XX
RSSI        : -45 dBm

Testing Internet...
Internet    : ONLINE

✅ Wi-Fi CONNECTION RESTORED!

🧠 Concepts Learned
This project helped develop practical knowledge of:
Wi-Fi Networking
ESP32 Station Mode
IP Addressing
Default Gateway
Subnet Mask
MAC Address
RSSI
Internet Connectivity
ICMP/Ping Concept
Network Monitoring
Connection State Detection
Automatic Reconnection
Basic Network Troubleshooting

🔐 Cyber Security Relevance
Network monitoring is an important foundation for cybersecurity.
Understanding:
Network addresses
Connected devices
Connectivity
Signal strength
Network state changes
helps build the foundation for more advanced security projects.
This project is part of a larger learning path toward Network Security and Intrusion Detection.

📁 Project Structure
ESP32-Network-Status-Monitor/
│
├── ESP32-Network-Status-Monitor.ino
├── README.md
├── LICENSE
│── demo/
│   └── esp32-network-monitor.mp4
└── images/
    └── esp32-network-monitor.png

🚀 Project Series

Project 01
📡 ESP32 Wi-Fi Scanner ✅
Project 02
🌐 ESP32 Network Status Monitor ← Current Project ✅
Project 03
🚨 Unauthorized Device Detector
Project 04
🍯 ESP32 Honeypot
Project 05
🛡️ ESP32 Mini IDS
Project 06
🔐 Secure IoT Gateway

👨‍💻 Author
Sasindu-Tech
Computer Networking & Cyber Security Enthusiast

Areas of Interest
🌐 Computer Networking
🛡️ Cyber Security
📡 IoT
🤖 Embedded Systems
💻 ESP32
🔧 Arduino

GitHub:
https://github.com/Sasidu-Tech⁠

📄 License
This project is licensed under the MIT License.
You are free to use, modify, and distribute this project, provided that the original copyright and license notice are retained.
See the LICENSE file for the full license text.

⭐ Support
If you found this project useful, consider giving the repository a ⭐ Star.
Thanks for checking out the project! 🚀
#include <ESPping.h>
#include <ping32.h>
#include <WiFi.h>
