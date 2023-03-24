int upPin = 2;
int downPin = 3;
int leftPin = 4;
int rightPin = 5;
int xPin = 6;
int zPin = 7;
int selectPin = 8;
int startPin = 9;
int aPin = 10;
int sPin = 11;

void setup() {
  pinMode(upPin, INPUT_PULLUP);
  pinMode(downPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(xPin, INPUT_PULLUP);
  pinMode(zPin, INPUT_PULLUP);
  pinMode(selectPin, INPUT_PULLUP);
  pinMode(startPin, INPUT_PULLUP);
  pinMode(aPin, INPUT_PULLUP);
  pinMode(sPin, INPUT_PULLUP);
  Serial.setTimeout(100);
  Serial.begin(9600);
}

int up = 0;
int down = 0;
int left = 0;
int right = 0;
int x = 0;
int z = 0;
int a = 0;
int s = 0;
int select = 0;
int start = 0;

void loop() {
  if (digitalRead(upPin) == LOW) {
    up = (up == 1) ? 0 : 1;
    Serial.println(up);
  }
  if (digitalRead(downPin) == LOW) {
    down = (down == 1) ? 0 : 1;
    Serial.println(down);
  }
  if (digitalRead(leftPin) == LOW) {
    left = (left == 1) ? 0 : 1;
    Serial.println(left);
  }
  if (digitalRead(rightPin) == LOW) {
    right = (right == 1) ? 0 : 1;
    Serial.println(right);
  }
  if (digitalRead(xPin) == LOW) {
    x = (z == 1) ? 0 : 1;
    Serial.println(a);
  }
  if (digitalRead(zPin) == LOW) {
    z = (z == 1) ? 0 : 1;
    Serial.println(z);
  }
  if (digitalRead(selectPin) == LOW) {
    select = (select == 1) ? 0 : 1;
    Serial.println(select);
  }
  if (digitalRead(startPin) == LOW) {
    start = (start == 1) ? 0 : 1;
    Serial.println(start);
  }
    if (digitalRead(aPin) == LOW) {
    a = (a == 1) ? 0 : 1;
    Serial.println(a);
  }
    if (digitalRead(sPin) == LOW) {
    s = (s == 1) ? 0 : 1;
    Serial.println(s);
  }
  delay(10);
}
