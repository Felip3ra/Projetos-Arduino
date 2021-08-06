
int controle = 1;
int valor=0;
int pos=0;
int termino=0;
short mot=0;
char receb;




int transforma(char n1){
 
  
    switch(n1){
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
  /*   
  if(controle == 4){
    do{
      if(digitalRead(10)==1){
        controle = 1;
        ct = false;
        valor=0;
        analogWrite(5,valor);
      }
      else{
        digitalWrite(13,LOW);
        analogWrite(5,valor);
        
      }
    }while(ct);
      
    
  }
*/
 if(controle == 4){
    do{
      if(Serial.available() > 0){
        receb = Serial.read();
       if(receb == 'p'){
        controle = 1;
        ct = false;
        valor=0;
        analogWrite(5,valor);
        }
      }
      else{
        digitalWrite(13,LOW);
        analogWrite(5,valor);
        
      }
    }while(ct);
      
    
  }
  
}



void setup() 
{
  //configura 7 pinos de uma vez
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(10,INPUT);
  pinMode(13,OUTPUT);
  
  
  Serial.begin(9600);
  while(!Serial);
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH);
  

}

void loop() 
{
  
  char a;

    /*
    while(Serial.available()>0)
    {
      
      recebe[pos] = Serial.read();
      //verifica se recebeu na serial um ENTER
      if(digitalRead(7) == 1)
      {
        Serial.println("Recebi");
        recebe[pos] =0;pos=0; 
        termino=1; //a = transforma(recebe);
        
      }
      else
      {
        digitalWrite(13,HIGH);
        transforma(recebe[pos]);
        pos++;
         
        
      }*/
/*
      while(Serial.available()>0)
    {
      
      recebe[pos] = Serial.read();
      //verifica se recebeu na serial um ENTER
        if(recebe[0] == 'i'){
        recebe[pos] =0;pos=0;
        digitalWrite(13,HIGH);
        if(mot%2 == 0){
          
          digitalWrite(2,LOW);
          digitalWrite(8,LOW);
          delay(1000);
          digitalWrite(7,HIGH);
          digitalWrite(4,HIGH);
          mot++;
        }
        else{
          digitalWrite(7,LOW);
          digitalWrite(4,LOW);
          digitalWrite(2,HIGH);
          digitalWrite(8,HIGH);
          mot=0;
        }
      }
        else{ 
          transforma(recebe[pos]);
          pos++;
        }
        
        
        if(pos == 3){
          recebe[pos] =0;pos=0; 
          digitalWrite(13,HIGH);
        }
         
 
    }*/

    while(Serial.available()>0)
    {
      
      receb = Serial.read();
      digitalWrite(13,HIGH);
        if(receb == 105){
          
          if(mot%2 == 0){
            
            digitalWrite(2,LOW);
            digitalWrite(8,LOW);
            digitalWrite(7,HIGH);
            digitalWrite(4,HIGH);
            mot++;
          }
          else{
            digitalWrite(7,LOW);
            digitalWrite(4,LOW);
            digitalWrite(2,HIGH);
            digitalWrite(8,HIGH);
            mot=0;
          }
      }
      else{ 
          transforma(receb);
      }
        
        
    }
    
    
    
  
     
     
  
   
}
