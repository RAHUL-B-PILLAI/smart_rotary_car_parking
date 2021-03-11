#include <AccelStepper.h>

// Define a stepper and the pins it will use
AccelStepper stepper(AccelStepper::DRIVER, 3, 2);

int slot;
int enable=7;

void setup()
{ Serial.begin(9600);
  pinMode(enable,OUTPUT);
  stepper.setMaxSpeed(3000);
  stepper.setAcceleration(1000);
  digitalWrite(enable,HIGH);
}

void loop()
{ 
  Serial.println("enter the slot");
  while(Serial.available()==0);{
    }
  slot=Serial.readString().toInt();
  Serial.println(slot);
  rotate(slot);
  Serial.println("task complete");
  delay(1000);
}
int rotate(int slot){
  digitalWrite(enable,LOW);
  Serial.println("entered");
  int pos;  
    if(slot==1){
        Serial.println("entered3");
            pos=0;
              stepper.moveTo(pos);
              while(stepper.distanceToGo() != 0)
              {            
                    stepper.run();
                   }
  Serial.println("Reached slot1");
  } 
    else if(slot==2){
        Serial.println("entered3");
            pos=5000;
              stepper.moveTo(pos);
              while(stepper.distanceToGo() != 0)
              {            
                    stepper.run();
                   }
  Serial.println("Reached slot2");
  } 
  else if(slot==3){
        Serial.println("entered3");
            pos=-5000;
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
}
  

