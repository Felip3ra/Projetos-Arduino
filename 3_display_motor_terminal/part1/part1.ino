char recebe;
short controle=1;
int valor=0;


void disp(int num){
  switch(num)
  {
      case 0:
         { digitalWrite(8,LOW);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,HIGH); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }

      case 1:
          { digitalWrite(8,LOW);  //G
          digitalWrite(7,LOW); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,LOW); //A
          break;
         }

      case 2:
           { digitalWrite(8,HIGH);  //G
          digitalWrite(7,LOW); //F
          digitalWrite(6,HIGH); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,LOW); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }


      case 3:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,LOW); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }

       case 4:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,LOW); //A
          break;
         }


       case 5:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,LOW); //B
          digitalWrite(2,HIGH); //A
          break;
         }


       case 6:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,HIGH); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,LOW); //B
          digitalWrite(2,HIGH); //A
          break;
         }


       case 7:
          { digitalWrite(8,LOW);  //G
          digitalWrite(7,LOW); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,LOW); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }


       case 8:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,HIGH); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }


        case 9:
          { digitalWrite(8,HIGH);  //G
          digitalWrite(7,HIGH); //F
          digitalWrite(6,LOW); //E
          digitalWrite(5,HIGH); //D
          digitalWrite(4,HIGH); //C
          digitalWrite(3,HIGH); //B
          digitalWrite(2,HIGH); //A
          break;
         }
         
  }
}
void mostra(int val){

  short centena,dezena,unidade;
  centena= val/100;
  dezena = (val%100)/10;
  unidade=val%10;
  disp(centena); digitalWrite(9,HIGH);
  delay(200);
  digitalWrite(9,LOW);
  disp(dezena); digitalWrite(10,HIGH);
  delay(200);
  digitalWrite(10,LOW);
  disp(unidade); digitalWrite(11,HIGH);
  delay(200);
  digitalWrite(11,LOW);
}


void setup() {
  // put your setup code here, to run once:
  for(int i=2;i < 12;i++){
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
  while(!Serial);
  disp(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    recebe = Serial.read();
    
    switch(recebe){
    case '0':
        if(controle == 1){
          valor = 0 * 100;
        }
        else if(controle == 2){
          valor += 0 * 10;
        }
        else if(controle == 3){
          valor += 0;
        }
        controle++;
        break;

     case '1':
        if(controle == 1){
          valor = 1 * 100;
        }
        else if(controle == 2){
          valor += 1 * 10;
        }
        else if(controle == 3){
          valor += 1;
        }
        controle++;
        
        break;

      case '2':
        if(controle == 1){
          valor = 2 * 100;
        }
        else if(controle == 2){
          valor += 2 * 10;
        }
        else if(controle == 3){
          valor += 2;
        }
        controle++;
        
        break;

      case '3':
        if(controle == 1){
          valor = 3 * 100;
        }
        else if(controle == 2){
          valor += 3 * 10;
        }
        else if(controle == 3){
          valor += 3;
        }
        controle++;
        break;

      case '4':
        if(controle == 1){
          valor = 4 * 100;
        }
        else if(controle == 2){
          valor += 4 * 10;
        }
        else if(controle == 3){
          valor += 4;
        }
        controle++;
        break;

       case '5':
        if(controle == 1){
          valor = 5 * 100;
        }
        else if(controle == 2){
          valor += 5 * 10;
        }
        else if(controle == 3){
          valor += 5;
        }
        controle++;
        break;

     case '6':
        if(controle == 1){
          valor = 6 * 100;
        }
        else if(controle == 2){
          valor += 6 * 10;
        }
        else if(controle == 3){
          valor += 6;
        }
        controle++;
        break;

      case '7':
        if(controle == 1){
          valor = 7 * 100;
        }
        else if(controle == 2){
          valor += 7 * 10;
        }
        else if(controle == 3){
          valor += 7;
        }
        controle++;
        break;

      case '8':
        if(controle == 1){
          valor = 8 * 100;
        }
        else if(controle == 2){
          valor += 8 * 10;
        }
        else if(controle == 3){
          valor += 8;
        }
        controle++;
        break;

      case '9':
        if(controle == 1){
          valor = 9 * 100;
        }
        else if(controle == 2){
          valor += 9 * 10;
        }
        else if(controle == 3){
          valor += 9;
        }
        controle++;
        break;

    }
      if(controle == 4){
        controle=1;
        
      }
      Serial.write(recebe);
  }
  mostra(valor);
}
