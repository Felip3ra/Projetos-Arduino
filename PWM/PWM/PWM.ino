int valor =0,recebe=0;
float temp;
int t1=0,t2=0;
void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(2,INPUT);
pinMode(3,INPUT);
}

void loop() {

  recebe = analogRead(A0);

  if(digitalRead(2) == 1)
  {
    while(digitalRead(2)==1);
    if(valor>0)
    {
      valor-=10;
    }
  }

  if(digitalRead(3) == 1)
  {
    while(digitalRead(3)==1);
    if(valor<250)
    {
      valor+=10;
    }
  }

  analogWrite(5,valor);
  temp = ((5 * (float)recebe)/1023)*100;

  if(temp>20)
  {
    if(t1<temp)
    {
      valor+=10;
      t1++;
    }
    if(t1> temp)
    {
      valor-=10;
    }
  }
}
