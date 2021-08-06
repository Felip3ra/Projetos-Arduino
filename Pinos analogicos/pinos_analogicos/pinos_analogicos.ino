int recebe;

void setup() {
  
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  
  recebe = analogRead(A0);

  if(recebe > 40 && recebe < 42)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13, LOW);
  }
  /*
  if(recebe < 327)
  {
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }

  else if(recebe >= 327 && recebe < 656)
  {
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  
  else if(recebe > 655)
  {
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  */
}
