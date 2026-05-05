
#include <TinyGPS.h>

 
// INSTANCIA DE LA LIBRERIA TINYGPS Y SOFTWARESERIAL
TinyGPS gps;
 
// VARIABLES PARA RECIBIR LOS DATOS DEL GPS
float latitude, longitude;
unsigned long age;
 
/**
   INICIO DEL SKETCH: ESTE CODIGO SE EJECUTA AL ENCENDER EL ARDUINO
*/
void setup()
{
  // PREPARAR PUERTOS SERIALES PARA COMUNICACIÓN CON LA PC Y CON EL GPS
  Serial.begin(115200);
  Serial1.begin(9600);
  
 
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("   EJEMPLO USO DEL SHIELD/MODULO GPS CON ARDUINO    "));
  Serial.println(F("            https://www.geekfactory.mx              "));
  Serial.println(F("----------------------------------------------------"));
}
 
/**
    CICLO PRINCIPAL DEL SKETCH: RECIBIR LOS DATOS DEL GPS Y CONVERTIRLOS A TIPOS NATIVOS DE ARDUINO
*/
void loop()
{
  // VERIFICAR SI HAY DATOS DESDE EL GPS (UART)
  while (Serial1.available())
  {
    // LEER DATOS DEL UART EMULADO POR SOFTWARE, CARACTER POR CARACTER Y PASARLO AL OBJETO TINYGPS
    // SI SE HA RECIBIDO UNA SENTENCIA NMEA COMPLETA MOSTRARLA EN EL MONITOR SERIAL
    char c = Serial1.read();
 
    // DESCOMENTAR LA SIGUIENTE LINEA PARA VER LAS SENTENCIAS NMEA
    // DESCOMENTAR LA SIGUIENTE LINEA PARA VER LAS SENTENCIAS NMEA
    Serial.write(c);
 
    if (gps.encode(c))
    {
      // OBTENER DATOS DESDE EL OBJETO TINYGPS Y ALMACENARLOS EN LAS VARIABLES INDICADAS
      gps.f_get_position(&latitude, &longitude, &age);
 
      Serial.print(F("NUEVA LECTURA! -> "));
 
      // IMPRIMIR LATITUD
      Serial.print(F("LATITUDE = "));
      Serial.print(latitude, 6);
 
      // IMPRIMIR LONGITUD
      Serial.print(F(" LONGITUDE = "));
      Serial.print(longitude, 6);
 
      // INICIAR NUEVA LINEA
      Serial.println();
    }
  }
}