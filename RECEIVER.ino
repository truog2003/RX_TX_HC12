//Demo - https://youtu.be/3bsvpogH8-0
//visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid
//https://github.com/rootsaid/arduino_hc12_remote_controller/blob/master/arduino_hc12_remote_controller.ino
//http://blog.eletrogate.com/gps-neo-6m-com-arduino-aprenda-usar/
//https://github.com/mikalhart/TinyGPSPlus/blob/master/examples/BasicExample/BasicExample.ino
//https://portal.vidadesilicio.com.br/modulo-gps-neo-6m/
//https://howtomechatronics.com/tutorials/arduino/diy-motorized-camera-slider-pan-tilt-head-project/
//https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
//https://github.com/ErickSimoes/Ultrasonic/blob/master/examples/UltrasonicSimple/UltrasonicSimple.ino
//https://sites.google.com/site/wayneholder/self-driving-rc-car/getting-from-point-a-to-point-b
//https://cdn.instructables.com/ORIG/FPP/JJZR/HLFIFY7W/FPPJJZRHLFIFY7W.txt

//Placa arduino MEGA

#include <SoftwareSerial.h> //Biblioteca pro HC12
#include <TinyGPS.h> //Biblioteca pro GPS
#include <Ultrasonic.h>  //Biblioteca do sensor SONAR

#define GPS_RX 14 //Saida pro GPS pino
#define GPS_TX 15 //Entrada pro GPS pino
#define Baud 115200 //velocidade de comunicação geral (HC12 e GPS)

SoftwareSerial HC12(0, 1); // Porta Rx e TX do arduino
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);

String input;
int x1; //UAG motion
int y1; //UAG motion
int velocidade;
int x2; //Turret pivot
int y2; //Turret head
int sw2; // Chave para deslocamento automatico
int sw3; // comentar o que não usar
int sw4; // comentar o que não usar
int boundLow;
int boundHigh;
const char delimiter = ';';

/*telemetria - voltagem*/
int pinosensordc; //A4,Sensor DC 0-25V
int valordc = 0;
float tensaodc = 0;

/*telemetria - GPS*/
TinyGPS gps; // The TinyGPS object

float lat, lon, vel;
unsigned long data, hora;
unsigned short sat;

/*Controle do UAG motion*/
int mx1;
int my1;
int dirx1a;
int stepx1a;
int dirx1b;
int stepx1b;

/*Turret Pivot - Head*/
int mx2;      //Pivot
int my2;      //Head
int dirx2a;   //Pivot
int stepx2a;  //Pivot
int dirx2b;
int stepx2b;
int limitp1;  //Pivot
int limitp2;  //Pivot
int limitp3;  //Pivot centro
int limith1;
int limith2;
int limith3;  //Head centro
int autosw;

/*SONG*/
int buzzer = 18; //checar porta pwm

/*Sensor SONAR*/ //checar se faz sentido
Ultrasonic ultrasonic1(10, 11); //Inicializa o sensor nos pinos definidos,  caso tenha mais de um sensor, continuar a sequencia
int distancia1;
int value0; //Para zerar step
int value255; //Para colocar valor 255
int distlimit; //Limite de distancia de segurança em CM

/***************************************/

void setup()
{
  /*
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  */
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, OUTPUT);

  /*Motion*/

  /*HC12*/
  Serial.begin(Baud);
  HC12.begin(Baud); //Inicia HC12
  delay(2000);

  /*telemetria - GPS*/
  gpsSerial.begin(Baud); //Inicia GPS
  Serial.println("Buscando satelites... lendo dados do SONAR ...");

  /*sensor SONAR*/

}

/***************************************/

void loop()
{
  pinosensordc = analogRead(A0);
  limitp1 = digitalRead(12); 
  limitp2 = digitalRead(13);
  limitp3 = digitalRead(14);
  limith1 = digitalRead(15);
  limith2 = digitalRead(16);
  limitp3 = digitalRead(17);

  dirx1a = 2; //portas pwm
  stepx1a = 3;
  dirx1b = 4;
  stepx1b = 5;
  dirx2a = 6;
  stepx2a = 7;
  dirx2b =  8;
  stepx2b = 9;

  /* Som inicializar 2X*/

  for (int i = 0; i <= 1; i++) { //espera 5S, executa musica do Mario Bros (pra avisar que inicializou), para 1S, e depois zera o turret 
  
  delay(5000);
  void song1();
  delay(1000);
  void zeroturret();
  delay(10);
  }
  
  /*Sensor SONAR*/ /*Incluir a lógica de invertar o step, condicional*/
  distancia1 = ultrasonic1.read();
  Serial.print(" Distancia SONAR1 in CM: ");
  Serial.println(distancia1);
  delay(1000);

  /*Telemetria - voltagem da bateria do UAG*/
  valordc = analogRead(pinosensordc);
  tensaodc = ((valordc * 0.00489) * 5); //Valor da voltagem a ser transmitido
  Serial.print(" Tensao (V): ");
  Serial.println(tensaodc);
  delay(500);

  /*telemetria - GPS*/
  while (gpsSerial.available()) {
    if (gps.encode(gpsSerial.read())) {

      //Hora e data
      gps.get_datetime(&data, &hora);
      Serial.print("--");
      Serial.print(hora / 1000000);
      Serial.print(":");
      Serial.print((hora % 1000000) / 10000);
      Serial.print(":");
      Serial.print((hora % 10000) / 100);
      Serial.print("--");
      Serial.print(data / 10000);
      Serial.print("/");
      Serial.print((data % 10000) / 100);
      Serial.print("/");
      Serial.print(data % 100);
      Serial.println("--");

      //latitude e longitude
      gps.f_get_position(&lat, &lon);
      Serial.print(" Latitude: ");
      Serial.println(lat, 6);
      Serial.print(" Longitude: ");
      Serial.println(lon, 6);

      //velocidade
      vel = gps.f_speed_kmph();
      Serial.print(" Velocidade: ");
      Serial.println(vel);

      //Satelites
      sat = gps.satellites();
      if (sat != TinyGPS::GPS_INVALID_SATELLITES) {
      Serial.print(" Satelites: ");
      Serial.println(sat);
      }

      Serial.println("");
      delay(10);
    }
  }

  /*Receiver*/
  if (HC12.available())
  {
    input = HC12.readStringUntil('\n'); //Quebra a string no nulo
    if (input.length() > 0)
    {
      Serial.println(input);

      boundLow = input.indexOf(delimiter);
      x1 = input.substring(0, boundLow).toInt();

      boundHigh = input.indexOf(delimiter, boundLow + 1);
      y1 = input.substring(boundLow + 1, boundHigh).toInt();

      boundLow = input.indexOf(delimiter, boundHigh + 1);
      velocidade = input.substring(boundHigh + 1, boundLow).toInt(); //Fator K de velocidade do UAG, antigo sw1

      boundHigh = input.indexOf(delimiter, boundLow + 1);
      x2 = input.substring(boundLow + 1, boundHigh).toInt();

      boundLow = input.indexOf(delimiter, boundHigh + 1);
      y2 = input.substring(boundHigh + 1, boundLow).toInt();

      boundLow = input.indexOf(delimiter, boundHigh + 1);
      sw2 = input.substring(boundLow + 1, boundHigh).toInt(); 

      boundHigh = input.indexOf(delimiter, boundLow + 1);
      sw3 = input.substring(boundHigh + 1, boundLow).toInt(); //Chave deslocamento automatico
      
      boundLow = input.indexOf(delimiter, boundHigh + 1);
      sw4 = input.substring(boundLow + 1).toInt();
      delay(10);
    }
  }

  /*Transmissor da telemetria - montar a string*/
  HC12.print (";");
  HC12.print("Latitude ");
  HC12.print(lat, 6);
  HC12.print(";");
  HC12.print("longitude ");
  HC12.print (lon, 6);
  HC12.print(";");
  HC12.print("Velocidade "); //Velocidade do GPS
  HC12.print(vel, 2);
  HC12.print (";");
  HC12.print("Hora ");
  HC12.print(hora / 1000000);
  HC12.print(":");
  HC12.print((hora % 1000000) / 10000);
  HC12.print(":");
  HC12.print((hora % 10000) / 100);
  HC12.print(";");
  HC12.print("Data ");
  HC12.print(data / 10000);
  HC12.print("/");
  HC12.print((data % 10000) / 100);
  HC12.print("/");
  HC12.print(data % 100);
  HC12.println(";");
  HC12.print("Satelites: ");
  HC12.println(sat);
  HC12.println(";");
  HC12.print("Tensao (V)");
  HC12.print(tensaodc, 2);
  HC12.println("");
  delay(100);

  /*UAG Motion - rodas*/
  mx1 = map(x1, 0, 1023, 0, 1000); //Centro 350-700
  my1 = map(y1, 0, 1023, 0, 1000); //Centro 350-700
   
  if (mx1 > 700 && my1 > 700 && sw3 == LOW && distancia1 >= 40) //Virando à frente e direita
  {
    frentedireita();
    delay(100);
  }
  else if (mx1 < 350 && my1 > 700 && sw3 == LOW && distancia1 >= 40) //Virando à frente e esquerda
  {
    frenteesquerda();
    delay(100);
  }
  else if (mx1 < 350 && my1 < 350 && sw3 == LOW  && distancia1 >= 40) //Virando pra trás à esquerda
  {
    trasequerda();
    delay(100);
  }
  else if (mx1 > 700 && my1 < 350 && sw3 == LOW && distancia1 >= 40) //Virando pra trás à direita
  {
    trasdireita();
    delay(100);
  }
  else if ((mx1 >= 350 && mx1 <= 700) && my1 > 700 && sw3 == LOW && distancia1 >= 40) //Pra frente reto
  {
    frente();
    delay(100);
  }
  else if ((mx1 >= 350 && mx1 <= 700) && my1 < 350 && sw3 == LOW && distancia1 >= 40) //Pra trás reto
  {
    tras();
    delay(100);
  }
  else if ((my1 >= 350 && my1 <= 700) && mx1 > 700 && sw3 == LOW && distancia1 >= 40) //Rodando à direita
  {
    girodireita();
    ariel();
    delay(100);
  }
  else if ((my1 >= 350 && my1 <= 700) && mx1 < 300 && sw3 == LOW && distancia1 >= 40) //Rodando à esquerda
  {
    giroesquerda();
    ariel();
    delay(100);
  }
  else if ((my1 >= 350 && my1 <= 700) && (mx1 >= 350 && mx1 <= 700) && sw3 == HIGH && distancia1 >= 40) //Frente automático, tem de estar x y = 0
  {
    frenteauto();
    delay(100);
  }
  else if (((my1 <= 350 || my1 >= 700) || (mx1 <= 350 || mx1 >= 700)) && (sw3 == LOW || sw3 == HIGH) && distancia1 <= 40) //Obstaculo avoid
  {
    parado();
    delay(300);
    r2D2();
    obstavoid();
    delay(300);
  }
  else  //Parado
  {
    parado();
    delay(100);
  }

  /*Turret - Pivot*/
  mx2 = map(x2, 0, 1023, 0, 1000); 
  my2 = map(y2, 0, 1023, 0, 1000); 

  if (mx2 > 700 && limitp1 == LOW) //Virando o pivot pra direita
  {
    analogWrite(stepx2a, 255);
    analogWrite(dirx2a, 255);
    delay(100);
  }
  else if (mx2 < 300 &&  limitp2 == LOW) //Virando o pivot pra esquerda
  {
    analogWrite(stepx2a, 255);
    analogWrite(dirx2a, 0);
    delay(100);
  }
  else //Parado
  {
    analogWrite(stepx2a, 0);
    analogWrite(dirx2a, 0);
    delay(100);
  }

  /*Turret - Head*/ //Checar limite inferior e superior do curso
  
  if (my2 > 700 && limith1 == LOW) //Virando o pivot pra cima
  {
    analogWrite(stepx2b, 255);
    analogWrite(dirx2b, 255);
    delay(100);
  }
  else if (my2 < 300 &&  limith2 == LOW) //Virando o pivot pra baixo
  {
    analogWrite(stepx2b, 255);
    analogWrite(dirx2b, 0);
    delay(100);
  }
  else //Parado
  {
    analogWrite(stepx2b, 0);
    analogWrite(dirx2b, 0);
    delay(100);
  }
   /*Turret - ZERAR*/ 
  if (sw2 == HIGH) 
  {
    void zeroturret();
    void closeEncounters();
    delay(300);
    void laugh2();
    delay(100);
  }
}

/***************************************************/
/*
            Y
            ^
           1000
            |
           700
            |
            |
X 0---350--------700-->1000          
            |
            |
           350
            |
            0


*/
