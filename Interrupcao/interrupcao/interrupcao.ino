boolean estado=0;
short aciona=0;
void muda()
{
  estado=!estado;
}
void muda1()
{
  if(aciona>2){aciona=0;}
  else{aciona++;}
}

void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(2),muda,RISING);
  //attachInterrupt(digitalPinToInterrupt(2),muda,FALLING);
  //o arduino UNO aceita interrupção apenas no 2 e no 3
  attachInterrupt(digitalPinToInterrupt(2),muda,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),muda1,RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,estado);
  switch(aciona)
  {
    case 0:
    {
      digitalWrite(12,LOW);break;
    }
    case 1:
    {
      digitalWrite(12,HIGH);delay(300);digitalWrite(12,LOW);delay(300);
      break;
    }
    case 2:
    {
      digitalWrite(12,HIGH);delay(700);
      digitalWrite(12,HIGH);delay(700);
      break;
    }
    case 3:
    {
      digitalWrite(12,HIGH);delay(1200);
      digitalWrite(12,HIGH);delay(1200);
      digitalWrite(12,HIGH);delay(1200);
      break;
    }
  }
}
