//*************************************************
//
//   when characters are received through serial connection
//   they usually include a Carriage Return (CR) and a Line Feed (LF) character.
//   These could cause problems when printing the string or trying to process the data.
//   This code removes the CR & LF and terminates the string with a NULL character (\0).
//   It also overwites the input buffer (inBuf) with NULL characters so that if the next input 
//   is shorter than the previous one, any left over characters will not be included in new string.
//   The new string is copied to the hold buffer for processing. 
//   Hold can be used as a string ie:  Serial.println(hold);
//   or it can be processed one character at a time until a null is reached.
//                      ie:   int i=0;
//                            char s=hold[i];
//                            while( s != '\0'){
//
//                                process code here
//
//                                i++;
//                                s=hold[i];
//                            }
//                                 
//
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
  
  // process code goes here
 
}
