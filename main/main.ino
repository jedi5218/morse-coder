#include <stack>
unsigned int signalLED=2;

void setup() {
  Serial.begin(9600);
  pinMode(signalLED,OUTPUT);
}

void loop() {
  std::stack<char> stack;
}
