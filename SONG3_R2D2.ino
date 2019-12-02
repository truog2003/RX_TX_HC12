//https://www.youtube.com/watch?v=L_9IFxVTOpg

#define   note_C0   16          //C0
#define   note_Db0   17         //C#0/Db0
#define   note_D0   18          //D0
#define   note_Eb0   19         //D#0/Eb0
#define   note_E0   20          //E0
#define   note_F0   21          //F0
#define   note_Gb0   23         //F#0/Gb0
#define   note_G0   24          //G0
#define   note_Ab0   25         //G#0/Ab0
#define   note_A0   27          //A0
#define   note_Bb0   29         //A#0/Bb0
#define   note_B0   30          //B0
#define   note_C1   32          //C1
#define   note_Db1   34         //C#1/Db1
#define   note_D1   36          //D1
#define   note_Eb1   38         //D#1/Eb1
#define   note_E1   41          //E1
#define   note_F1   43          //F1
#define   note_Gb1   46         //F#1/Gb1
#define   note_G1   49          //G1
#define   note_Ab1   51         //G#1/Ab1
#define   note_A1   55          //A1
#define   note_Bb1   58         //A#1/Bb1
#define   note_B1   61          //B1
#define   note_C2   65          //C2 (Middle C)
#define   note_Db2   69         //C#2/Db2
#define   note_D2   73          //D2
#define   note_Eb2   77         //D#2/Eb2
#define   note_E2   82          //E2
#define   note_F2   87          //F2
#define   note_Gb2   92         //F#2/Gb2
#define   note_G2   98          //G2
#define   note_Ab2   103        //G#2/Ab2
#define   note_A2   110         //A2
#define   note_Bb2   116        //A#2/Bb2
#define   note_B2   123         //B2
#define   note_C3   130         //C3
#define   note_Db3   138        //C#3/Db3
#define   note_D3   146         //D3
#define   note_Eb3   155        //D#3/Eb3
#define   note_E3   164         //E3
#define   note_F3   174         //F3
#define   note_Gb3   185        //F#3/Gb3
#define   note_G3   196         //G3
#define   note_Ab3   207        //G#3/Ab3
#define   note_A3   220         //A3
#define   note_Bb3   233        //A#3/Bb3
#define   note_B3   246         //B3
#define   note_C4   261         //C4
#define   note_Db4   277        //C#4/Db4
#define   note_D4   293         //D4
#define   note_Eb4   311        //D#4/Eb4
#define   note_E4   329         //E4
#define   note_F4   349         //F4
#define   note_Gb4   369        //F#4/Gb4
#define   note_G4   392         //G4
#define   note_Ab4   415        //G#4/Ab4
#define   note_A4   440         //A4
#define   note_Bb4   466        //A#4/Bb4
#define   note_B4   493         //B4
#define   note_C5   523         //C5
#define   note_Db5   554        //C#5/Db5
#define   note_D5   587         //D5
#define   note_Eb5   622        //D#5/Eb5
#define   note_E5   659         //E5
#define   note_F5   698         //F5
#define   note_Gb5   739        //F#5/Gb5
#define   note_G5   783         //G5
#define   note_Ab5   830        //G#5/Ab5
#define   note_A5   880         //A5
#define   note_Bb5   932        //A#5/Bb5
#define   note_B5   987         //B5
#define   note_C6   1046        //C6
#define   note_Db6   1108       //C#6/Db6
#define   note_D6   1174        //D6
#define   note_Eb6   1244       //D#6/Eb6
#define   note_E6   1318        //E6
#define   note_F6   1396        //F6
#define   note_Gb6   1479       //F#6/Gb6
#define   note_G6   1567        //G6
#define   note_Ab6   1661       //G#6/Ab6
#define   note_A6   1760        //A6
#define   note_Bb6   1864       //A#6/Bb6
#define   note_B6   1975        //B6
#define   note_C7   2093        //C7
#define   note_Db7   2217       //C#7/Db7
#define   note_D7   2349        //D7
#define   note_Eb7   2489       //D#7/Eb7
#define   note_E7   2637        //E7
#define   note_F7   2793        //F7
#define   note_Gb7   2959       //F#7/Gb7
#define   note_G7   3135        //G7
#define   note_Ab7   3322       //G#7/Ab7
#define   note_A7   3520        //A7
#define   note_Bb7   3729       //A#7/Bb7
#define   note_B7   3951        //B7
#define   note_C8   4186        //C8
#define   note_Db8   4434       //C#8/Db8
#define   note_D8   4698        //D8
#define   note_Eb8   4978       //D#8/Eb8

/****************************************************************/

void scale() {
  
  digitalWrite(buzzer, HIGH);

  tone(buzzer, note_C7, 500);   //C: play the note C for 500ms
  tone(buzzer, note_D7, 500);   //D
  tone(buzzer, note_E7, 500);   //E
  tone(buzzer, note_F7, 500);   //F
  tone(buzzer, note_G7, 500);   //G
  tone(buzzer, note_A7, 500);   //A
  tone(buzzer, note_B7, 500);   //B
  tone(buzzer, note_C8, 500);   //C
}

void r2D2() {

  digitalWrite(buzzer, HIGH);

  tone(buzzer, note_A7, 100);   //A
  tone(buzzer, note_G7, 100);   //G
  tone(buzzer, note_E7, 100);   //E
  tone(buzzer, note_C7, 100);   //C
  tone(buzzer, note_D7, 100);   //D
  tone(buzzer, note_B7, 100);   //B
  tone(buzzer, note_F7, 100);   //F
  tone(buzzer, note_C8, 100);   //C
  tone(buzzer, note_A7, 100);   //A
  tone(buzzer, note_G7, 100);   //G
  tone(buzzer, note_E7, 100);   //E
  tone(buzzer, note_C7, 100);   //C
  tone(buzzer, note_D7, 100);   //D
  tone(buzzer, note_B7, 100);   //B
  tone(buzzer, note_F7, 100);   //F
  tone(buzzer, note_C8, 100);   //C
}

void closeEncounters() {

  digitalWrite(buzzer, HIGH);

  tone(buzzer, note_Bb5, 300);  //B b
  delay(50);
  tone(buzzer, note_C6, 300);   //C
  delay(50);
  tone(buzzer, note_Ab5, 300);  //A b
  delay(50);
  tone(buzzer, note_Ab4, 300);  //A b
  delay(50);
  tone(buzzer, note_Eb5, 500);  //E b
  delay(500);
  tone(buzzer, note_Bb4, 300);  //B b
  delay(100);
  tone(buzzer, note_C5, 300);   //C
  delay(100);
  tone(buzzer, note_Ab4, 300);  //A b
  delay(100);
  tone(buzzer, note_Ab3, 300);  //A b
  delay(100);
  tone(buzzer, note_Eb4, 500);  //E b
  delay(500);
  tone(buzzer, note_Bb3, 300);  //B b
  delay(200);
  tone(buzzer, note_C4, 300);   //C
  delay(200);
  tone(buzzer, note_Ab3, 300);  //A b
  delay(500);
  tone(buzzer, note_Ab2, 300);  //A b
  delay(550);
  tone(buzzer, note_Eb3, 500);  //E b
}

void ariel() {

  digitalWrite(buzzer, HIGH);

  tone(buzzer, note_C6, 300);   //C
  delay(50);
  tone(buzzer, note_D6, 300);   //D
  delay(50);
  tone(buzzer, note_Eb6, 600);  //D#
  delay(250);
  tone(buzzer, note_D6, 300);   //D
  delay(50);
  tone(buzzer, note_Eb6, 300);  //D#
  delay(50);
  tone(buzzer, note_F6, 600);   //F
  delay(250);
  tone(buzzer, note_C6, 300);   //C
  delay(50);
  tone(buzzer, note_D6, 300);   //D
  delay(50);
  tone(buzzer, note_Eb6, 500);  //D#
  delay(50);
  tone(buzzer, note_D6, 300);   //D
  delay(50);
  tone(buzzer, note_Eb6, 300);  //D#
  delay(50);
  tone(buzzer, note_D6, 300);   //D
  delay(50);
  tone(buzzer, note_Eb6, 300);  //D#
  delay(50);
  tone(buzzer, note_F6, 600);   //F
  delay(50);

}

void laugh2() {

  digitalWrite(buzzer, HIGH);

  tone(buzzer, note_C6, 200);   //C
  tone(buzzer, note_E6, 200);   //E
  tone(buzzer, note_G6, 200);   //G
  tone(buzzer, note_C7, 200);   //C
  tone(buzzer, note_C6, 200);   //C
  delay(50);
  tone(buzzer, note_C6, 200);   //C
  tone(buzzer, note_E6, 200);   //E
  tone(buzzer, note_G6, 200);   //G
  tone(buzzer, note_C7, 200);   //C
  tone(buzzer, note_C6, 200);   //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C
  delay(50);
  tone(buzzer, note_C6, 50);  //C

}
