int trigpin1 = 11; // Front
int echopin1 = 13; // Front
int trigpin2 = 10; // Right
int echopin2 = 12; // Right
int trigpin3 = 6;  // Left
int echopin3 = 8;  // Left

int Tfront, Tleft, Tright;
float Dfront, Dleft, Dright;

void setup()
{
  Serial.begin(9600);
  
  pinMode(echopin1, INPUT);
  pinMode(echopin2, INPUT);
  pinMode(echopin3, INPUT);
  
  pinMode(trigpin1, OUTPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(trigpin3, OUTPUT);
  
  pinMode(7, OUTPUT); // Motor control pins
  pinMode(2, OUTPUT); // Motor control pins
  pinMode(4, OUTPUT); // Motor control pins
  pinMode(3, OUTPUT); // Motor control pins
}

void loop()
{
  // Read Front Sensor
  digitalWrite(trigpin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);
  Tfront = pulseIn(echopin1, HIGH);
  Dfront = (0.0343 * Tfront) / 2;
  
  delay(50);
  
  // Read Right Sensor
  digitalWrite(trigpin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);
  Tright = pulseIn(echopin2, HIGH);
  Dright = (0.0343 * Tright) / 2;
  
  delay(50);
  
  // Read Left Sensor
  digitalWrite(trigpin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin3, LOW);
  Tleft = pulseIn(echopin3, HIGH);
  Dleft = (0.0343 * Tleft) / 2;
  
  delay(50);
  
  // Control Motors
  if (Dfront >= 10.0 && Dfront<=330.0)
  {
    // Move Forward
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    
    Serial.println("Micromouse is moving forward");
    delay(1500);
  }
  else if (Dright >= 10.0 && Dright<=330.0)
  {
    // Turn Right
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    
    Serial.println("Micromouse is turning right");
    delay(1500);
  }
  else if (Dleft >= 10.0 && Dleft<=330.0)
  {
    // Turn Left
    digitalWrite(7, LOW);
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    
    Serial.println("Micromouse is turning left"); 
    delay(1500);
  }
  else
  {
    // Move Backward
    digitalWrite(7, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    
    Serial.println("Micromouse is moving backward");
    delay(1500);
  }
  
  delay(2000); // Delay for the next loop iteration
}
