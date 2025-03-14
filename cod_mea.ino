/*   
 *   Basic example code for controlling a stepper without library
 *      
 */

// defines pins

#define stepPin 5
#define dirPin 2 
#define CW 11 //CW is defined as pin #7//
#define CCW 7 //CCW is defined as pin #8//
int q = 0;
int ocupat = 0;
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(CW, OUTPUT); //Set CW as an output//
  pinMode(CCW, OUTPUT); //Set CCW as an output// 
  Serial.begin(9600);
}

void coboara(int steps){
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction
  //Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(700);    // by changing this time delay between the steps we can change the rotation speed
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(700); 
  }
  delay(1000); // One second delay
}

void urca(int steps){
    digitalWrite(dirPin,LOW); //Changes the rotations direction
  //Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < steps; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
  }

    delay(200);
}

void arunca()
{
  delay(500);
  digitalWrite(CW,HIGH); //Motor runs clockwise//
  delay(75);
  digitalWrite(CW, LOW); //Motor stops//
  delay(100);
}

void ia()
{
  delay(500);
  digitalWrite(CCW, HIGH);//Motor runs counter-clockwise//
  delay(150); //For 1 second//
  digitalWrite(CCW, LOW); //Motor stops//
  delay(100);
}

void puneMasina()
{
  urca(750);
  arunca();
  ia();
  coboara(750);
}

void iaMasina()
{
  urca(750);
  arunca();
  delay(1000);
  urca(100);
  ia();
  coboara(850);
}
void afisare()
{
  Serial.println("selecteaza o actiune:");
  Serial.println("parcheaza la etaj - scrie 1");
  Serial.println("ia masina de la etaj - scrie 2");
}
void loop() {
  
  afisare();
  while (Serial.available() == 0) {
  }

  int action = Serial.parseInt();
  char c = Serial.parseInt();
  if(action == 1)
    {
      if(ocupat == 0)
      {
        puneMasina();
        Serial.println("SUCCES! Ai parcat!");
        ocupat = 1;
      }else{
        Serial.println("ERROR OCUPAT!");
      }

    }

  if(action == 2)
  {
    if(ocupat == 1)
      {
        iaMasina();
        ocupat = 0;
        Serial.println("SUCCES! Ridica masina!");
      }else{
        Serial.println("ERROR Nu exista masina!");
      }
    
  }
  
  /*while(q == 0)
  {
    delay(1000);
    //puneMasina();
    //coboara(800);
    //urca(100);
   
    q++;
  } 
  delay(500);
  */
}