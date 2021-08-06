
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
  for(int i =0; i<14;i++)
  {
    pinMode(i,OUTPUT);
  }
  

}

void loop() 
{
  
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    
    if(digitalRead(7)== 1){ display(1);  }
    if(digitalRead(8)== 1){ display(4);  }
    if(digitalRead(9)== 1){ display(7);  }
    if(digitalRead(10)== 1){ display();  }
    
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    
    if(digitalRead(7)== 1){ display(2);  }
    if(digitalRead(8)== 1){ display(5);  }
    if(digitalRead(9)== 1){ display(8);  }
    if(digitalRead(10)== 1){ display();  }
    
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    
    if(digitalRead(7)== 1){ display(3);  }
    if(digitalRead(8)== 1){ display(6);  }
    if(digitalRead(9)== 1){ display(9);  }
    if(digitalRead(10)== 1){ display();  }
    
    
}
