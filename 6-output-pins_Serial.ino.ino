/*
 6 output pins controlled by Serial monitor
  - Send 1 - 6 to toggle outputs On or Off
  - send 0 to turn all outputs OFF
  - (GPIO pins used are 2 to 7)
 Author: Dan Nadeau
 Dec 4, 2020
*/

bool outState[]= {false, false, false, false,false,false,false, false};

//---------------------------------------------------------------------
void setup() {
  for(int i=2; i <=7; i++){
    pinMode(i, OUTPUT);           // initialize the output pins 2 to 7
  }
  Serial.begin(9600);
  Serial.println("Ready");
}
//------------------------------------------------------------------------
void loop() {
  int i;
 
  if(Serial.available()){
    i = Serial.read();                      // get ASCII character
    i -= 48;                                // Convert to integer
   
    switch (i){
      case 0:
      {
        for(i=2; i <=7; i++){
          outState[i] = false;
          digitalWrite(i, LOW);         // turn all outputs off
        }
        Serial.println( "All outputs are OFF ");
        break;
      }
      case 1: case 2: case 3: case 4: case 5: case 6:
      { outState[i+1] = !outState[i+1];     // toggle pin status
        if  (outState[i+1] == true) {
           digitalWrite(i+1, HIGH);       // turn output on
           Serial.print( "Output ");
           Serial.print( i );
           Serial.println( " is ON ");
        } else {
           digitalWrite(i+1, LOW);        // turn output off
           Serial.print( "Output ");
           Serial.print( i );
           Serial.println( " is OFF ");
        }
        break;
      }
    }
  }
}
