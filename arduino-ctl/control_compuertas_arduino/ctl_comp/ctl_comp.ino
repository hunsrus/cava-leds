#define pinA 2
#define pinB 3
#define pinC 4
int entrada = 0;

void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0)
  {
    entrada = (int)Serial.read();
    switch (entrada) {
      case 1:
        digitalWrite(pinA, HIGH);
      break;
      case 2:
        digitalWrite(pinA, LOW);
      break;
      case 3:
        digitalWrite(pinB, HIGH);
      break;
      case 4:
        digitalWrite(pinB, LOW);
      break;
      case 5:
        digitalWrite(pinC, HIGH);
      break;
      case 6:
        digitalWrite(pinC, LOW);
      break;
      default:
      break;
    }
  }
  delay(100);
}
