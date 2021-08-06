#include<LiquidCrystal.h>

LiquidCrystal lcd(10,11,7,8,9,12);

/*

Nome: Felipe Santana Santos

Este código foi escrito por Felipe Santana Santos.
Disponibilizo esse código para estudos e projetos internos!
*/

char recebe;
int valor=0;
short controle=1,aux=0;

void mot(char n){
  switch(n){
      case '0':
            if(controle==1){
              valor = 0*100;
            }
            else if(controle==2){
              valor += 0*10;
            }
            else if(controle==3){
              valor += 0;
            }
            controle++;
            break;
       case '1':
            if(controle==1){
              valor = 1*100;
            }
            else if(controle==2){
              valor += 1*10;
            }
            else if(controle==3){
              valor += 1;
            }
            controle++;
            break;

         case '2':
            if(controle==1){
              valor = 2*100;
            }
            else if(controle==2){
              valor += 2*10;
            }
            else if(controle==3){
              valor += 2;
            }
            controle++;
            break;

         case '3':
            if(controle==1){
              valor = 3*100;
            }
            else if(controle==2){
              valor += 3*10;
            }
            else if(controle==3){
              valor += 3;
            }
            controle++;
            break;

         case '4':
            if(controle==1){
              valor = 4*100;
            }
            else if(controle==2){
              valor += 4*10;
            }
            else if(controle==3){
              valor += 4;
            }
            controle++;
            break;

         case '5':
            if(controle==1){
              valor = 5*100;
            }
            else if(controle==2){
              valor += 5*10;
            }
            else if(controle==3){
              valor += 5;
            }
            controle++;
            break;
       case '6':
            if(controle==1){
              valor = 6*100;
            }
            else if(controle==2){
              valor += 6*10;
            }
            else if(controle==3){
              valor += 6;
            }
            controle++;
            break;

         case '7':
            if(controle==1){
              valor = 7*100;
            }
            else if(controle==2){
              valor += 7*10;
            }
            else if(controle==3){
              valor += 7;
            }
            controle++;
            break;

         case '8':
            if(controle==1){
              valor = 8*100;
            }
            else if(controle==2){
              valor += 8*10;
            }
            else if(controle==3){
              valor += 8;
            }
            controle++;
            break;

         case '9':
            if(controle==1){
              valor = 9*100;
            }
            else if(controle==2){
              valor += 9*10;
            }
            else if(controle==3){
              valor += 9;
            }
            controle++;
            break;
    }
    if(controle == 4){
      controle=1;
    }
}

void setup() {
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  while(!Serial);
 
  lcd.print("PWM:");
  lcd.setCursor(0,1);
  lcd.print("ROT:AH");
  lcd.setCursor(4,0);
  digitalWrite(2,HIGH);
  digitalWrite(6,HIGH);
}

void loop() {
  if(Serial.available()>0){
    recebe = Serial.read();
    if(recebe != 'a' && recebe != 'h' && recebe != 'p'){
    lcd.write(recebe);
    mot(recebe);
    aux++;
    }
    else if(recebe == 'a'){
      lcd.setCursor(4,1);
      lcd.print("AH");
      lcd.setCursor(4,0);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(500);
      digitalWrite(2,HIGH);
      digitalWrite(6,HIGH);
    }
    else if(recebe == 'h'){
      lcd.setCursor(4,1);
      lcd.print("H ");
      lcd.setCursor(4,0);
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
    
  }
  if(aux == 3){
    lcd.setCursor(4,0);
    aux=0;
  }
  analogWrite(5,valor);

}
