char inChar;
#define IR_RECEIVE_PIN 7 // The Arduino pin connected to IR controller
#include <IRremote.h>
#include <SoftwareSerial.h>
#define IR_BUTTON_POWER 69
#define IR_BUTTON_OFF 70

SoftwareSerial SerialBT(3,2); // TX, RX

const int Rl1 = 9;
const int buzzer = 10;


void setup(){
  Serial.begin(19200);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  SerialBT.begin(9600);
  SerialBT.begin(9600);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
}

void loop(){


  
 //Kontrol_Dengan_HC05

 if (SerialBT.available()) 
  {
    inChar = SerialBT.read();
  }
    if(inChar == 'N')
  {
    Serial.println("On");
    digitalWrite(Rl1, HIGH);
  }
  
    if(inChar == 'F')
  {
    Serial.println("Off");
    digitalWrite(Rl1, LOW);
  }

  if(inChar == 'C')
  {
    Serial.println("Connect");
  }
}
