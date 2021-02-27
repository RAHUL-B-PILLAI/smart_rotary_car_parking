//using easy driver as stepper driver

#define dir_pin 2
#define step_pin 3

void setup(){
    pinMode(dir_pin, OUTPUT);
    pinmode(step_pin, OUTPUT);
    digitalWrite(dir_pin, HIGH);// TO ROTATE CLOCKWISE
}

voidloop(){

    digitalWrite(step_pin,HIGH);
    delay(5);
    digitalWrite(step_pin,LOW);
    delay(5);

}