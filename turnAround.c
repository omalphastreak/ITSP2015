# ITSP2015
My Institue Summer Technical Project
#include<Stepper.h>

const int Rate = 180 ;
Stepper myStepper1(Rate , 8,9,10,11);
Stepper myStepper2(Rate , 4,5,6,7);
int stepCount1 = 0;
int stepCount2 = 90;
void setup(){
}
void loop()
{
myStepper1.step(1);
myStepper2.step(-1);
stepCount1 ++;
stepCount2 --;
if (stepCount1 = 90 && stepCount2 = 0)
myStepper1.step(0);
myStepper2.step(0);
}
