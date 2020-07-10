int buzzerPin = 11;
int buzzerIntensity = 4; // range: 0 to 255
unsigned int dotOffset = 50;
unsigned int lineOffset = 200;
unsigned int signalOffset = 300;
unsigned int letterOffset = 1000;
unsigned int wordlOffset = 1500;


//char s[] = "...";

//{'s', '.', '.', '.'}
char alphabet[][6] = {
  "a.-",
  "b-...",
  "c-.-.",
  "d-..",
  "e.",
  "f..-.",
  "g--.",
  "h....",
  "i..",
  "j.---",
  "k-.-"
  "l.-..",
  "m--",
  "n-.",
  "o---",
  "p.--.",
  "q--.-",
  "r.-.",
  "s...",
  "t-",
  "u..-",
  "v...-",
  "w.--",
  "x-..-",
  "y-.--",
  "z--..",
};

void dot() {
  analogWrite(buzzerPin, buzzerIntensity);
  delay(dotOffset);
  analogWrite(buzzerPin, 0);
  delay(signalOffset);
}

void line() {
  analogWrite(buzzerPin, buzzerIntensity);
  delay(lineOffset);
  analogWrite(buzzerPin, 0);
  delay(signalOffset);
}



void morseChar(char x) {
  int i = 0;
  while (alphabet[i][0] != x) {
    i++;
  }

  int j = 1;
  while (alphabet[i][j] != '\0') {
    if (alphabet[i][j] == '.') dot();
    else if (alphabet[i][j] == '-') line();
    j++;
  }
}

//--------------------------------------------------------------------------------------------------
void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);

  //String slowo = "chuj";
  /*
    int k = 0;
    while (slowo[k] != '\0'){
      morseChar(slowo[k]);
      k++;
      delay(letterOffset);
    }*/

}

String wyraz;

void loop() {
  if (Serial.available() > 0) {
    wyraz = Serial.readString();
    int k = 0;
    while (wyraz[k] != '\0') {
      morseChar(wyraz[k]);
      k++;
      delay(letterOffset);
    }
  }
}
