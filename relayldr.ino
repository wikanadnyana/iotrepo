int hasilLdr;
int pinRelay = 14;

void setup() {
  Serial.begin(9600);
  pinMode(pinRelay,OUTPUT);
  digitalWrite(pinRelay, LOW);
}

void loop() {
  hasilLdr = analogRead(A0);
  Serial.println("=========================");
  Serial.print("Intensitas Cahaya = ");
  Serial.println(hasilLdr);

  if(hasilLdr>50){
    digitalWrite(pinRelay,LOW);
    Serial.println("Lampu Mati");
  }else if(hasilLdr<=50){
    digitalWrite(pinRelay,HIGH);
    Serial.println("Lampu Menyala");
  }
  Serial.println("=========================");
  delay(1000);
 
}