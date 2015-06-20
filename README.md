# ITSP2015
My Institue Summer Technical Project
// ITSP2015
//My Institue Summer Technical Project

#include<Stepper.h>
#include<SPI.h>
#include<SD.h>
//size of arena 1.5m*1.5m
/*pinMode
8 pins for Stepper
6 pins for UDS
Necessary power levels - 12V , 5V
*/
/*const int stepsPerRevolution= 200 ;
Stepper myStepper1(stepsPerRevolution , 8 , 9 , 10 , 11);
Stepper myStepper2(stepsPerRevolution , 4 , 5 ,6,7);*/
int stepCount = 0;
float distance1 = 0 ;
float distance2 = 0;
float distance3 = 0;
float duration1;
float duration2;
float duration3;
int trigPin1= 7;
int trigPin2= 8;
int trigPin3= 9;
int echoPin1= A0;
int echoPin2= A1;
int echoPin3= A2;
int greenLedPin= 1;
int redLedPin= 2;
int yellowLedPin= A4;
const int chipSelect= 4;
void setup()
{
	Serial.begin(9600);
	pinMode(trigPin1 , OUTPUT);
	pinMode(trigPin2 , OUTPUT);
	pinMode(trigPin3 , OUTPUT);
	pinMode(echoPin1 , INPUT);
	pinMode(echoPin2 , INPUT);
	pinMode(echoPin3 , INPUT);
	pinMode(greenLedPin , OUTPUT);
	pinMode(redLedPin , OUTPUT);
	pinMode(yellowLedPin , OUTPUT);
        Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(10, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
//initializing pins
}


void loop()
{
digitalWrite(trigPin1 , LOW);
delayMicroseconds(100);
digitalWrite(trigPin1 , HIGH);
delayMicroseconds(100);
digitalWrite(trigPin1 , LOW);
delayMicroseconds(100);
duration1 = pulseIn(echoPin1 , HIGH);
duration1 = duration1/10000.;
distance1 = (duration1)*346.;
distance1 = (distance1)/2.;



digitalWrite(trigPin2 , LOW);
delayMicroseconds(100);
digitalWrite(trigPin2 , HIGH);
delayMicroseconds(100);
digitalWrite(trigPin2 , LOW);
delayMicroseconds(100);
duration2 = pulseIn(echoPin2 , HIGH);
duration2 = duration2/10000.;
distance2 = (duration2)*346.;
distance2 = (distance2)/2.;



digitalWrite(trigPin3 , LOW);
delayMicroseconds(100);
digitalWrite(trigPin3 , HIGH);
delayMicroseconds(100);
digitalWrite(trigPin3 , LOW);
delayMicroseconds(100);
duration3 = pulseIn(echoPin3 , HIGH);
duration3 = duration3/10000.;
distance3 = (duration3)*346.;
distance3 = (distance3)/2.;



  // make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ","; 
    }
  }

File datalog= SD.open("Map.txt" , FILE_WRITE);
if (datalog) {
    datalog.println(dataString);
    datalog.close();
    // print to the serial port too:
    Serial.println(dataString);
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening Map.txt");
  } 

/*if (distance3<1 && 90<distance2<100 && 90<distance1<100) 
 digitalWrite(greenLedPin, HIGH);
else  
 digitalWrite(redLedPin,HIGH);

while(distance3<1 && distance1>20)
{
myStepper1.step(1);
myStepper2.step(1);
}
//start to turn
//turn successfull. Repeat starting code*/
}
