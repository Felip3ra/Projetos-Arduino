
short valor = 0;
short anterior=-1;
void display(short num)
{
  //verifica valores da variavel num
  switch(num)
  {
      case 0:
         { digitalWrite(7,LOW);  //G
          digitalWrite(8,HIGH); //F
          digitalWrite(9,HIGH); //E
          digitalWrite(10,HIGH); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,HIGH); //A
          break;
         }

      case 1:
          { digitalWrite(7,LOW);  //G
          digitalWrite(8,LOW); //F
          digitalWrite(9,LOW); //E
          digitalWrite(10,LOW); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,LOW); //A
          break;
         }

      case 2:
           { digitalWrite(7,HIGH);  //G
          digitalWrite(8,LOW); //F
          digitalWrite(9,HIGH); //E
          digitalWrite(10,HIGH); //D
          digitalWrite(11,LOW); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,HIGH); //A
          break;
         }


      case 3:
          { digitalWrite(7,HIGH);  //G
          digitalWrite(8,LOW); //F
          digitalWrite(9,LOW); //E
          digitalWrite(10,HIGH); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,HIGH); //A
          break;
         }

       case 4:
          { digitalWrite(7,HIGH);  //G
          digitalWrite(8,HIGH); //F
          digitalWrite(9,LOW); //E
          digitalWrite(10,LOW); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,LOW); //A
          break;
         }


       case 5:
          { digitalWrite(7,HIGH);  //G
          digitalWrite(8,HIGH); //F
          digitalWrite(9,LOW); //E
          digitalWrite(10,HIGH); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,LOW); //B
          digitalWrite(13,HIGH); //A
          break;
         }


       case 6:
          { digitalWrite(7,HIGH);  //G
          digitalWrite(8,HIGH); //F
          digitalWrite(9,HIGH); //E
          digitalWrite(10,HIGH); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,LOW); //B
          digitalWrite(13,HIGH); //A
          break;
         }


       case 7:
          { digitalWrite(7,LOW);  //G
          digitalWrite(8,LOW); //F
          digitalWrite(9,LOW); //E
          digitalWrite(10,LOW); //D
          digitalWrite(11,HIGH); //C
          digitalWrite(12,HIGH); //B
          digitalWrite(13,HIGH); //A
          break;
         }


       case 8:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,HIGH); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }


        case 9:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }


         case 10:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,HIGH); //E
          digitalWrite(3,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }
  }
}

void setup() 
{
  //configura 7 pinos de uma vez
  for(int i =1; i<14;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(0,INPUT);
  

}

void loop() 
{
  valor = Serial.read();
  if(anterior!=valor)
  {
    display(valor);anterior=valor;  
  }
    
}
