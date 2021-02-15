int slota,slotb,slotc=0;
float dis, dur;
float ultrasonic;
#define vcc 5
#define gnd 8
#define trig 6
#define echo 7
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(trig,OUTPUT);
pinMode(echo, INPUT);
pinMode(vcc,OUTPUT);
pinMode(gnd,OUTPUT);

digitalWrite(vcc,HIGH);
digitalWrite(gnd,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("Available slots");
Serial.print("Slot A:");
Serial.println(slota);
Serial.print("Slot B:");
Serial.println(slotb);
Serial.print("Slot C:");
Serial.println(slotc);
Serial.println("Enter current slot");  
    while (Serial.available() == 0)   
    { //Wait for user input  
      }
int currentslot=Serial.readString().toInt();  
Serial.println("Enter required slot");
while (Serial.available() == 0)   
    { //Wait for user input  
    }

long int slot= Serial.readString().toInt();
reader(currentslot,slot);

delay(1000);

}

void reader(int currentslot,int slot){
  
  if(currentslot<slot){
    
    for(int i=currentslot;i<slot;i++){
      
      int motor=1;
      Serial.println("motor is running");
      delay(200);
      int enter=0;
      while(ultrasonic>3){
       
       ultrasonic=sonic();
        Serial.println(ultrasonic);
        enter=1;
      }
    ultrasonic=sonic();
    Serial.println(ultrasonic);
    Serial.println(enter);
    motor=0;
    delay(10+00);
    motor=0;
    Serial.println("motor is off");   
    }
  }
  else if(currentslot>slot){
    int j=3-slot;
    for(int i=0;i<j;i++){
int motor=1;
      Serial.println("motor is running");
      delay(200);
      int enter=0;
      while(ultrasonic>3){
       
       ultrasonic=sonic();
        Serial.println(ultrasonic);
        enter=1;
      }
    ultrasonic=sonic();
    Serial.println(ultrasonic);
    Serial.println(enter);
    delay(1000);
    motor=0;
    Serial.println("motor is off");
    }
  
  }
}



long sonic(){
 dur=0;

digitalWrite(trig,LOW);

delayMicroseconds(2);

digitalWrite(trig,HIGH);

delayMicroseconds(10);

digitalWrite(trig, LOW);

dur = pulseIn(echo,HIGH);

//distance divde by 2 * speed of sound in millisecond
dis =(dur/2)*0.0343;

Serial.print("distance= ");
if (dis>400 || dis <2)
{
  Serial.println("out of range");
  }
else {
  Serial.print(dis);
  Serial.println("cm");}
return dis;
}