#include <Servo.h>
Servo gobekServo;
Servo eklem1Servo;
Servo eklem2Servo;
Servo gripperServo;

#define S2 5
#define S3 4
#define sensorOut 3

unsigned int red = 0;
unsigned int green = 0;
unsigned int blue = 0;


int gelenVeri;
int oto,show, tekrarlama;
String voice;
boolean durum = false;
int A, B, C, D;
int pozA, pozB, pozC, pozD;
int turuncu_algilandi, beyaz_algilandi = 0;

void setup() {
  Serial.begin(9600);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  gripperServo.attach(8);
  eklem2Servo.attach(9);
  gobekServo.attach(11);
  eklem1Servo.attach(12);
  gobekServo.write(90);
  eklem1Servo.write(90);
  eklem2Servo.write(90);
  gripperServo.write(100);
  delay(200);
  
  pozA=150;
  for (int i = 90; i <= 155; i++) {
    gobekServo.write(i);
    delay(15);
  }
  for (int i = 100; i <= 140; i++) {
    gripperServo.write(i);
    delay(15);
  }
  //  gobekServo.write(155);
  //  eklem1Servo.write(90);
  //  eklem2Servo.write(90);
  //  gripperServo.write(140);
  delay(1000);
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////////////////ASA///////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void sensor_oku()
{
  // Setting red filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(red / 100); //printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  Serial.print(green / 100); //printing RED color frequency
  Serial.print("  ");
  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  Serial.print(blue / 100); //printing RED color frequency
  Serial.println("  ");
  delay(100);
}

void topa_git()
{
  gripperServo.write(130);
  gobekServo.write(pozA);
  //  for(int i=120;i<=160;i++){gripperServo.write(i);delay(15);}
  for (int i = 90; i >= 70; i--) {eklem2Servo.write(i);delay(20);}delay(50);
  for (int i = 90; i <= 135; i++) {eklem1Servo.write(i);delay(20);}delay(50);
  tekrarlama = 0;
}
void top_al()
{
  //  gobekServo.write(145);
  //  eklem1Servo.write(140);
  //  eklem2Servo.write(80);
  for (int i = 140; i >= 100; i--) {gripperServo.write(i);delay(15);}delay(50);
}

void turuncuTopu_birak()
{
  for (int i = 120; i >= 120; i--) {eklem1Servo.write(i);delay(15);}
  if(show==0){for (int i = pozA; i <= pozA+25; i++) {gobekServo.write(i);delay(15);}}
  for (int i = 70; i <= 130; i++)  {eklem2Servo.write(i);delay(15);}
  for (int i = 120; i <= 160; i++) {eklem1Servo.write(i);delay(15);}
  for (int i = 100; i <= 140; i++) {gripperServo.write(i);delay(15);}
  delay(20);
  for (int i = 160; i >= 90; i--) {eklem1Servo.write(i);delay(15);}
  for (int i = 120; i >= 90; i--) {eklem2Servo.write(i);delay(15);}
  for (int i = pozA+25; i >= pozA; i--) {gobekServo.write(i);delay(15);}
  show=0;
}
void beyazTopu_birak()
{
  for (int i = 120; i >= 120; i--) {eklem1Servo.write(i);delay(15);}
  if(show==0){for (int i = pozA; i >= pozA-25; i--) {gobekServo.write(i); delay(15);}}
  for (int i = 70; i <= 130; i++) {eklem2Servo.write(i); delay(15);}
  for (int i = 120; i <= 160; i++) {eklem1Servo.write(i);delay(15);}
  for (int i = 100; i <= 140; i++) {gripperServo.write(i);delay(15);}
  delay(20);
  for (int i = 160; i >= 90; i--) {eklem1Servo.write(i);delay(15);}
  for (int i = 120; i >= 90; i--) {eklem2Servo.write(i);delay(15);}
  for (int i = pozA-25; i <= pozA; i++) {gobekServo.write(i);delay(15);}
  show=0;
}
void tekrar_oku()
{
  for (int i = 135; i >= 80; i--) {eklem1Servo.write(i);delay(15);}
  for (int i = 100; i <= 140; i++) {gripperServo.write(i);delay(15);}
  tekrarlama = 1;
}

void beyazTop_show()
{
  for (int i = 135; i >= 90; i--)   {eklem1Servo.write(i);delay(15);}
  for (int i = 70; i <= 140; i++)   {eklem2Servo.write(i);delay(15);}  
  for (int i = pozA; i <= 180; i++) {gobekServo.write(i);delay(15);}//sağa
  for (int i = 180; i >=  pozA-25; i--)  {gobekServo.write(i);delay(15);}//sola
  for (int i =  pozA-25; i <= 180; i++)  {gobekServo.write(i);delay(15);}//sağa
  for (int i = 180; i >=  pozA-25; i--)  {gobekServo.write(i);delay(15);}  
  for (int i = 140; i >= 70; i--)   {eklem2Servo.write(i);delay(15);} 
  for (int i = 90; i <= 120; i++)   {eklem1Servo.write(i);delay(20);}
  show=1;
  
}
void turuncuTop_show()
{  
  for (int i = 135; i >= 90; i--)   {eklem1Servo.write(i);delay(15);}
  for (int i = 70; i <= 140; i++)   {eklem2Servo.write(i);delay(15);}  
  for (int i = pozA; i <= pozA+25; i++) {gobekServo.write(i);delay(15);}
  for (int i = pozA+25; i >= 130; i--)  {gobekServo.write(i);delay(15);}
  for (int i = 130; i <= pozA+25; i++)  {gobekServo.write(i);delay(15);}
//  for (int i = 180; i >= 130; i--) {gobekServo.write(i);delay(15);}  
  for (int i = 140; i >= 70; i--)    {eklem2Servo.write(i);delay(15);} 
  for (int i = 90; i <= 120; i++)   {eklem1Servo.write(i);delay(15);}
  show=1;
}
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////////////////ASA///////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////



void loop() {

  while (Serial.available())
  {
    delay(10);
    gelenVeri = (Serial.read());
    Serial.println(gelenVeri);
    delay(10);
    if (gelenVeri == 50)pozA = 100;
    if (gelenVeri == 51)pozA = 105;
    if (gelenVeri == 52)pozA = 110;
    if (gelenVeri == 53)pozA = 115;
    if (gelenVeri == 54)pozA = 120;
    if (gelenVeri == 55)pozA = 125;
    if (gelenVeri == 56)pozA = 130;
    if (gelenVeri == 57)pozA = 135;
    if (gelenVeri == 58)pozA = 140;
    if (gelenVeri == 59)pozA = 145;
    if (gelenVeri == 60)pozA = 150;
    if (gelenVeri == 61)pozA = 155;
    if (gelenVeri == 62)pozA = 160;
    if (gelenVeri == 63)pozA = 165;
    if (gelenVeri == 64)pozA = 170;
    if (gelenVeri == 65)pozA = 175;
    if (gelenVeri == 66)pozA = 180;

    if (gelenVeri == 10)pozB = 0;
    if (gelenVeri == 11)pozB = 10;
    if (gelenVeri == 12)pozB = 20;
    if (gelenVeri == 13)pozB = 30;
    if (gelenVeri == 14)pozB = 40;
    if (gelenVeri == 15)pozB = 50;
    if (gelenVeri == 16)pozB = 60;
    if (gelenVeri == 17)pozB = 70;
    if (gelenVeri == 18)pozB = 80;
    if (gelenVeri == 19)pozB = 90;
    if (gelenVeri == 20)pozB = 100;
    if (gelenVeri == 21)pozB = 110;
    if (gelenVeri == 22)pozB = 120;
    if (gelenVeri == 23)pozB = 130;
    if (gelenVeri == 24)pozB = 140;
    if (gelenVeri == 25)pozB = 150;
    if (gelenVeri == 26)pozB = 160;
    if (gelenVeri == 27)pozB = 170;
    if (gelenVeri == 28)pozB = 180;

    if (gelenVeri == 29)pozC = 50;
    if (gelenVeri == 30)pozC = 60;
    if (gelenVeri == 31)pozC = 70;
    if (gelenVeri == 32)pozC = 80;
    if (gelenVeri == 33)pozC = 90;
    if (gelenVeri == 34)pozC = 100;
    if (gelenVeri == 35)pozC = 110;
    if (gelenVeri == 36)pozC = 120;
    if (gelenVeri == 37)pozC = 130;
    if (gelenVeri == 38)pozC = 140;
    if (gelenVeri == 39)pozC = 150;

    if (gelenVeri == 40)pozD = 180;
    if (gelenVeri == 41)pozD = 170;
    if (gelenVeri == 42)pozD = 160;
    if (gelenVeri == 43)pozD = 150;
    if (gelenVeri == 44)pozD = 140;
    if (gelenVeri == 45)pozD = 130;
    if (gelenVeri == 46)pozD = 120;
    if (gelenVeri == 47)pozD = 110;
    if (gelenVeri == 48)pozD = 100;

    gobekServo.write(pozA);
    eklem1Servo.write(pozB);
    eklem2Servo.write(pozC);
    gripperServo.write(pozD);
    delay(10);

    if (gelenVeri == 1)oto = 1;
    while (oto == 1)
    {
      topa_git();
      delay(20);
      top_al();
      delay(200);
      sensor_oku();
      delay(20);
      ///////hiÃ§ biri deÄŸil ise//////
      if ((red / 100 > 100) || (blue / 100 > 100) || (green / 100 > 100))tekrar_oku();
      ///////turuncu ise/////
      if ((green<blue) && (tekrarlama == 0))turuncuTopu_birak();
      ///////beyaz ise//////
      if ((green>blue) && (tekrarlama == 0))beyazTopu_birak();
      delay(20);

      gelenVeri = (Serial.read());
      if (gelenVeri == 2)oto = 0;

    }
    ////////////////////turuncu topu algÄ±la///////////////////////////
    if (gelenVeri  == 116)
    { gelenVeri = (Serial.read());
      if (gelenVeri  == 117)
      { gelenVeri = (Serial.read());
        if (gelenVeri  == 114)
        { gelenVeri = (Serial.read());
          if (gelenVeri  == 117)
          { gelenVeri = (Serial.read());
            if (gelenVeri  == 110)
            { gelenVeri = (Serial.read());
              if (gelenVeri  == 99)
              { gelenVeri = (Serial.read());
                if (gelenVeri  == 117)
                { gelenVeri = (Serial.read());
                  if (gelenVeri  == 32)
                  { gelenVeri = (Serial.read());
                    if (gelenVeri  == 116)
                    { gelenVeri = (Serial.read());
                      if (gelenVeri  == 111)
                      { gelenVeri = (Serial.read());
                        if (gelenVeri  == 112)
                        { gelenVeri = (Serial.read());
                          if (gelenVeri  == 117)
                          { gelenVeri = (Serial.read());
                            if (gelenVeri  == 32)
                            { gelenVeri = (Serial.read());
                              if (gelenVeri  == 97)
                              { gelenVeri = (Serial.read());
                                if (gelenVeri  == 108)
                                {
                                  Serial.print("turuncu algÄ±landÄ±");
                                  turuncu_algilandi = 1;}}}}}}}}}}}}}}}


    ////////////////////beyaz topu algÄ±la///////////////////////////
    if (gelenVeri  == 98)
    { gelenVeri = (Serial.read());
      if (gelenVeri  == 101)
      { gelenVeri = (Serial.read());
        if (gelenVeri  == 121)
        { gelenVeri = (Serial.read());
          if (gelenVeri  == 97)
          { gelenVeri = (Serial.read());
            if (gelenVeri  == 122)
            { gelenVeri = (Serial.read());
              if (gelenVeri  == 32)
              { gelenVeri = (Serial.read());
                if (gelenVeri  == 116)
                { gelenVeri = (Serial.read());
                  if (gelenVeri  == 111)
                  { gelenVeri = (Serial.read());
                    if (gelenVeri  == 112)
                    { gelenVeri = (Serial.read());
                      if (gelenVeri  == 117)
                      { gelenVeri = (Serial.read());
                        if (gelenVeri  == 32)
                        { gelenVeri = (Serial.read());
                          if (gelenVeri  == 97)
                          { gelenVeri = (Serial.read());
                            if (gelenVeri  == 108)
                            {
                              Serial.print("beyaz algÄ±landÄ±");
                              beyaz_algilandi = 1;}}}}}}}}}}}}}
                              
  while (turuncu_algilandi == 1)
  {
    topa_git();
    delay(20);
    top_al();
    delay(200);
    sensor_oku();
    delay(20);
    ///////hiÃ§ biri deÄŸil ise//////
    if ((red / 100 > 100) || (blue / 100 > 100) || (green / 100 > 100))tekrar_oku();
    ///////turuncu ise/////
    if ((green<blue) && (tekrarlama == 0)){turuncuTop_show(); turuncuTopu_birak();turuncu_algilandi = 0;}
    ///////beyaz ise//////
    if ((green>blue) && (tekrarlama == 0))beyazTopu_birak();
    delay(20);
  }
  while (beyaz_algilandi == 1)
  {
    topa_git();
    delay(20);
    top_al();
    delay(200);
    sensor_oku();
    delay(20);
    ///////hiÃ§ biri deÄŸil ise//////
    if ((red / 100 > 100) || (blue / 100 > 100) || (green / 100 > 100))tekrar_oku();
    ///////turuncu ise/////
    if ((green<blue) && (tekrarlama == 0))turuncuTopu_birak();
    ///////beyaz ise//////
    if ((green>blue) && (tekrarlama == 0)){beyazTop_show(); beyazTopu_birak();beyaz_algilandi = 0;}
    delay(20);
  }
}}
