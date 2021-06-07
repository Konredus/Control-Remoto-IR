/*
   Este ejemplo imprime por Serial el valor de cada
   boton que es presionado en el control remoto Infrarrojo.
   Libreria creada por Ken Shirriff
   Traducido por Konrad Peschka | Tribumaker.com
*/

#include <IRremote.h>

//Este es el pin donde conectamos el sensor IR
int IR_PIN = 8;

IRrecv Infrarojo(IR_PIN);
decode_results auxiliar;

void setup()
{
  Serial.begin(9600);

  //inicializamos la lectura del sensor infrarrojo
  Infrarojo.enableIRIn();
}

void loop()
{
  //si hay alguna informacion, entonces entra al if()
  if (Infrarojo.decode(&auxiliar) > 0)
  {
    Serial.print("Boton presionado: ");
    Serial.println(auxiliar.value);

    // Recibo el siguiente dato para actualizar auxiliar
    Infrarojo.resume();
  }
}
