int pin[] = {16,5,4,0,2,14};
int numPin = 6;
int pinOnIndex = 0;

void setup() {
  for(int i=0;i<numPin;i++){
    pinMode(pin[i],OUTPUT);
  }
}

void loop() {
  for (int i=0;i<numPin;i++){
    if(i==pinOnIndex){
      digitalWrite(pin[i],HIGH);
    }else{
      digitalWrite(pin[i],LOW);
    }
 }

 delay(300);
 pinOnIndex = pinOnIndex+1;
 if(pinOnIndex>=numPin){
  pinOnIndex = 0;
 }

}
