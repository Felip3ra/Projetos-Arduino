/*
//reserva espaço para todas as letras do display
char memoria[129];
//referencia de posição dentro do vetor memoria
short pos=0;
short linha=0; //sinaliza linha 0- linha1 , 1-linha2
char informacao[17]; //guarda uma linha
short pinf=0; //posicao da informacao
char recebe;



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

void setup() {
  // put your setup code here, to run once:
  pinMode(0,INPUT);
  for(int i=1;i<12;i++)
  { pinMode(i,OUTPUT); }
  pinMode(12,INPUT);
  inicializa();
  texto("Ola");
  Serial.begin(9600);
  while(!Serial);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available()>0)
{
recebe=Serial.read(); //recebe letra da serial
//se enter apertado
if(recebe==13)
{
if(linha==0){ pos=64 ; linha=1;}
else { pos=0; linha=0; }
}
else
{
//caso a posicao estrapolar as 16 letras
if(pos==16+(linha*64))
{
for(short i=0+(linha*64);i<16+(linha*64);i++)
{ memoria[i]=memoria[i+1]; }
memoria[15+(linha*64)]=recebe; pos=15+(linha*64);
}
memoria[pos]=recebe;
pos++;
}

//mostra informações na primeira linha
//posicao primeira letra primeira linha do display
posicao(0);
for(short i=0;i<16;i++)
{
//envia ao display letra do vetor memoria
// de acordo co o valor de i
envia(memoria[i],1);
}
//mostra informações na segunda linha
//posicao primeira letra segunda linha do display
posicao(64); //64 = 0x40
for(short i=64;i<80;i++)
{
//envia ao display letra do vetor memoria
// de acordo co o valor de i
envia(memoria[i],1);
}
}
  
  if(digitalRead(12)== 1)
  {
    envia(1,0);
  }
 
}
*/

 
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(10, 11,2,3,4,5,6,7,8,9);

char recebido;
// um conjunto de 100 posições
char recebidos[100];
//conjunto de letras(texto) 
String _final;
int control=0;
short pos=0; //referencia de posição
boolean termino=0;
 
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  while(!Serial);
}
 
void loop()
{
  while(Serial.available()>0)
    {
      recebidos[pos] = Serial.read();
      //verifica se recebeu na serial um ENTER
      if(recebidos[pos] == 13)
      {
        recebidos[pos] =0;pos=0;control++; 
        termino=1;
        if(control%2 == 0)
        {
          lcd.setCursor(0,1);
        }
        else
        {
          lcd.setCursor(0,0);
        }
 
      }
      else
      {
        pos++;
      }
    }
    if(termino==1)
    {
      lcd.print(recebidos);
      termino=0;
      _final = recebidos;
      
      
    }
  if(digitalRead(12)==1)
  {
    //Limpa a tela
    lcd.clear();
  }
}
