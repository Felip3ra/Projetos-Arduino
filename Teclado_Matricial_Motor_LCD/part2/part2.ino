char recebe;
short invert=0,controle=1;
int valor=0;

void motor(char rot){
  switch(rot){
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
          valor += 1 * 100;
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
          valor += 2 * 100;
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
          valor += 3 * 100;
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
          valor += 4 * 100;
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
          valor += 5 * 100;
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
          valor += 6 * 100;
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
          valor += 7 * 100;
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
          valor += 8 * 100;
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
          valor += 9 * 100;
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
  
    
  bool ct = true;   
  if(controle == 4){
    do{
      if(digitalRead(10)==1){
        controle = 1;
        ct = false;
        valor=0;
        analogWrite(5,valor);
      }
      else{
        digitalWrite(13,HIGH);
        analogWrite(5,valor);
        
      }
    }while(ct);
      
    
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  Serial.begin(9600);
  while(!Serial);
  digitalWrite(2,OUTPUT);
  digitalWrite(6,OUTPUT);
}

void loop() 
{
  while(Serial.available() > 0){
    
    recebe = Serial.read();

    if(recebe == 'a'){
      
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        delay(500);
        digitalWrite(2,HIGH);
        digitalWrite(6,HIGH);
    }
      
      else if(recebe == 'h'){
        digitalWrite(2,LOW);
        digitalWrite(6,LOW);
        delay(500);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        
      }
      else if(recebe == 'p'){
        digitalWrite(2,LOW);
        digitalWrite(6,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
      }
      else{
      motor(recebe);
      }
      
    

  }
  
  
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    
    if(digitalRead(7)== 1){ while(digitalRead(7)==1); Serial.write('1');  }
    else if(digitalRead(8)== 1){ while(digitalRead(8)==1); Serial.write('4');  }
    else if(digitalRead(9)== 1){ while(digitalRead(9)==1); Serial.write('7');  }
    else if(digitalRead(10)== 1){ while(digitalRead(10)==1); Serial.write('a');  }
    
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    
    if(digitalRead(7)== 1){ while(digitalRead(7)==1); Serial.write('2');  }
    else if(digitalRead(8)== 1){ while(digitalRead(8)==1); Serial.write('5');  }
    else if(digitalRead(9)== 1){ while(digitalRead(9)==1); Serial.write('8');  }
    else if(digitalRead(10)== 1){ while(digitalRead(10)==1); Serial.write('h');  }
    
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
    
    if(digitalRead(7)== 1){ while(digitalRead(7)==1); Serial.write('3');  }
    else if(digitalRead(8)== 1){ while(digitalRead(8)==1); Serial.write('6');  }
    else if(digitalRead(9)== 1){ while(digitalRead(9)==1); Serial.write('9');  }
    else if(digitalRead(10)== 1){ while(digitalRead(10)==1); Serial.write('p');  }
    
    
}
