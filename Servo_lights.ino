// ----------LIBRARIES--------------

#include <Servo.h>





// --------CONSTANTS (won't change)---------------
const int led_A_Pin = 13;
const int led_B_Pin = 12;
const int led_C_Pin = 11;
const int led_D_Pin = 10;

const int servoPin = 9; // the pin number for the servo signal


const int led_A_Interval = 2500;
const int led_B_Interval = 4500;
const int led_C_Interval = 6500;
const int led_D_Interval = 8500;

const int blinkDuration = 500;

const int servoMinDegrees = 20; // the limits to servo movement
const int servoMaxDegrees = 150;

//------------ VARIABLES (will change)---------------------

byte led_A_State = LOW;           //   LOW = off
byte led_B_State = LOW;
byte led_C_State = LOW;
byte led_D_State = LOW;

Servo myservo;  // create servo object to control a servo 

int servoPosition = 90;     // the current angle of the servo - starting at 90.
int servoSlowInterval = 80; // millisecs between servo moves
int servoFastInterval = 10;
int servoInterval = servoSlowInterval; // initial millisecs between servo moves
int servoDegrees = 2;       // amount servo moves at each step 
                            //    will be changed to negative value for movement in the other direction

unsigned long currentMillis = 0;    // stores the value of millis() in each iteration of loop()
unsigned long previousOnBoardLedMillis = 0;   // will store last time the LED was updated
unsigned long previousLed_A_Millis = 0;
unsigned long previousLed_B_Millis = 0;
unsigned long previousLed_C_Millis = 0;
unsigned long previousLed_D_Millis = 0;


unsigned long previousButtonMillis = 0; // time when button press last checked

unsigned long previousServoMillis = 0; // the time when the servo was last moved


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting SeveralThingsAtTheSameTimeRev1.ino");  // so we know what sketch is running
  
  pinMode(led_A_Pin, OUTPUT);
  pinMode(led_B_Pin, OUTPUT);
  pinMode(led_C_Pin, OUTPUT);
  pinMode(led_D_Pin, OUTPUT);
  
  myservo.write(servoPosition); // sets the initial position
  myservo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
currentMillis = millis(); 

            // call the functions that do the work
  updateLed_A_State();
  updateLed_B_State();
  updateLed_C_State();
  updateLed_D_State();
  switchLeds();
  servoSweep();


}

//========================================

void updateLed_A_State() {

  if (led_A_State == LOW) {
    if (currentMillis - previousLed_A_Millis >= led_A_Interval) {
       led_A_State = HIGH;
       previousLed_A_Millis += led_A_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_A_Millis >= blinkDuration) {
       led_A_State = LOW;
       previousLed_A_Millis += blinkDuration;
    } 
  }    
}

//========================================

void updateLed_B_State() {

  if (led_B_State == LOW) {
    if (currentMillis - previousLed_B_Millis >= led_B_Interval) {
       led_B_State = HIGH;
       previousLed_B_Millis += led_B_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_B_Millis >= blinkDuration) {
       led_B_State = LOW;
       previousLed_B_Millis += blinkDuration;
    }
  }    
}
//========================================

void updateLed_C_State() {

  if (led_C_State == LOW) {
    if (currentMillis - previousLed_C_Millis >= led_C_Interval) {
       led_C_State = HIGH;
       previousLed_C_Millis += led_C_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_B_Millis >= blinkDuration) {
       led_C_State = LOW;
       previousLed_C_Millis += blinkDuration;
    }
  }    
}

//========================================

void updateLed_D_State() {

  if (led_D_State == LOW) {
    if (currentMillis - previousLed_D_Millis >= led_D_Interval) {
       led_D_State = HIGH;
       previousLed_D_Millis += led_D_Interval;
    }
  }
  else {
    if (currentMillis - previousLed_D_Millis >= blinkDuration) {
       led_D_State = LOW;
       previousLed_D_Millis += blinkDuration;
    }
  }    
}
//========================================
void switchLeds() {
      // this is the code that actually switches the LEDs on and off

  
  digitalWrite(led_A_Pin, led_A_State);
  digitalWrite(led_B_Pin, led_B_State);
  digitalWrite(led_C_Pin, led_C_State);
  digitalWrite(led_D_Pin, led_D_State);
}

//========================================
void servoSweep() {

      // this is similar to the servo sweep example except that it uses millis() rather than delay()

      // nothing happens unless the interval has expired
      // the value of currentMillis was set in loop()
  
  if (currentMillis - previousServoMillis >= servoInterval) {
        // its time for another move
    previousServoMillis += servoInterval;
    
    servoPosition = servoPosition + servoDegrees; // servoDegrees might be negative

    if (servoPosition <= servoMinDegrees) {
          // when the servo gets to its minimum position change the interval to change the speed
       if (servoInterval == servoSlowInterval) {
         servoInterval = servoFastInterval;
       }
       else {
        servoInterval = servoSlowInterval;
       }
    }

    if ((servoPosition >= servoMaxDegrees) || (servoPosition <= servoMinDegrees))  {
          // if the servo is at either extreme change the sign of the degrees to make it move the other way
      servoDegrees = - servoDegrees; // reverse direction
          // and update the position to ensure it is within range
      servoPosition = servoPosition + servoDegrees; 
    }
    
        // make the servo move to the next position
    myservo.write(servoPosition);
        // and record the time when the move happened

  }
  
}

//========================================END

