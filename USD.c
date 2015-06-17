//ITSP2015
//My Institue Summer Technical Project
//CodeForUDS
int trigPin1= 13;
int trigPin2= 3;
int trigPin3= 4;

int echoPin1 = 11;
int echoPin2 = 12;
int echoPin3 = 10; 
float distance1;
float duration1;
float distance2;
float duration2;
float distance3;
float duration3;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
}
void loop()
{
  
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  
  duration1 = duration1/10000.;
  distance1 = duration1*346.;
  distance1 = distance1/2.;
  duration1 = pulseIn(echoPin2, HIGH);
  
   digitalWrite(trigPin2, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2 , HIGH);
  
  duration2 = (duration2)/10000.;
  distance2 = (duration2)*346.;
  distance2 = (distance2)/2.;
  
   digitalWrite(trigPin3, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin3, LOW);
  
  duration3 = pulseIn(echoPin3 , HIGH);
  
  duration3 = (duration3)/10000.;
  distance3 = (duration3)*346.;
  distance3 = (distance3)/2.;
  
  Serial.print(distance1);
  Serial.println("cm");
  Serial.print(distance2);
  Serial.println("cm");
  Serial.print(distance3);
  Serial.println("cm");
  delay(1000);
}
