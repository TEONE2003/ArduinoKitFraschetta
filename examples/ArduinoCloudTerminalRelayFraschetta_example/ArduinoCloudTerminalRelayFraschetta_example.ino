/*This example does not work because the code must be placed in the program with the configuration of the card.*/
#include "arduino_secrets.h"
#include "thingProperties.h"
#include <ArduinoCloudTerminalRelayFraschetta.h>
bool Readible=false;
ArduinoCloudTerminalRelayF R(/*address of the Arduino Cloud string*/,&Readible,"R",13,ReverseLogic);
void setup() {
  R.Begin();
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
}
void loop(){ArduinoCloud.update(); R.FunctionSerialRelay();}
void onSChange(){Readible=true;}