//VARIAVEIS DE CONTROLE
int controle=0;
int inverte=0;
int controle_2=0,controle_3=0;

void setup() {
  //CONFIGURAÇÃO DE PINOS
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  
  //ROTAÇÃO INICIAL:
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

    //INVERTE A ROTAÇÃO
    if(digitalRead(10)== 1)
    {
      while(digitalRead(10)==1);
      if(inverte % 2 == 0)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,HIGH);
        controle_3=1;
      }
      else
      {
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,LOW);
        controle_3=0;
      }
      inverte++;
    }

    //PARA O MOTOR
    if(digitalRead(11)== 1)
    {
      while(digitalRead(11)==1);
      if(controle_2 % 2 == 0)
      {
        digitalWrite(3,HIGH);
        digitalWrite(4,LOW);
        digitalWrite(8,HIGH);
        digitalWrite(9,LOW);
      }
      else
      {
        if(controle_3==1)
        {
          
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          digitalWrite(8,LOW);
          digitalWrite(9,HIGH);
      
        }
        else if(controle_3==0)
        {
          
          digitalWrite(3,LOW);
          digitalWrite(4,HIGH);
          digitalWrite(8,HIGH);
          digitalWrite(9,LOW);
          
        }
        
      }
      controle_2++;
      
    }

    //AUMENTA A ROTAÇÃO DO MOTOR
    if(digitalRead(13)== 1)
    {
      while(digitalRead(13)==1);
      if(controle <= 235)
      {
        controle+=20;
        
      }
      
    }

    //DIMINUI A ROTAÇÃO DO MOTOR
    if(digitalRead(12)== 1)
    {
      while(digitalRead(12)==1);
      if(controle > 20)
      {
        controle-=20;
      }
    }
    //PWM
    analogWrite(5,controle);
}
