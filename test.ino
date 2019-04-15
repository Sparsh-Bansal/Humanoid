
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 140
#define MAX_PULSE_WIDTH 590
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 60
double perdegreechange;

char input; 
int analread;
int newanalread;
double changeangle;
double changeperdegree[3];
void setup() {
        pinMode(A5,INPUT);
        pinMode(A6,INPUT);
        pinMode(A7,INPUT);
        Serial.begin(9600);
        pwm1.begin();
        pwm1.setPWMFreq(FREQUENCY);
       
        

       
}

void loop() {
  
  char input = Serial.read();
  
  if (input=='s')
  {
    set90();
   servocallibration();
  }
  if(input=='i')
 {
  
  iniAnalogRead()detachhf (input=='d')
  {();
  }=alogRead((input == 'r')
  {  
  }
 analread

}



void iniAna{
 Aan5);
  Serial.println(analread);
  
}
void detachh()
{
  pwm1.setPWM(0,0,0);
  Serial.println("detached");
}

void set90()
{
  
  pwm1.setPWM(0,0,pulseWidth(90));
  
}


void servocallibration()
{
 pwm1.setPWM(0, 0, pulseWidth(85));
 delay(100);
 int p=analogRead(A5);
 Serial.println(p);
 pwm1.setPWM(0, 0, pulseWidth(95));
 delay(100);
 int q=  analogRead(A5);
  Serial.println(q);
  changeangle = double((q-p))/10.0;
 Serial.println(double((q-p))/10.0);
}













int pulse_wide(int angle){
  int pulse = map(angle,0,180,140,590);
  return pulse;
}








double pulseWidth(double angle)
{
double pulse_wide, analog_value;
pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
//analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
//Serial.println(analog_value);
return pulse_wide;
}
