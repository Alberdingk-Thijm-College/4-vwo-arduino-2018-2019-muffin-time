  //In een array zit een array. Eerst wordt de GND pin gegeven, dan die voor het groene LED,
  //Daarna voor het rode LED.
  //Bijv stoplicht 3 heeft GND-pin = GND, RLEd-pin = 5 en GLED-pin = 8:
  //stoplicht[2][0] = 5, stoplicht[2][1] = 8
  int stoplicht[4][2] = {
    {3, 2},   //Stoplict 1
    {5, 4},   //Stoplicht 2
    {7, 6},   //Stoplicht 3
    {9, 8}};  //Stoplicht 4

  //Alle pin-getallen (gesorteerd van laag naar hoog):
  int pins[8] = {stoplicht[0][1], stoplicht[0][0], stoplicht[1][1], stoplicht[1][0], stoplicht[2][1], stoplicht[2][0], stoplicht[3][1], stoplicht[3][0]};
  int pinsRood[4] = {stoplicht[0][0], stoplicht[1][0], stoplicht[2][0], stoplicht[3][0]};


  //We willen alle pins out.
  int outMin = 2; // Lowest input pin
  int outMax = 9; // Highest input pin

void setup() {
  Serial.begin(115200);
//  pinMode(3, OUTPUT);


//Alle pins op output:
  for(int i = 0; i <= sizeof(pins); i++) {
    pinMode(pins[i], OUTPUT);
    Serial.println(i);
  }
  
  
}

void loop() {

//  Loop door alle stoplichten:
  for (int j = outMin; j <= outMax; j++) {
    if (j > outMax) {
      j = outMin;
    }
    Serial.println(j);
    digitalWrite(j, HIGH);
    delay(1000);
    digitalWrite(j, LOW);
   }

  
}
