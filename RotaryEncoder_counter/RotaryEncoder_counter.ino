/* Rotary encoder counter
The count gets incremented by one when encoder rotated right 
and decremented by one when encoder rotated left.

The count is reset to zero wnen pushbutton is pressed.
*/
#define ENC_A 6
#define ENC_B 7

#define Button 8
int A_val =1;
int B_val = 1;
int count = 0;
//*******************************************************
void setup()
{
  /* Setup encoder pins and pushbutton as inputs */
  pinMode(ENC_A, INPUT);
  digitalWrite(ENC_A, HIGH);
  pinMode(ENC_B, INPUT);
  digitalWrite(ENC_B, HIGH);
  pinMode(Button, INPUT);
  Serial.begin (115200);
}
//******************************************************
void loop()
{
  A_val = digitalRead(ENC_A);                       // read encoder inputs
  B_val = digitalRead(ENC_B);
  if (A_val != B_val){                              // if both are not 1 the encoder was rotated
    Serial.print("ENC_A = "); Serial.println(A_val);
    Serial.print("ENC_B = "); Serial.println(B_val); 
    
    if(A_val == 0 && B_val == 1) count++;          // rotated right
    if(A_val == 1 && B_val == 0) count--;          // rotated left
    Serial.print("count = "); Serial.println(count);
    Serial.println("----------------------");
    delay(400);
}
  if (digitalRead(Button) == false) {             // read pushbutton. if zero button pressed
    Serial.println("Button Pressed");
    count = 0;
    Serial.print("count = "); Serial.println(count);
    Serial.println("----------------------");
    delay(400);
  } 
    
}

