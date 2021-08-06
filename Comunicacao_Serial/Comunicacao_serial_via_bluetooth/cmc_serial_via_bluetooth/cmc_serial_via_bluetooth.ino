char recebido;
// um conjunto de 100 posições
char recebidos[100];
//conjunto de letras(texto) 
String _final;
short pos=0; //referencia de posição
boolean termino=0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //aguarda porta serial ser inicializada
  while(!Serial);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {

  
    //enquanto estiver recebendo algo na porta serial
    // Serial.available espere o usuario digitar um "valor" que seja maior que 0, no caso um caractere
    while(Serial.available()>0)
    {
      recebidos[pos] = Serial.read();
      termino=1;
      pos++;
      //verifica se recebeu na serial um ENTER
    }
    recebidos[pos] =0; pos=0;
    _final = recebidos;
    if(termino==1)
    {
      //Serial.write(recebidos);
      termino=0;
      
      if(_final == "Liga1")
      {
        digitalWrite(4,HIGH);
        Serial.write("Led1 Ligado");
        
      }
      if(_final == "Desliga1")
      {
        digitalWrite(4,LOW);
        Serial.write("Led1 Desligado");
        
      }
      if(_final == "Liga2")
      {
        digitalWrite(3,HIGH);
        
      }
      if(_final == "Desliga2")
      {
        digitalWrite(3,LOW);
        
      }
      if(_final == "Pisca1")
      {
        digitalWrite(4,HIGH);delay(500);
        digitalWrite(4,LOW);delay(500);
        digitalWrite(3,HIGH);delay(500);
        digitalWrite(3,LOW);delay(500);
        
      }
      
    }
  
  
  
  /*

 while(termino==0)
 {
  recebidos[pos] = Serial.read();
  if(recebidos[pos] > 0)
  {
    //verifica se recebeu na serial a letra !
    if(recebidos[pos] == '!')
    {
      recebidos[pos] =0;pos=0;
      Serial.println(recebidos);
      termino=1;
    }
    else
    {
      pos++;
    }
  }
 }
 termino=0;
 */


 
 
 //LÊ CARACTERE POR CARACTERE
   /*
  //guarda em recebido, o valor lido da porta serial
  recebido = Serial.read();
  if(recebido > 0)
  {
    Serial.write(recebido);
    
  }
  _final = recebido;
  if(_final == "L")
  {
    digitalWrite(4,HIGH);
  }
  if(_final == "D")
  {
    digitalWrite(4,LOW);
  }
  */

  
  
  delay(100);
  
}
