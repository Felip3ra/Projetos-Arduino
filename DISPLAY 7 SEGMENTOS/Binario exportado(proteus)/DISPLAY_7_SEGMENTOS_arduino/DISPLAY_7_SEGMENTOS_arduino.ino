
short valor = 0;

void display(short num)
{
  //verifica valores da variavel num
  switch(num)
  {
      case 0:
         { digitalWrite(0,LOW);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,HIGH); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }

      case 1:
          { digitalWrite(0,LOW);  //G
          digitalWrite(1,LOW); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,LOW); //A
          break;
         }

      case 2:
           { digitalWrite(0,HIGH);  //G
          digitalWrite(1,LOW); //F
          digitalWrite(2,HIGH); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,LOW); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }


      case 3:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,LOW); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
          break;
         }

       case 4:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,LOW); //A
          break;
         }


       case 5:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,LOW); //B
          digitalWrite(6,HIGH); //A
          break;
         }


       case 6:
          { digitalWrite(0,HIGH);  //G
          digitalWrite(1,HIGH); //F
          digitalWrite(2,HIGH); //E
          digitalWrite(3,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,LOW); //B
          digitalWrite(6,HIGH); //A
          break;
         }


       case 7:
          { digitalWrite(0,LOW);  //G
          digitalWrite(1,LOW); //F
          digitalWrite(2,LOW); //E
          digitalWrite(3,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(5,HIGH); //B
          digitalWrite(6,HIGH); //A
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
  for(int i =0; i<7;i++)
  {
    pinMode(i,OUTPUT);
  }
  

}

void loop() 
{
  //display com botão
    if(digitalRead(7) == 1)
    {
      while(digitalRead(7) == 1);
   
        if(valor < 10)
        {
          
          valor++;
        }
        else
        {
          valor = 0;
        }   
    }
    display(valor);
  
  /*  
   *   Display sem botão
   *   for(int x=0; x<11;x++)
    {
      display(x);
      delay(500);
    }
    */
  
}
