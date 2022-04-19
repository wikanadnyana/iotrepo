const int trigPin = 5;
const int echoPin = 4;
const int r = 6;
const float pi = 3.14;
const float tinggiGelas = 10;

#define SOUND_VELOCITY 0.034

long duration;
float distanceCm;
float volume;
float tinggiAir;

void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_VELOCITY/2;
  tinggiAir = tinggiGelas - distanceCm;
  if (tinggiAir < 0){
    tinggiAir = 0;
  }
  volume = pi * r * r * tinggiAir;

  Serial.print("Tinggi Air (cm): ");
  Serial.println(tinggiAir);
  Serial.print("Volume Air (cm^3): ");
  Serial.println(volume);
  Serial.print("Tinggi Kosong (cm): ");
  Serial.println(distanceCm);
  Serial.print("================= ");
  Serial.print("\n");


  delay(1000);
}