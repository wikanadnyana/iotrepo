int pin[] = {16,5,4,0,2,14};
int numPin = 6;
int pinOnIndex = 0;
int countLed = 3;

void setup() {
  for(int i=0;i<numPin;i++){
    pinMode(pin[i],OUTPUT);
  }
}

void loop() {
  for (int i=0;i<numPin;i++){
    if(i==pinOnIndex){
        if(i==(numPin-2)){
          int tempLed = i;
          for (int j=0;j<countLed;j++){
              if (j==2){
                digitalWrite(pin[0],HIGH);
            }
            digitalWrite(pin[i+j],HIGH);
          }
        }else if(i== (numPin-1)){
            for (int j=0;j<countLed;j++){
              if (j==2){
                for (int k=0;k<2;k++){
                  digitalWrite(pin[k],HIGH);
                }
            }
              digitalWrite(pin[i+j],HIGH);
              
          }
        }else{
           for (int j=0;j<countLed;j++){
              digitalWrite(pin[j+i],HIGH);
          }
        }
    }
 }
 delay(1000);
 pinOnIndex = pinOnIndex+1;
 
int ledOff = pinOnIndex - 1;
digitalWrite(pin[ledOff],LOW);
 
 if(pinOnIndex>=numPin){
  pinOnIndex = 0;
 }

}
