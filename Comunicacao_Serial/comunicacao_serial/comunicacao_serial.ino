void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //aguarda porta serial ser inicializada
  while(!Serial);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print('H'); //imprime na serial a letra H
  Serial.print(" TESTE "); //imprime na serial uma frase
  Serial.println(" pular linha "); // imprime frase e pula linha no final
  Serial.write('W');//envia um número na porta serial
  Serial.write(87);//envia o numero referente a uma letra na tabela ASCII
  delay(1000);
}
