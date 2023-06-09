const int POTEN_PIN = A1;
const int PHOTO_PIN = A3;

const int btn_A_PIN = 2;
const int btn_B_PIN = 3;

int btn_A_value = 0;
int btn_B_value = 0;

int previous_btn_A_value = 0;
int previous_btn_B_value = 0;

const int ledA = 5;
const int ledB = 6;

//myLEDs[2] = {5, 6};

int actuatorValue = 0;
int previousValue = 0;

void setup() {
  // put your setup code here, to run once:


/*___________________________________________

1) Set the mode for each Pin.

_____________________________________________ */ 

pinMode(btn_A_PIN, INPUT_PULLUP);
pinMode(btn_B_PIN, INPUT_PULLUP);
pinMode(ledA, OUTPUT);
pinMode(ledB, OUTPUT);
pinMode(PHOTO_PIN, INPUT);
  
  Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
   /*if(Serial.available() > 0) {
    receivingData();
  } else {
    sendingData();
  } */

  buttonState1 = digitalRead(btn_A_PIN == LOW);
  buttonState2 = digitalRead(btn_B_PIN == LOW);

  if(buttonState1){
    digitalWrite(ledA, HIGH);
  } else {
    digitalWrite(ledA, LOW);
  }

   if(buttonState2){
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }

  delay(100);
  
}

void sendingData() {
  
  /*___________________________________________

2) Read the value of each pin below
_____________________________________________ */ 

  
    
  if (previousValue != actuatorValue) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previousValue = actuatorValue;
  }

  if (previous_btn_A_value != btn_A_value) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previous_btn_A_value = btn_A_value;
  }

    if (previous_btn_B_value != btn_B_value) {
    sendSerialMessage(actuatorValue, btn_A_value, btn_B_value);
    previous_btn_B_value = btn_B_value;
  }

  delay(100);
}

/*___________________________________________

3) Print the value of the actuator and the value of each button.

Example: 
Serial.print(value);
Serial.print(' ');
Serial.println();
_____________________________________________ */ 

void sendSerialMessage(int actuatorValue, int btn_A_value, int btn_B_value) {

  
}

/*___________________________________________

4) Receive the messages sended by the Game.
S is for scoring: If you score a point, both leds should turn on and off
L is for loosing: If you loose, both leds should turn on
_____________________________________________ */ 

void receivingData() {
  char inByte = Serial.read();



  switch(inByte){
    case 'S':
    
      break;
    case 'L':

      break;
  }
  Serial.flush();
}