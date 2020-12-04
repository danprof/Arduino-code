/*
 6 output pins controlled by Serial monitor
  - Send 1 - 6 to toggle outputs On or Off
  - send 0 to turn all outputs OFF

 Author: Dan Nadeau
 Dec 4, 2020
*/

bool outState[]= {false, false, false, false,false,false,false};

//---------------------------------------------------------------------
void setup() {
  for(int i=1; i <=6; i++){
    pinMode(i, OUTPUT);           // initialize the output pins 1 to 6
  }
  Serial.begin(9600);
}
//------------------------------------------------------------------------
void loop() {
  int i;
  if(Serial.available()){
    i = Serial.read(); 
    switch (i){
      case 0:
      {
        for(i=1; i <=6; i++){
          outState[i] == false;
          digitalWrite(i, LOW);         // turn all outputs off
        }
        Serial.println( "All outputs are OFF ");
        break;
      }
      case 1: case 2: case 3: case 4: case 5: case 6:
      { outState[i] = !outState[i];     // toggle pin status
        if  (outState[i] == true) {
           digitalWrite(i, HIGH);       // turn output on
           Serial.print( "Output ");
           Serial.print( i );
           Serial.println( "is ON ");
        } else {
           digitalWrite(i, LOW);        // turn output off
           Serial.print( "Output ");
           Serial.print( i );
           Serial.println( "is OFF ");
        }
        break;
      }
    }
  }
}
