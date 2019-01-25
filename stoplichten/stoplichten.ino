  // and             &&
  // and_eq          &=
  // bitand          &
  // bitor           |
  // not             !
  // not_eq          !=
  // or              ||
  // or_eq           |=
  // xor             ^
  // xor_eq          ^=


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
  int pins[8] = {stoplicht[0][0], stoplicht[0][1], stoplicht[1][0], stoplicht[1][1], stoplicht[2][0], stoplicht[2][1], stoplicht[3][0], stoplicht[3][1]};
  int pinsRood[4] = {stoplicht[0][0], stoplicht[1][0], stoplicht[2][0], stoplicht[3][0]};
  int pinsGroen[4] = {stoplicht[0][1], stoplicht[1][1], stoplicht[2][1], stoplicht[3][1]};
  // int pinsMode[8] = {0,0,0,0,0,0,0,0};

  //Deze array heft de volgorde van pinsGroen
  int pinsGroenMode[4] = {0,0,0,0};
  //Deze array heeft de volgorde van pinsRood
  int pinsRoodMode[4] = {0,0,0,0};

  //We willen alle pins out.
  int outMin = 2; // Lowest input pin
  int outMax = 9; // Highest input pin

void setup() {
  Serial.begin(115200);

  //We zetten niet gelijk alle pins op output, want dan verschijnt er een bug.


}

void loop() {

//  Loop door alle stoplichten:
//  for (int j = outMin; j <= outMax; j++) {
//    if (j > outMax) {
//      j = outMin;
//    }
//    Serial.println(j);
//    digitalWrite(j, HIGH);
//    delay(1000);
//    digitalWrite(j, LOW);
//   }

  for (int t = 0; t <=  3; t++) {
    pinMode(pinsRood[t], OUTPUT);
    digitalWrite(pinsRood[t], HIGH);
    pinsRoodMode[t] = 1;
  }

//Check of een groene stoplicht aan is of niet
  for (int p = 0; p <= 3; p++) {
    //Als er een stoplicht groen is, zet dan de corresponderende rode pin uit. Groene stoplichten > rode stoplichten
    if (pinsGroenMode[p] == 1) {
      pinsRoodMode[p] == 0;
      pinMode(pinsRood[p], OUTPUT);
      digitalWrite(pinsRood[p], LOW);
      //digitalWrite rood

//Als we een groen stoplicht hebben gevonden die aan is, zetten we de andere groene stoplichten uit
      for (int z = 0; z <= 3; z++) {
        if (z != p) {
          pinsGroenMode[z] = 0;
          pinMode(pinsGroen[z], INPUT);
          digitalWrite(pinsGroen[z], LOW);
          //digitalWrite groen
        }
      }
    }
  }

}
