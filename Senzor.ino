/* Acest cod este pentru miscarea autonoma a masini  
 *  mai precis de a ocoli obstacolele prin ajutorul
 *  unui senzor ultrasonic HC-SR04.
 */
int motor1pin1 = 13;
int motor1pin2 = 12; //initalizarea motoarelor

int motor2pin1 = 10;
int motor2pin2 = 11;

int trigpin=7; //initializarea senzorului de ultrasunete emitator,receptor
int echopin=6;

long duration,distance;


void setup() {
  Serial.begin(9600);

  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(4, OUTPUT); 
  pinMode(3, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:   
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigpin, HIGH); // transmite unde ultrasonice pentru 10 microsecunde  
  delayMicroseconds(10);
  duration = pulseIn(echopin, HIGH); // receptorul primeste undele ultra sunete in raport cu timpul
  distance = (duration / 2) * 0.0343;
  delay(10);
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(4, 200); //ENA pin
  analogWrite(3, 200); //ENB pin
  if(distance >70){
  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(500);
  }
  if(distance <70){
  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  delay(500);
  
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);

   digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(500);
  }
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
     Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  }
  
  
