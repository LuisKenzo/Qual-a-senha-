int INPUTbit0 = 3;
int INPUTbit1 = 5;
int INPUTbit2 = 6;
int INPUTbitp = 9;//botão que pode ser personalizado
int INPUTpersonalizado = 12;//identifica se a porta lógica é a personalizada
int bit0,bit1,bit2,bitp,entrada0,entrada1,saida=0;
int ledCorreto = 13;
int ledErrado = 10;
int fase = 1;

void setup() {
  pinMode(INPUTbit0, INPUT);
  pinMode(INPUTbit1, INPUT);
  pinMode(INPUTbit2, INPUT);
  pinMode(INPUTbitp, INPUT);
  pinMode(INPUTpersonalizado, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.print("Começando fase");
  Serial.println(fase);
}

void loop() {
  if(digitalRead(INPUTpersonalizado)==LOW){//botão personalizado
      entrada0 = digitalRead(INPUTbit2);
      entrada1 = digitalRead(INPUTbitp);
      saida = entrada0 && entrada1;//Escolher lógica que queira, como default, vou deixar com AND
  }
  else{
     saida = digitalRead(INPUTbit2);
  }
    
    bit0 = random(0,2);
    bit1 = random(0,2);
    bit2 = random(0,2);

    while(digitalRead(INPUTbit0)!=bit0 || digitalRead(INPUTbit1)!=bit1 || saida!=bit2){
      Serial.print(bit0);
      Serial.print(bit1);
      Serial.println(bit2);
      delay(2000);

      digitalWrite(ledErrado, HIGH);
      digitalWrite(ledCorreto, LOW);
      
     //rever se colocou o personalizado
     if(digitalRead(INPUTpersonalizado)==LOW){//botão personalizado
      entrada0 = digitalRead(INPUTbit2);
      entrada1 = digitalRead(INPUTbitp);
      saida = entrada0 && entrada1;//Escolher lógica que queira, como default, vou deixar com AND
     }
     else{
      saida = digitalRead(INPUTbit2);
     }
     
    }
    fase++;
    //Acertou!!
    digitalWrite(ledErrado, LOW);
    digitalWrite(ledCorreto, HIGH);
    Serial.println("Acetou!");
    Serial.print("Começando fase");
    Serial.println(fase);
    delay(1500); 
}

