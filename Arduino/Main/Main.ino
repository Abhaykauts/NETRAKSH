#include <esp_now.h>
#include <WiFi.h>

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t broadcastAddress1[] = {0xB0, 0xA7, 0x32, 0xF3, 0x2F, 0x10}; // Enter your Receiver board MAC Address

String cmd;

typedef struct test_struct {
  char command;
} test_struct;

test_struct test;

esp_now_peer_info_t peerInfo;

// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Check for data from the serial port
  if (Serial.available() > 0) {
    cmd = Serial.readStringUntil('\r'); // Read the command sent by the OpenCV program

    // Prepare the data to send
    test.command = cmd.charAt(0);

    // Send data via ESP-NOW
    esp_err_t result = esp_now_send(broadcastAddress1, (uint8_t *) &test, sizeof(test_struct));
    if (result == ESP_OK) {
      Serial.println("Sent with success: " + cmd);
    } else {
      Serial.println("Error sending the data");
    }
  }
}