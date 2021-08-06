short memoria[62][5];
short recebe;


void matriz()
{
  //numero 0 
  memoria[0][0] = 0b01000001;
  memoria[0][1] = 0b00111110;
  memoria[0][2] = 0b00111110;
  memoria[0][3] = 0b00111110;
  memoria[0][4] = 0b01000001;

  //numero 1 
  memoria[1][0] = 0b01101110;
  memoria[1][1] = 0b01011110;
  memoria[1][2] = 0b00000000;
  memoria[1][3] = 0b01111110;
  memoria[1][4] = 0b01111110;

  //Letra A 
  memoria[10][0] = 0b01100000;
  memoria[10][1] = 0b01011011;
  memoria[10][2] = 0b00111011;
  memoria[10][3] = 0b01011011;
  memoria[10][4] = 0b01100000;

  //Letra a 
  memoria[36][0] = 0b01101001;
  memoria[36][1] = 0b01010110;
  memoria[36][2] = 0b01010110;
  memoria[36][3] = 0b01010110;
  memoria[36][4] = 0b01100000;
}

void mostra(short num)
{
  short v1;
  boolean v2;
  
  for(short c=0; c<5;c++)
{
    v1=memoria[num][c];
    

    for(short l = 2; l<9;l++)
    {
      v2 = (boolean)(v1 & 0b00000001);
      digitalWrite(l,v2);//linha 0
      v1 = v1>>1;
    }
    digitalWrite(9+c,LOW);
    delay(10);
    digitalWrite(9+c,HIGH);
  }

  
}


void setup() {
  // put your setup code here, to run once:
  for(short i=1;i<14;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
  }
  matriz();

  Serial.begin(9600);
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    recebe=Serial.read();
    Serial.write(recebe);
    //letra de A - Z
    if(recebe>64 && recebe <91)
    {
      recebe-=55;
    }
    //letras a-z
    if(recebe>96 && recebe <123)
    {
      recebe-=61;
    }
    //numeros 0-1
    if (recebe>47 && recebe<58)
    {
      recebe-=48;
    }
  }
  mostra(recebe);
}
