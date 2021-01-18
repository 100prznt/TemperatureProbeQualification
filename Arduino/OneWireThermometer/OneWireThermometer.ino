/*
 * 1-wire thermometer
 *
 * This program provides communication with a DS18B20 temperature
 * sensor which is connected to the Arduino at the defined pin.
 * Communication is made via the serial (USB) interface with the
 * connection parameters (9600/8-N-1) and the end sequence \n (<LF>;
 * 0x0A). Showing of all supported commands with "HELP?".
 *
 * https://github.com/100prznt/TemperatureProbeQualification
 */

#define FIRMWARE_VERSION "0.01"
#define HARDWARE_NAME "Arduino M0"

#define ONE_WIRE_BUS_PIN 2 



#include <OneWire.h> 
#include <DallasTemperature.h>



OneWire oneWire(ONE_WIRE_BUS_PIN); 
DallasTemperature sensors(&oneWire);

uint8_t address[8];
String inStr;


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  
  SerialUSB.begin(9600); 
  while (!SerialUSB)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  sensors.begin(); 

  OneWire ow(ONE_WIRE_BUS_PIN);
  ow.search(address);
}

void loop()
{
  if (SerialUSB.available() > 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  
    inStr = SerialUSB.readStringUntil(10);
    if (inStr == "*IDN?")
      SerialUSB.println(HARDWARE_NAME + String(" - 1-wire thermometer"));
    else if (inStr == "T?")
    {
      sensors.requestTemperatures(); // Send the command to get temperature readings 
      float temp = sensors.getTempCByIndex(0);
      SerialUSB.println(temp, 5);
    }
    else if (inStr == "R?")
        SerialUSB.println(sensors.getResolution());
    else if (inStr == "F?")
        SerialUSB.println(FIRMWARE_VERSION);
    else if (inStr == "A?")
    {
      for (uint8_t i = 0; i < 8; i++)
      {
        if (address[i] < 0x10)
          SerialUSB.print("0");
        SerialUSB.print(address[i], HEX);
        if (i < 7)
          SerialUSB.print(":");
      }
      SerialUSB.println();
    }
    else if (inStr == "R 9")
      sensors.setResolution(address, 9);
    else if (inStr == "R 10")
      sensors.setResolution(address, 10);
    else if (inStr == "R 11")
      sensors.setResolution(address, 11);
    else if (inStr == "R 12")
      sensors.setResolution(address, 12);
    else if (inStr == "HELP?")
    {
      SerialUSB.println("1-wire thermometer - Commands");
      SerialUSB.println("");
      SerialUSB.println("Command  Description");
      SerialUSB.println("*IDN?    Request hardwarename");
      SerialUSB.println("F?       Request firmware version");
      SerialUSB.println("A?       Request address of connected 1-wire sensor");
      SerialUSB.println("R?       Request sensor resolution in bits");
      SerialUSB.println("R <res>  Set sensor resolution in bits <9 ... 12>");
      SerialUSB.println("T?       Performe and fetch a measurement");
    }
    else
      SerialUSB.println("Invalid command! Show supported commands with \"HELP?\"");
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
}
