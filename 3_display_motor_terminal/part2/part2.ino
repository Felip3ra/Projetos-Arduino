char recebe;
int valor =0;
short controle = 1,inverte=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(13,INPUT);
  Serial.begin(9600);
  while(!Serial);
  digitalWrite(2,HIGH);
  digitalWrite(6,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available() > 0){

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
  }
  if(digitalRead(13) == 1){
    if(inverte%2 == 0){
      digitalWrite(2,LOW);
      digitalWrite(6,LOW);
      delay(500);
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      inverte++;
    }
    else{
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      delay(500);
      digitalWrite(2,HIGH);
      digitalWrite(6,HIGH);
      inverte=0;
    }
  }
  analogWrite(5,valor);
}
