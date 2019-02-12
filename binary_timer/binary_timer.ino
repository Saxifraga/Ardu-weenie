int ledPins[] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12  //select output pins
};
int pinVals[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0  // store output values for all LEDs; initialize all values low
};

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  for (int thisPin = 1; thisPin < 13; thisPin++){
    pinMode(ledPins[thisPin], OUTPUT);  //initialize all the pins as outputs
  } 
}
 
  
void loop() {
  // put your main code here, to run repeatedly:
  thisLoop(12); //there are only 12 pins

}


void fourSecLoop(){  //the base case
  for (int i = 1; i < 3; i++){
    writeAll(pinVals, ledPins);
    for (int j = 1; j< i+1; j++){
      pinVals[j] = toggle(pinVals[j]);
    }
  } 
}

void thisLoop(int n){ 
  if (n >2){
    thisLoop(n-1);  //recursively call the previous loop twice
    thisLoop(n-1);
    pinVals[n] = toggle(pinVals[n]);  //then toggle the newest LED
  }
  else{
    fourSecLoop();  //for the last loop call the base case
  }
}


void writeAll (int pinVals[], int ledPins[]){
  for (int i = 1; i<13; i++){
    digitalWrite(ledPins[i], pinVals[i]);
  }
  delay(1000);  // 1 sec
}

int toggle(int led){  //toggle the LED output setting between HIGH (1) and LOW (0)
  if(led==0){
    return 1;
  }
  else{
    return 0;
  }
}

//void sixteenSecLoop(){
//  eightSecLoop();
//  eightSecLoop();
//  pinVals[4] = toggle(pinVals[4]); 
//}
//void eightSecLoop(){
//  for (int i = 1; i < 3; i++){
//      for (int j = 1; j < 3; j++){
//        writeAll(pinVals, ledPins);
//        for (int k = 1; k< j+1; k++){
//          pinVals[k] = toggle(pinVals[k]);
//        }
//    } 
//  }
//  pinVals[3] = toggle(pinVals[3]);
//}

