    /*
    -Arduino Position Encoder
    -Using a generic photo-interrupter
    -Basic Test Sketch 1 / June 2014
    -Tested at TechNode Protolabz
    -www.electroschematics.com/
    */
    const int encoderInV = 8; // input venstre 
    const int encoderInH = 9; // input højre 

    int detectStateV=0; // Variable for reading the encoder status
    int detectStateH=0; // Variable for reading the encoder status
    int counter;
    int lastStateV;
    int newStateV;
    int counterV;
    int lastStateH;
    int newStateH;
    int counterH;

    void setup() {
       Serial.begin( 9600 );
       pinMode(encoderInV, INPUT); //Set pin 8 as input
       pinMode(encoderInH, INPUT); //Set pin 9 as input
    }
    
    void loop() {
       detectStateV=digitalRead(encoderInV);
       detectStateH=digitalRead(encoderInH);
       counter++;
       
       if (detectStateV == HIGH) { //If encoder output is high
          newStateV = 1;
       } else {
          newStateV = 0;          
       }
       if (lastStateV == newStateV) {
        if (lastStateV == 0) lastStateV = 1; else lastStateV = 0;
        counterV++;
        //Serial.println(counter);
       }

       if (detectStateH == HIGH) { //If encoder output is high
          newStateH = 1;
       } else {
          newStateH = 0;          
       }
       if (lastStateH == newStateH) {
        if (lastStateH == 0) lastStateH = 1; else lastStateH = 0;
        counterH++;
        //Serial.println(counter);
       }
      if (counterV != counterH) {
        Serial.print("Cnt1: ");  
        Serial.print(counterV);
        Serial.print(" Cnt2: ");  
        Serial.println(counterH);
      }
      
      if (counter == 10) {
        counterV = 0;
        counterH = 0;
        counter  = 0;
      }
    }
