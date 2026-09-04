#include <ESPping.h>
#include <ping32.h>
#include <WiFi.h>


// Wi-Fi Credentials
const char* ssid     = "Infinix HOT 40 Pro";
const char* password = "12345678";


// Previous Wi-Fi State
bool previousWiFiState = false;


void setup() {

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  // Enable automatic Wi-Fi reconnection
  WiFi.setAutoReconnect(true);

  Serial.println();

  Serial.println("--------------------------------------------------------------------------------------------");
  Serial.println("                         ESP32 NETWORK STATUS MONITOR");
  Serial.println("--------------------------------------------------------------------------------------------");

  Serial.println();

  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);


  // Wait until Wi-Fi is connected
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");
  }


  Serial.println();
  Serial.println("Wi-Fi Connected!");

  previousWiFiState = true;
}


void loop() {

  Serial.println();

  Serial.println("--------------------------------------------------------------------------------------------");
  Serial.println("                                  NETWORK MONITOR");
  Serial.println("--------------------------------------------------------------------------------------------");


  // --------------------------------------------------
  // Wi-Fi Connection Check
  // --------------------------------------------------

  bool currentWiFiStatus = (WiFi.status() == WL_CONNECTED);


  // --------------------------------------------------
  // If Wi-Fi is Connected
  // --------------------------------------------------

  if (currentWiFiStatus) {

    Serial.println();

    Serial.println("WiFi Status : CONNECTED");


    // SSID
    Serial.print("SSID        : ");
    Serial.println(WiFi.SSID());


    // ESP32 IP Address
    Serial.print("ESP32 IP    : ");
    Serial.println(WiFi.localIP());


    // Gateway
    Serial.print("Gateway     : ");
    Serial.println(WiFi.gatewayIP());


    // Subnet Mask
    Serial.print("Subnet Mask : ");
    Serial.println(WiFi.subnetMask());


    // MAC Address
    Serial.print("MAC Address : ");
    Serial.println(WiFi.macAddress());


    // RSSI
    Serial.print("RSSI        : ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");


    // --------------------------------------------------
    // Internet Ping Test
    // --------------------------------------------------

    IPAddress target(8, 8, 8, 8);

    Serial.println();

    Serial.println("Testing Internet...");


    if (Ping.ping(target, 2)) {

      Serial.println("Internet    : ONLINE");

    }
    else {

      Serial.println("Internet    : OFFLINE");
    }
  }


  // --------------------------------------------------
  // If Wi-Fi is Disconnected
  // --------------------------------------------------

  else {

    Serial.println();

    Serial.println("WiFi Status : DISCONNECTED");

    Serial.println("Internet    : NOT TESTED");


    // Try to reconnect
    Serial.println("Trying to reconnect...");

    WiFi.reconnect();
  }


  // --------------------------------------------------
  // Connection Lost Detection
  // --------------------------------------------------

  if (previousWiFiState == true && currentWiFiStatus == false) {

    Serial.println();

    Serial.println("⚠️ Wi-Fi CONNECTION LOST!");
  }


  // --------------------------------------------------
  // Connection Restored Detection
  // --------------------------------------------------

  if (previousWiFiState == false && currentWiFiStatus == true) {

    Serial.println();

    Serial.println("✅ Wi-Fi CONNECTION RESTORED!");
  }


  // --------------------------------------------------
  // Update Previous Wi-Fi State
  // --------------------------------------------------

  previousWiFiState = currentWiFiStatus;


  // --------------------------------------------------
  // Monitor Every 5 Seconds
  // --------------------------------------------------

  Serial.println();

  Serial.println("Next check in 5 seconds...");

  delay(5000);
}
