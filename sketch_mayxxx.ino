

//Change these to match the pins on your Arduino - make sure theyre PWM capable
int greenPin = 10;
int redPin = 11;
int bluePin = 9;
int soundsensor=8;

void setup(){
  pinMode(soundsensor, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  analogWrite(bluePin,0);
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  delay(3);
}

void loop(){
   
    if (digitalRead(soundsensor)==HIGH){
      Serial.println("highhhhhhhhhhhhhhh");
      analogWrite(redPin,200);
      analogWrite(bluePin,195);
      analogWrite(greenPin,200);
      delay(4);
      analogWrite(bluePin,0);
      analogWrite(redPin,0);
      analogWrite(greenPin,0);
      delay(4);
      
    }
    else{
      Serial.println("low");
      delay(1);
    }
}

void fadeFromTo(int from, int to){
  for(int i = 0; i < 255; i++){
    analogWrite(to, i);
    delay(0.5);
    analogWrite(from, 255 - i);
    delay(0.5);
  }
}
