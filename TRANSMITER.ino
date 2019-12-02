//Transmitter
//Demo - https://youtu.be/3bsvpogH8-0
//visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid
//https://github.com/rootsaid/arduino_hc12_remote_controller/blob/master/arduino_hc12_remote_controller.ino
//https://www.arduinoecia.com.br/2014/12/modulo-i2c-display-16x2-arduino.html

//Placa Arduino UNO

#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>//Carrega a biblioteca LiquidCrystal I2C
#include <Wire.h>

#define Baud 115200 //velocidade de comunicação geral (HC12)
SoftwareSerial HC12(1, 0); // Porta Rx e TX do arduino
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE); // Inicializa o display no endereco 0x27

/*transmissor*/

int x1; //UAG motion
int y1; //UAG motion
int sw1; //Velocidade pot
int x2; //Turret pivot
int y2; //Turret head
int sw2; 
int sw3;
int sw4;
int velocidade;

/*receiver_telemetria*/

String input;
int tensaodc; //telemetria do receptor, voltagem de bateria
int valordctran; //Voltagem do transmissor
int boundLow;
int boundHigh;
const char delimiter = ';';
float lat, lon, vel;
unsigned short sat;

/*SONG*/
int buzzer = 3; //checar porta pwm

/***************************************/

void setup()
{
  /*transmissor*/
  HC12.begin(Baud);
  Serial.begin(Baud);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT); //Velocidade
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT); 
  pinMode(5, INPUT); //sw3
  pinMode(6, INPUT); //sw4

  /*LCD*/
  lcd.begin(16, 2); //Define o número de colunas e linhas do LCD
}

/***************************************/

void loop()
{
  /*transmissor*/
  analogWrite(A0, 0); // colocando um valor inicial da porta A0
  analogWrite(A1, 0); // colocando um valor inicial da porta A1
  analogWrite(A2, 0); // colocando um valor inicial da porta A2
  analogWrite(A3, 0); // colocando um valor inicial da porta A3
  analogWrite(A4, 0); // colocando um valor inicial da porta A4
  analogWrite(A5, 0); // colocando um valor inicial da porta A5
  digitalWrite(3, LOW); // Colocando uma valor High na saída 3
  digitalWrite(4, LOW); // Colocando uma valor High na saída 4 - comentar o que não usar
  digitalWrite(5, LOW); // Colocando uma valor High na saída 5 - comentar o que não usar
  digitalWrite(6, LOW); // Colocando uma valor High na saída 6 - comentar o que não usar


  x1 = analogRead(A0);
  y1 = analogRead(A1);
  sw1 = analogRead(A2); //Velocidade
  velocidade = map(sw1, 0, 1023, 0, 10); //Velocidade
  x2 = analogRead(A3);
  y2 = analogRead(A4);
  sw2 = analogRead(A5); // comentar o que não usar
  sw3 = digitalRead(3); // Chave para deslocamento automatico
  sw4 = digitalRead(4); // comentar o que não usar

  HC12.print(";");
  HC12.print(x1);    // Valor a ser transmitido pelo HC12
  HC12.print(";");
  HC12.print(y1);
  HC12.print(";");
  HC12.print(velocidade);
  HC12.print(";");
  HC12.print(x2);
  HC12.print(";");
  HC12.print(y2);
  HC12.print(";");
  HC12.print(sw2);
  HC12.print(";");
  HC12.print(sw3); // comentar o que não usar
  HC12.print(";");  // comentar o que não usar
  HC12.print(sw4); // comentar o que não usar
  HC12.println(""); 

  delay(100);

  /*Telemetria GPS - Voltagem - quebrar string*/
  if (HC12.available())
  {
    input = HC12.readStringUntil('\n'); //Quebra a string no nulo
    if (input.length() > 0)
    {
      Serial.println(input);

      boundLow = input.indexOf(delimiter);
      lat = input.substring(0, boundLow).toInt();

      boundHigh = input.indexOf(delimiter, boundLow + 1);
      lon = input.substring(boundLow + 1, boundHigh).toInt();

      boundLow = input.indexOf(delimiter, boundHigh + 1);
      vel = input.substring(boundHigh + 1, boundLow).toInt();

      boundHigh = input.indexOf(delimiter, boundLow + 1);
      sat = input.substring(boundLow + 1, boundHigh).toInt();

      boundLow = input.indexOf(delimiter, boundHigh + 1);
      tensaodc = input.substring(boundHigh + 1, boundLow).toInt();

      delay(10);
    }
  }

  /*LCD*/

      lcd.setBacklight(HIGH);
      lcd.setCursor(0,0); //Mostra a mensagem na primeira linha do lcd
      lcd.print(input); //Mostra a string "input" no lcd
      lcd.setCursor(0,1); //Mostra a mensagem na sengunda linha do lcd
      lcd.print ("Volts UAG: ");
      lcd.print (tensaodc);
      lcd.print (" V");
      lcd.autoscroll(); // set the display to automatically scroll:
      delay(200);
      //lcd.setBacklight(LOW);
      //delay(200);
      lcd.clear(); // clear screen for the next loop 

}
/*************************************************/
/* converter de GMS pra grau decimal - https://www.dexterindustries.com/howto/arduinogpsprojects-gps-coordinates/*/
/*
 * float conv_coords(float in_coords)
 {
 //Initialize the location.
 float f = in_coords;
 // Get the first two digits by turning f into an integer, then doing an integer divide by 100;
 // firsttowdigits should be 77 at this point.
 int firsttwodigits = ((int)f)/100; //This assumes that f < 10000.
 float nexttwodigits = f - (float)(firsttwodigits*100);
 float theFinalAnswer = (float)(firsttwodigits + nexttwodigits/60.0);
 return theFinalAnswer;
 }*/
 
