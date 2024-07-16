
/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Detector de sismos
   Dev. Fabian Andree Sinay Canel
   Fecha: 16 de Julio
*/
//librerias 
#include <math.h>
#include<Wire.h>                   
#include <SparkFun_ADXL345.h>       
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

//construccion
ADXL345 acelerometro_ADXL345 = ADXL345();    
SoftwareSerial DFPlayerSerial(2, 13); 
DFRobotDFPlayerMini MP3;

//variables
int x;
int y;
int z;

int gravedadXYZ;
int gravedad;
int sens;
volatile int mer;

void setup() {

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  
 Serial.begin(9600);     
  //configuracion del acelerometro
  acelerometro_ADXL345.powerOn();             
  acelerometro_ADXL345.setRangeSetting(16); 
  //configuracion del MP3
 DFPlayerSerial.begin(9600);
 MP3.begin(DFPlayerSerial);
 MP3.volume(25);    

}

void loop() {
   
 acelerometro_ADXL345.readAccel(&x,&y,&z);

 //Calculos para la gravedad
 gravedadXYZ = ((x*x)+(y*y)+(z*z));
 gravedad = sqrt(gravedadXYZ);

 //sensibilidad
 sens = map(gravedad, 25,175,47,13900 );
 
 //escala de mercalli, valores en gravedad y la escala
 mer = map(sens,47,13900,0,10);
 
 
  
 if(mer < 1){
  digitalWrite(12, LOW);

 }
  if(mer > 1){
  digitalWrite(11, LOW);

 }
 if(mer > 2){
  digitalWrite(10, LOW);

 }
 if(mer > 3){
  digitalWrite(9, LOW);

 }
 if(mer > 4){
  digitalWrite(8, LOW);

 }
 if(mer > 5){
  digitalWrite(7, LOW);
 }
 if(mer > 6){
  digitalWrite(6, LOW);
  MP3.play(1);
  delay(60);
 }
 if(mer > 7){
  digitalWrite(5, LOW);

 }
  if(mer > 8){
  digitalWrite(4, LOW);

 }
  if(mer > 9){
  digitalWrite(3, LOW);

 }

if (mer < 1 && digitalRead(11)==LOW){
  delay(2000);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);

}
}
