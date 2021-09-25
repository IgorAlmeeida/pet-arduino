#include <OneWire.h> //INCLUSÃO DE BIBLIOTECA
#include <DallasTemperature.h> //INCLUSÃO DE BIBLIOTECA

#define DS18B20 7 //DEFINE O PINO DIGITAL UTILIZADO PELO SENSOR
#define rele 4

OneWire ourWire(DS18B20); //CONFIGURA UMA INSTÂNCIA ONEWIRE PARA SE COMUNICAR COM O SENSOR
DallasTemperature sensors(&ourWire); //BIBLIOTECA DallasTemperature UTILIZA A OneWire
bool ligado = false;

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  sensors.begin(); //INICIA O SENSOR
  delay(1000); //INTERVALO DE 1 SEGUNDO
  pinMode(rele, OUTPUT);
}

void loop(){

  float temepratura = (float) sensors.getTempCByIndex(0);
  sensors.requestTemperatures();//SOLICITA QUE A FUNÇÃO INFORME A TEMPERATURA DO SENSOR
  Serial.print("Temperatura: "); //IMPRIME O TEXTO NA SERIAL
  Serial.print(temepratura); //IMPRIME NA SERIAL O VALOR DE TEMPERATURA MEDIDO
  Serial.println("*C"); //IMPRIME O TEXTO NA SERIAL
  Serial.println(ligado);

  if (temepratura < 70.0 && ligado == false){
    ligado = true;
    digitalWrite(rele, LOW);
  }
  if (temepratura > 70.0 && ligado == true){
    ligado = false;
    digitalWrite(rele, HIGH);  //Liga rele 1
  }
   temepratura = 0;
  delay(250);//INTERVALO DE 250 MILISSEGUNDOS
}
