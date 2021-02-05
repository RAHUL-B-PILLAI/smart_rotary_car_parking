int slota, slotb, slotc = 0, 0, 0;
#define vcc 5
#define gnd 8
#define trig 6
#define echo 7
float dis, dur;
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

}
void reader(currentslot,slot){
  if(currentlot<slot)
  for(i=currentslot;i<slot;i++){
    while(ultrasonic>3){
      motor=1;
      delay(200);
      ultrasonic=sonic();
      motor=0;
      delay(100);
    }
  }
}
void sonic(){
 dur=0;

digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
dur = pulseIn(echo,HIGH);
dis =(dur/2)*0.0343;//distance divde by 2 * speed of sound in millisecond
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
