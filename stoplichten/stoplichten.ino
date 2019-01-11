
  //In een array zit een array. Eerst wordt de GND pin gegeven, dan die voor het groene LED,
  //Daarna voor het rode LED.
  //Bijv stoplicht 3 heeft GND-pin = GND, RLEd-pin = 5 en GLED-pin = 8:
  //stoplicht[2][0] = 5, stoplicht[2][1] = 8
  int stoplicht[4][2] = {
    {3, 2},   //Stoplict 1
    {5, 4},   //Stoplicht 2
    {7, 6},   //Stoplicht 3
    {9, 8}};  //Stoplicht 4

  //Alle pin-getallen:
  int pins[8] = {stoplicht[0][0], stoplicht[0][1], stoplicht[1][0], stoplicht[1][1], stoplicht[2][0], stoplicht[2][1], stoplicht[3][0], stoplicht[3][1]};

  
  //We willen alle pins out.
  int outMin = 2; // Lowest input pin
  int outMax = 9; // Highest input pin

void setup() {
  Serial.begin(115200);
  
  for(int i = outMin; i < outMax; i++) {
    pinMode(i, OUTPUT);
  }

  for(int k = 0; k < sizeof(pins); k++) {
  Serial.println(pins[k]);
  }

}

void loop() {
  for (int j = outMin; j < outMax; j++) {
    if (j > outMax) {
      j = outMin;
    }
    pinMode(j, HIGH);
    delay(1000);
    pinMode(j, LOW);
   }
}
