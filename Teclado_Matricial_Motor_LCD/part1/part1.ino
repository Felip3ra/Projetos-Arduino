
short pos=0;
char receb;
short termino=0;
short control=0;
char aux;

// informacao, comando/letra
void envia(char letra,boolean tipo)
{
boolean valor;



digitalWrite(11,LOW); //enable=0
//define rs=0->comando ou rs=1->letra
digitalWrite(10,tipo);



//loop, contagem dos pinos
for(int i=2; i<10; i++)
{
//desmebra em valor o bit0 de letra
valor=(boolean)(letra & 0B00000001);
digitalWrite(i,valor);
letra=letra>>1; //desloca 1 bit a direita
}
digitalWrite(11,HIGH); //E
delay(2);
digitalWrite(11,LOW); //E
delay(2);
}



void texto(char *frase)
{
while(*frase!=0)
{
envia(*frase,1);
frase++;
}
}



void posicao(short pos)
{
pos=pos | 0B10000000; //compatibiliza posicao do display
envia(pos,0);
}
void inicializa()
{
delay(20);
envia(0B00111000,0);
envia(0B00001111,0);
envia(0B00000001,0);
envia(0B00000110,0);
}
void setup()
{
for(int i=2;i<13;i++)
{ pinMode(i,OUTPUT); }

pinMode(15,INPUT);

inicializa();
Serial.begin(9600);
while(!Serial);

texto("PWM:");
posicao(64);
texto("ROT: AH");
posicao(4);
}



void loop()
{
 
    
  while(Serial.available()>0)
    {
      
      receb = Serial.read();
      
        if(termino == 3){
        posicao(4);
        termino=0;
      }

      if(receb == 'a'){
        if(aux == 'p'){
            posicao(69);
            texto(" ");
            posicao(70);
            texto(" ");
            posicao(71);
            texto(" ");
            posicao(72);
            texto(" ");
            posicao(73);
            texto(" ");
            posicao(74);
            texto(" ");
            aux = ' ';
          }
            posicao(69);
            texto("A");
            posicao(70);
            texto("H");
            posicao(4);
            Serial.write(receb);
      }
      else if(receb == 'h'){
        if(aux == 'p'){
            posicao(69);
            texto(" ");
            posicao(70);
            texto(" ");
            posicao(71);
            texto(" ");
            posicao(72);
            texto(" ");
            posicao(73);
            texto(" ");
            posicao(74);
            texto(" ");
            aux = ' ';
          }
            posicao(69);
            texto("H");
            posicao(70);
            texto(" ");
            posicao(4);
            Serial.write(receb);
      }
      else if(receb == 'p'){
            posicao(69);
            texto("Parado");
            posicao(4);
            aux = 'p';
            Serial.write(receb);
      }
      else{
            envia(receb,1);
            Serial.write(receb);
            termino++;
            digitalWrite(12,HIGH);
      }
        /*
        if(receb == 'i'){
          if(aux == 'p'){
            posicao(69);
            texto(" ");
            posicao(70);
            texto(" ");
            posicao(71);
            texto(" ");
            posicao(72);
            texto(" ");
            posicao(73);
            texto(" ");
            posicao(74);
            texto(" ");
          
          }

          Serial.write(105);
          if(control%2 == 0){
            posicao(69);
            texto("H");
            posicao(70);
            texto(" ");
            posicao(4);
            control++;
          }
          else{
            posicao(69);
            texto("A");
            posicao(70);
            texto("H");
            posicao(4);
            control=0;
          }
        }
      else if(receb != 'i' && receb != 'p'){
        
          envia(receb,1);
          Serial.write(receb);
           termino++;
           digitalWrite(12,HIGH);   
      }
      else if(receb == 'p'){
        posicao(69);
        texto("Parado");
        posicao(4);
        aux = 'p';
      }
       */ 
        
        
      }
      
      
        
     
     
      
  
  }
  
