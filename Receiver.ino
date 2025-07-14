#include <SPI.h>
#include <mcp_can.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 8); // LCD pins
MCP_CAN CAN(10); // CAN module CS pin
void setup() {
    Serial.begin(9600);
    SPI.begin();
    if (CAN.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK) {
        Serial.println("CAN Receiver Ready...");
    } else {
        Serial.println("CAN Init Failed!");
        while (1);
    }
    CAN.setMode(MCP_NORMAL);
    // Proper LCD Initialization
    lcd.begin(16, 2);
    delay(100); // Small delay for LCD to initialize
    lcd.print("CAN Receiver Ready");
    delay(2000);
    lcd.clear();
}
void loop() {
    long unsigned int id;
    unsigned char len;
    unsigned char buf[16];
    // Check if a message is available
    if (CAN.checkReceive() == CAN_MSGAVAIL) {
        CAN.readMsgBuf(&id, &len, buf);
        // Convert received data into a string
        String receivedMsg = "";
        for (int i = 0; i < len; i++) {
            receivedMsg += (char)buf[i]; // Convert bytes to characters
        }
        receivedMsg.trim(); // Remove unwanted characters
        Serial.print("Received Message: ");
        Serial.println(receivedMsg); // Debug on Serial Monitor
        // Display on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Received:");
        lcd.setCursor(0, 1); // Move to second row
        lcd.print(receivedMsg);
        delay(2000); // Keep message visible for 2 seconds
    }
}