//#include<string.h>
int n = 0;
char c;
char discard;         // to handle \cr & \lf
int bufLen = 20;      // Serial buffer length
char inBuf[20];       // Serial buffer
char hold[20];        // Working buffer
//----------------------
void setup() {
  Serial.begin(115200);
}
//----------------------
void loop() {
  int n;                                // number of characters to read
   n = Serial.available();
   if(n > 2){                           // if more than  CR LF
     Serial.readBytes(inBuf,n-2);       // read characters minus CR & LF
     discard = Serial.read();           // discard CR
     discard = Serial.read();           // discard LF
     Serial.print(n);
     Serial.print (" Received string: " );
//     Serial.println(inBuf); 
     for(int i = 0 ; i < bufLen; i++){  // for each characters in inBuf
        hold[i] = inBuf[i];             // transfer char to working buffer
        Serial.print(int(inBuf[i]));
        Serial.print(" - ");
        inBuf[i] = '\0';                // overwrite the char in inBuf with a NULL haracter
      }                                 // blanking ibnuff for next read
      Serial.println();
      Serial.println(hold);
    n=0;                                // reset character count for next read
   }
}
