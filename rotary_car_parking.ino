#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER,4, 3); //dir 3,step 4

int slot;
int enable=7;
int park[]={1,1,1};
int currentslot;
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);

/* Uno's A4 to SDA & A5 to SCL */

void setup(void) {
  //pinMode(2,INPUT);
  pinMode(enable,OUTPUT);
  //pinMode(ms1,OUTPUT);
 // pinMode(ms2,OUTPUT);
    Serial.begin(9600);
  pinMode(enable,OUTPUT);
  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(100);
  digitalWrite(enable,HIGH);
    nfc.begin();
  //attachInterrupt(0, blink, RISING);
}

void loop(void) {
  
Serial.println("\nScan a NFC tag\n");

    if (nfc.tagPresent())

    {   

    Serial.println("NFC tag Found!\n");
    NfcTag tag = nfc.read();
    
    String uid;
    Serial.print("UI: ");
    uid=tag.getUidString();
    Serial.println(tag.getUidString());
          
    if(uid=="F3 9A D8 18"){      
    Serial.println("slot1");
    slot=1;
      }
      
    else if(uid=="73 32 D5 18"){
      Serial.println("slot2");
      slot=2;
      }
      
    else if(uid=="73 8E DB 18"){
      Serial.println("slot3");
      slot=3;
      }
   
      
    else if(uid=="D3 B3 DE 18"){
      Serial.println("slot4");
      slot=4;
      }
      
    else if(uid=="13 1C BF 18"){
      Serial.println("slot5");
      slot=5;
      }
    
    else{
      Serial.println("no slot");
      slot=0;
      }
    } 
//UID 1C B4 E9 21 slot1, UID 55 51 14 2A slot2, F3 9A D8 18 slot3,73 32 D5 18 slot4, 73 8E DB 18 slot5, D3 B3 DE 18 slot6, 13 1C BF 18 slot7
  currentslot=slot;
  Serial.println(park[currentslot-1]);
  Serial.println(slot);
  rotate(slot);
  Serial.println("task complete");
  delay(2000);

}


int rotate(int slot){
  digitalWrite(enable,LOW);
  int pos;  
    if(slot==1){
            pos=0;
              stepper.moveTo(pos);
              while(stepper.distanceToGo() != 0)
              {            
                    stepper.run();
                   }
  Serial.println("Reached slot1");
  } 
    else if(slot==2){
            pos=-5000;
              stepper.moveTo(pos);
              while(stepper.distanceToGo() != 0)
              {            
                    stepper.run();
                   }
  Serial.println("Reached slot2");
  } 
  else if(slot==3){       
            pos=-10000;
              stepper.moveTo(pos);
              while(stepper.distanceToGo() != 0)
              {            
                    stepper.run();
                   }
  Serial.println("Reached slot3");
      }  
    else
    {Serial.println("enter correct slot");
      }
 digitalWrite(enable,HIGH);
 slot=0;
}

void blink(){
  park[currentslot-1]=!park[currentslot-1];
  Serial.println("interrupt recieved");
  }
 

