
#include <SPI.h>
#include "mcp_can.h"

MCP_CAN CAN(9);                                    

void setup()
{
    Serial.begin(115200);
    pinMode(2,OUTPUT);

    while (CAN_OK != CAN.begin(CAN_500KBPS))          
    {
        Serial.println("CAN BUS initiation failed");
        Serial.println("Trying to initiate CAN BUS again");
        delay(100);
    }
    Serial.println("CAN BUS initiation Sucess");
}

int my_id = 134;
void loop()
{
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())           
    {
        CAN.readMsgBuf(&len, buf); 

        unsigned long canId = CAN.getCanId();

        Serial.println("-^-^-^-^-^-^-***-^-^-^-^-^-^-");
        Serial.print("Reciving data from CAN-ID: ");
        Serial.println(canId);
        for(int i = 0 ; i < 8 ; i++)
        {
          Serial.print(buf[i]);
          Serial.print(' ');
        }
        Serial.println(' ');
        
        if(canId == my_id)
        {
          Serial.println("Message recived over CANID{134}");
          if(buf[0] == 2)
          {
            digitalWrite(2,HIGH);
            Serial.println("Motor turned ON");
          }
          else if(buf[0] == 3)
          {
            digitalWrite(2,LOW);
            Serial.println("Motor turned OFF");
          }
          else
          {
            Serial.print("Enter valid command");
          }
        }
        
    }
}
