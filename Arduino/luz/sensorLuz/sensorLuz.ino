int entrada = A0;
double val=0;
void setup(){
  Serial.begin(9600);
}

void loop() {
  val = analogRead (entrada) ;
  Serial.println(val);
  delay(2000);
}
