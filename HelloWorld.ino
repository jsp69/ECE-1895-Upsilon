void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2)==HIGH){
    digitalWrite(13,HIGH);
    delay(10);
    digitalWrite(13,LOW);
    delay(10);
  }else{
    digitalWrite(13,LOW);
  }
}

//Extra comment from Jash

//Ethan Vukelich Comment

//Caulen Hershman comment

