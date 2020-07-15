//Based on source code from these websites: 
//https://how2electronics.com/interface-capacitive-soil-moisture-sensor-arduino/
//https://www.bc-robotics.com/tutorials/using-a-tmp36-temperature-sensor-with-arduino/
//https://create.arduino.cc/projecthub/Ayeon0122/reading-a-photoresistor-1e705e



//Initalize these variables:


//Time
int Time;


  //Moisture Sensor Variables:
const int AirValue = 620;
const int WaterValue=310;
int SoilMoistureValue=0;
int SoilMoisturePercent=0;


  //Temperature Sensor Variables
int TemperaturePin=A2;
int TemperatureSensorInput;
double TemperatureValue;
double TemperatureCalibration=57;



//Photoresistor Variables
const int PhotoResistorPin=A1;
int LightInput;
int LightValue;






void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600); //sets seial port baud to 9600 bps


}

void loop() {
  // put your main code here, to run repeatedly:
  
  
//Report Current time
  Serial.print("Seconds since program started: ");
  Time=(millis()/1000);
  Serial.print(Time);
Serial.print('\n');
 

//Report Moisture Sensor
SoilMoistureValue=analogRead(A0);
Serial.println(SoilMoistureValue);
SoilMoisturePercent=map(SoilMoistureValue, AirValue, WaterValue, 0, 100);
Serial.print ("The moisture level is: ");
Serial.print(SoilMoisturePercent);
Serial.print("%");
Serial.print('\n');

//Report Temperature Sensor
 TemperatureSensorInput=analogRead(A2);
 TemperatureValue=((((double)TemperatureSensorInput / 1024)*5)-0.5)*100+TemperatureCalibration;
 Serial.print("The temperature is: ");
 Serial.print(TemperatureValue);
  Serial.print('\n');

  
  //Report Photo Resistor
LightInput=analogRead(A1);
 LightValue=LightInput;//need to figure out how to get lumens out of this
  Serial.print("The light intensity is: ");
  Serial.println(LightValue);
  Serial.print('\n');

  
  
  
delay(5000);
}
