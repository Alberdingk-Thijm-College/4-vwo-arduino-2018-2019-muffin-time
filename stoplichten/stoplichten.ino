void setup() {
  //In een array zit een array. Eerst wordt de GND pin gegeven, dan die voor het groene LED,
  //Daarna voor het rode LED.
  //Bijv stoplicht 3 heeft GND-pin = 1, RLEd-pin = 5 en GLED-pin = 8:
  //stoplicht[2][0] = 1, stoplicht[2][1] = 5 en stoplicht[2][2] = 8
  int stoplicht[] = {
    {GND, 3, 2},   //Stoplict 1
    {GND, 5, 4},   //Stoplicht 2
    {GND, 7, 6},   //Stoplicht 3
    {GND, 9, 8}};  //Stoplicht 4

  //We willen alle pins out.
  int outMin = 2; // Lowest input pin
  int outMax = 9; // Highest input pin
    for(int i=inMin; i<=inMax; i++) {
    pinMode(i, OUTPUT);
  }

  for (int j = outMin; j= < outMax; j++) {
    if (j > outMax) {
      j = outMin;
    }
    pinMode(j, HIGH);
    delay(1000);
    pinMode(j, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
