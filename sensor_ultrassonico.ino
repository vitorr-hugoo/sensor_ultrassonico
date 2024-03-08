//Configuração de Distancia Mínima em centimetros
const int distancia_carro = 20; 

//Sensor
const int TRIG = 3;
const int ECHO = 2;

//componentes
const int ledGreen = 7;
const int ledRed = 8;
const int buzzer = 9;

// Variaveis para funcionamento do Buzzer
float seno;
int frequencia;

void setup() {
  Serial.begin(9600);
  
  // Configurações do Sensor
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  
  // Configurações do LED
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  //Configurações do Buzzer
  pinMode(buzzer, OUTPUT); 
  
}

void loop() {
  int distancia = sensor_morcego(TRIG,ECHO);

    if(distancia <= 20 ){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer20();
    }
    else if(distancia <= 30){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer40();
    }
    else if(distancia <= 40){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer60();
    }
    else if(distancia <= 50){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer60();
    }
    else if(distancia <= 60){
      Serial.print("Atenção: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledRed, HIGH);
      tocaBuzzer60();
    }
    else{
      Serial.print("Livre: ");
      Serial.print(distancia);
      Serial.println("cm");
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
      noTone(buzzer);
    }
  delay(100);
  
}

int sensor_morcego(int pinotrig,int pinoecho){
  digitalWrite(pinotrig,LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig,LOW);

  return pulseIn(pinoecho,HIGH)/58;
}

//Função para execução do Alarme Sonoro
void tocaBuzzer20(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 3000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}
}
void tocaBuzzer30(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 2500+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}
}
void tocaBuzzer40(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 2000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}

}
void tocaBuzzer50(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 1500+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}

}
void tocaBuzzer60(){
 for(int x=0;x<180;x++){
  seno=(sin(x*3.1416/180));
  frequencia = 1000+(int(seno*1000));
  tone(buzzer,frequencia);
  delay(2);
}

}