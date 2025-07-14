#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(10); // CS pin

void setup() {
    Serial.begin(115200);
    SPI.begin();

    if (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
        Serial.println("CAN Transmitter Ready...");
    } else {
        Serial.println("CAN Init Failed! Check Wiring");
        while (1);
    }

    CAN.setMode(MCP_NORMAL);
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim();
        int len = input.length();
        if (len > 8) len = 8; // CAN Max 8 bytes

        unsigned char data[8];
        input.getBytes(data, len + 1); // Convert string to bytes

        Serial.print("Sending: ");
        Serial.println(input);

        byte sendStatus = CAN.sendMsgBuf(0x100, 0, len, data);
        
        if (sendStatus == CAN_OK) {
            Serial.println("Message Sent Successfully!");
        } else {
            Serial.println("Message Send Failed! Check Wiring or Resistors.");
        }

        delay(500); // Small delay before next message
    }
}
