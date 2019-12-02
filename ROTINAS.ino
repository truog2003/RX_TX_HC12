
void parado() {           //Parado
  analogWrite(stepx1a, 0);
  analogWrite(stepx1b, 0);
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 0);
}

void frente() {          //Pra frente reto
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
}

void tras() {           //Pra trás reto
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 0);
}

void girodireita() {   //Rodando à direita
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 0);
}

void giroesquerda() {   //Rodando à esquerda
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 255);
}

void frentedireita() {  //Virando à frente e direita
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade)/2);
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
}

void frenteesquerda() {   //Virando à frente e esquerda
  analogWrite(stepx1a, (25 * velocidade)/2);
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
}

void trasequerda() {      //Virando pra trás à esquerda
  analogWrite(stepx1a, (25 * velocidade)/2);
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 0);
}

void trasdireita() {        //Virando pra trás à direita
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade)/2);
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 0);
}

void frenteauto() {          //Pra frente reto
  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
}

void obstavoid() {          //Manobra obstaculo
  analogWrite(stepx1a, (25 * velocidade)/2);
  analogWrite(stepx1b, (25 * velocidade)/2);
  analogWrite(dirx1a, 0);
  analogWrite(dirx1b, 0);
  delay(1000);

  analogWrite(stepx1a, (25 * velocidade)/2);
  analogWrite(stepx1b, (25 * velocidade));
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
  delay(300);

  analogWrite(stepx1a, (25 * velocidade));
  analogWrite(stepx1b, (25 * velocidade)/2);
  analogWrite(dirx1a, 255);
  analogWrite(dirx1b, 255);
  delay(300);
}

void zeroturret() {
do {
  analogWrite(stepx2a, 100); //Gira turret pra esquerda até o limite1
  analogWrite(dirx2a, 255);
} while (limitp1 < 50);
  delay(100);

do {
  analogWrite(stepx2a, 100); //Gira turret pra direita até o limite2
  analogWrite(dirx2a, 0);
} while (limitp2 < 50);
  delay(100);
  
do {
  analogWrite(stepx2a, 100); //Gira turret pra direita até o centro
  analogWrite(dirx2a, 255);
} while (limitp3 < 50);
  delay(100);
  
do  {
    analogWrite(stepx2b, 100); //Gira head pra baixo até limite1
    analogWrite(dirx2b, 255);
  } while (limith1 < 50);
    delay(100);
    
do  {
    analogWrite(stepx2b, 100); //Gira head pra cima até limite2
    analogWrite(dirx2b, 0);
  } while (limith1 < 50);
    delay(100);

do  {
    analogWrite(stepx2b, 100); //Gira head pra baixo até centro
    analogWrite(dirx2b, 255);
  } while (limith3 < 50);
    delay(100);
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
