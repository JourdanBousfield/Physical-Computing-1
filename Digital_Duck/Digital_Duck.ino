
void setup() {
Serial.begin(9600);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(9, OUTPUT);
}

void loop() {
// read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability


if (sensorValue <600 && sensorValue >500){ 
 digitalWrite (12, HIGH);   // turn the LED on (HIGH is the voltage level)
}else{
  digitalWrite (12, LOW);
}

if (sensorValue <700 && sensorValue >600){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
}else{
  digitalWrite(13, LOW);
}

if (sensorValue >700 && sensorValue <800){
  analogWrite (9, 100);
}else{
 digitalWrite (9,LOW);
}
}
