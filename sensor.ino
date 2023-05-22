#include <DHT.h>
#include "SD.h"
#include "SPI.h"

int chipselect= 10;
int SENSOR = 9;     // pin DATA de DHT22 a pin digital 2
int SENSOR1 =8;     // pin DATA de DHT22 a pin digital 3
int SENSOR2 = 7;     // pin DATA de DHT22 a pin digital 4
int SENSOR3 = 6;     // pin DATA de DHT22 a pin digital 5


int TEMPERATURA,TEMPERATURA1,TEMPERATURA2,TEMPERATURA3;
int HUMEDAD,HUMEDAD1,HUMEDAD2,HUMEDAD3;

DHT dht(SENSOR, DHT22);   // creacion del objeto, cambiar segundo parametro
DHT dht1(SENSOR1, DHT22);   // creacion del objeto, cambiar segundo parametro
DHT dht2(SENSOR2, DHT22);   // creacion del objeto, cambiar segundo parametro
DHT dht3(SENSOR3, DHT22);   // creacion del objeto, cambiar segundo parametro
       
void setup(){
  Serial.begin(9600);   // inicializacion de monitor serial
  dht.begin();      // inicializacion de sensor
   dht1.begin();  
    dht2.begin();  
    dht3.begin();  

 String encabezado = String ("text")+(';')+ String("Hex")+(';') + String("Tcol")+ (';')+ String ("Hcol")+(';')+ String ("Tcam")+(';')+String ("Hcam")+(';');
 
 File dataFile = SD.open ("Datos.CSV" ,FILE_WRITE);//guardamos los datos en la sd
 //escribir en el archivo de excel

 if(dataFile){
  dataFile.println(encabezado);
  Serial.println(encabezado);
  dataFile.close();
 }
     Serial.print( "inicializando SD…");
pinMode( 10, OUTPUT);

//por si la tarjeta falla¡
if ( ! SD.begin( chipselect))
{
Serial.print ("fail-SD");
return;
}

}


void loop(){
  TEMPERATURA = dht.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD = dht.readHumidity();   // obtencion de valor de humedad
 delay(500);
  TEMPERATURA1 = dht1.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD1 = dht1.readHumidity();   // obtencion de valor de humedad
  delay(500);
  TEMPERATURA2 = dht2.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD2 = dht2.readHumidity();   // obtencion de valor de humedad
  delay(500);
  TEMPERATURA3 = dht3.readTemperature();  // obtencion de valor de temperatura
  HUMEDAD3 = dht3.readHumidity();   // obtencion de valor de humedad
   
   String datos= String (TEMPERATURA)+(';')+ String(HUMEDAD)+(';')+ String(TEMPERATURA1)+ (';')+ String (HUMEDAD1)+(';')+ String (TEMPERATURA2)+(';')+String (HUMEDAD2)+(';')+ String (TEMPERATURA3)+(';')+ String (HUMEDAD3);
 
 
 File dataFile = SD.open ("Datos.CSV" ,FILE_WRITE);//guardamos los datos en la sd
 //escribir en el archivo de excel
 if(dataFile){
  dataFile.println(datos);
 
  Serial.println(datos);
  dataFile.close();
 }
 }