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

  //rood = 12, groen = 11
  int voetgangerStoplichtPins[2] = {11, 12};
  int buttonPin = 10;

  int cycleMode = 1;

  //Deze array heft de volgorde van pinsGroen
  int pinsGroenMode[4] = {0,0,0,0};
  //Deze array heeft de volgorde van pinsRood
  int pinsRoodMode[4] = {0,0,0,0};

  //We willen alle pins out.
  int outMin = 2; // Lowest input pin
  int outMax = 9; // Highest input pin

  //Een array met de volgorde van de stoplichten. Welke gaat aan en welke daarna?
  int cycle[4] = {0,1,2,3};

void setup() {
  Serial.begin(115200);

  //We zetten niet gelijk alle pins op output, want dan verschijnt er een bug.

//  Zet
//  pinMode(pinsGroen[1], OUTPUT);
//  digitalWrite(pinsGroen[1], HIGH);
//  pinsGroenMode[1] = 1;


  //Eerst alle stoplichten op rood:
  //Alle rode stoplichten aan:
    for (int t = 0; t <=  3; t++) {
     pinMode(pinsRood[t], OUTPUT);
     digitalWrite(pinsRood[t], HIGH);
     pinsRoodMode[t] = 1;
    }

  
}

void checkVoetganger() {
    if (digitalRead(buttonPin) == HIGH){
    Serial.println("KNOP");
    cycleMode = 0;
    //Alles op rood en groen uit!
    digitalWrite(pinsGroen[0], LOW);
    digitalWrite(pinsGroen[1], LOW);
    digitalWrite(pinsGroen[2], LOW);
    digitalWrite(pinsGroen[3], LOW);

    digitalWrite(pinsRood[0], HIGH);
    digitalWrite(pinsRood[1], HIGH);
    digitalWrite(pinsRood[2], HIGH);
    digitalWrite(pinsRood[3], HIGH);    

    digitalWrite(voetgangerStoplichtPins[1], LOW);
    digitalWrite(voetgangerStoplichtPins[0], HIGH);

    //Voetgangerstoplicht op groen!
    delay(3 * 1000);
    digitalWrite(voetgangerStoplichtPins[0], LOW);
    digitalWrite(voetgangerStoplichtPins[1], HIGH);
    cycleMode = 1;
  }
}


void loop() {
  for (int p = 0; p <= 3; p ++) {
    pinMode(pinsRood[p], OUTPUT);
    pinMode(pinsGroen[p], OUTPUT);
    pinMode(voetgangerStoplichtPins[0], OUTPUT);
    pinMode(voetgangerStoplichtPins[1], OUTPUT);
  }

  if (cycleMode == 1){
//    digitalWrite(voetgangerStoplichtPins[1], HIGH);
    digitalWrite(voetgangerStoplichtPins[1], HIGH);

    checkVoetganger();
    
    digitalWrite(pinsGroen[0], HIGH);
    digitalWrite(pinsRood[0], LOW);
    delay(1000);
    digitalWrite(pinsGroen[0], LOW);
    digitalWrite(pinsRood[0], HIGH);

    checkVoetganger();
  
    digitalWrite(pinsGroen[1], HIGH);
    digitalWrite(pinsRood[1], LOW);
    delay(1000);
    digitalWrite(pinsGroen[1], LOW);
    digitalWrite(pinsRood[1], HIGH);

    checkVoetganger();

    digitalWrite(pinsGroen[2], HIGH);
    digitalWrite(pinsRood[2], LOW);
    delay(1000);
    digitalWrite(pinsGroen[2], LOW);
    digitalWrite(pinsRood[2], HIGH);

    checkVoetganger();

    digitalWrite(pinsGroen[3], HIGH);
    digitalWrite(pinsRood[3], LOW);
    delay(1000);
    digitalWrite(pinsGroen[3], LOW);
    digitalWrite(pinsRood[3], HIGH);
  }
}
