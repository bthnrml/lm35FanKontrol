#include <EEPROM.h>

int birinciSensor = A0;
int ikinciSensor = A1;
int fan = 3;

int anlikDisDeger = 0;
int anlikIcDeger = 0;
int anlikDeger = 0;
int icAdres = 0;
int disAdres = 513;
int icAnlikDeger=0;
int disAnlikDeger=0;

int terminal = 13;


void setup() {
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
  pinMode(terminal,OUTPUT);
  
  digitalWrite(3,LOW);

  Serial.begin(9600);
}

void loop() {

/*
for(int i = 0;i<=1024;i++){      // EEPROM SIFIR YAZDIRMA.
  EEPROM.write(i,0);
  }
*/
    float icDeger = analogRead(A0);
    float disDeger = analogRead(A1);
  
    float icSicaklik = ((icDeger/1023.0)*5000.0)/10.0;
    float disSicaklik = ((disDeger/1023.0)*5000.0)/10.0;
    


if(icSicaklik != disSicaklik){
  EEPROM.write(icAdres,icSicaklik);
  icAdres = icAdres+1;
  if(icAdres == 513){
    icAdres = 0;
    }
  }

if(icSicaklik != disSicaklik){
  EEPROM.write(disAdres,disSicaklik);
  disAdres = disAdres+1;
  if(disAdres == 1025){
    disAdres = 513;
    }
  }
delay(60000);


int i;
int j;
j = 15;
if(i>=0 && i<513 && j>=15 && j<527){
    for(i = 0;i<=j;i++){
        anlikIcDeger = anlikIcDeger + EEPROM.read(i);
    }
    i++;
    j++;
  }
else {
  i = 0;
  j = 15;
  }

j = 528;
if(i>=513 && i<1024 && j>=528 && j<1024){
    for(i= 513;i<=j;i++){
        anlikDisDeger = anlikDisDeger + EEPROM.read(i);
    }
    i++;
    j++;
  }
else {
  i = 513;
  j = 528;
  }

  
float anlikDeger = ((anlikIcDeger)/15 - (anlikDisDeger)/15);

if ((anlikDeger) > 15){
      analogWrite(fan,85);
      delay(500);
    }
  if ((anlikDeger) > 30){
      analogWrite(fan,190);
      delay(500);
    }
  if ((anlikDeger) > 45){
      analogWrite(fan,255);
      delay(500);
    }
  else{
      analogWrite(fan,LOW);
    }


Serial.println("------------------------------");
Serial.println(EEPROM.read(0));
Serial.println(EEPROM.read(1));
Serial.println(EEPROM.read(2));
Serial.println(EEPROM.read(3));
Serial.println(EEPROM.read(4));
Serial.println("------------------------------");
Serial.println(EEPROM.read(513));
Serial.println(EEPROM.read(514));
Serial.println(EEPROM.read(515));
Serial.println(EEPROM.read(516));
Serial.println(EEPROM.read(517));



/*
 for (int i = 0;i<=1024;i++){                 //EEPROM DEĞERLERİNİ GÖRMEK İÇİN.
  Serial.print("EEPROM degerleri: ");
  Serial.println(EEPROM.read(i));
  i++;
  delay(0);
  }
*/

}





  
  
