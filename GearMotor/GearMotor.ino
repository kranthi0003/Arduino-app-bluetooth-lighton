//Project Ekathra
//Rotating Solar Panel with Arduino and DC(Gear) Motor

#define E1 10  // Enable Pin for motor 1 
#define I1 8  // Control pin 1 for motor 1
#define I2 9  // Control pin 2 for motor 1

//Gear motor mechanism = turns in one direction for I1 & I2, if we interchange status of I1 & I2 the direction o rotation changes.
void setup() {

  //set the pin mode for the motor to be an output

   pinMode(E1, OUTPUT);//Enable Pin
   pinMode(I1, OUTPUT);//Control Pin 1
   pinMode(I2, OUTPUT);//Control Pin 2
    
   Serial.begin(14400);//Serial Data rate transmission with computer,i.e 14400 bits per sec
}

void loop() {

// read the value from the sensor

 int leftsensorValue = analogRead(A0);//read the analogue voltage from left Ldr
 int rightsensorValue = analogRead(A1);////read the analogue voltage from right Ldr

// Convert the analog value into standard voltage 

 float volt1=leftsensorValue*(5.0/1023.0); 
 float volt2=rightsensorValue*(5.0/1023.0);

  
  if (volt1 > volt2){//if(leftsensval>rightsensval)--rotate left;
      //since intensity increases,,voltage increases
    digitalWrite(E1, 1);
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
    
  }
  if (volt2 > volt1){//if(rightsensval>leftsensval)--rotate right;
   
    digitalWrite(E1, 1);
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    
  }
 
  if (volt2 == volt1) {//if left==right then do nothing =>turn off enable pin;
    digitalWrite(E1, LOW);
  }

  //print voltages

  Serial.print("sensorValue: ");
  Serial.println(volt1);
  Serial.print(' ');
  Serial.print("sensorValue1: ");
  Serial.println(volt2);
  Serial.print('\n');

  delay (500);
}
