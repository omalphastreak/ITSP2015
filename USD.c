# ITSP2015
#My Institue Summer Technical Project
#CodeForUDS
int trigPin1= 13;

int echoPin1 = 11;
//int echoPin2 = 12;

float distance1;
float duration1;
//float distance2;
//float duration2;


void setup()
{
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  //pinMode(echoPin2, INPUT); 
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
  distance1 = duration1*330;
  distance1 = distance1/2;
  /*duration1 = pulseIn(echoPin2, HIGH);
  
  duration1 = (duration2)/10000.;
  distance1 = (duration2)*330;
  distance1 = (distance2)/2;
 
  */
  Serial.print(distance1);
  Serial.println("cm");
  //Serial.print(distance2);
  //Serial.print("cm");
  delay(1000);
}
