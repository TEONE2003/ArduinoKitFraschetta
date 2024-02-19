#include <ArduinoCloudTerminalRelayFraschetta.h>
bool Readible=false;
ArduinoCloudTerminalRelayF R(/*arduino cloud string*/,Readible,"R",13,ReverseLogic,SaveStatus)
void Setup(){R.Begin();}
void Loop(){R.FunctionSerialRelay();}
/*This example does not work because the code must be placed in the program with the configuration of the card.
In the method in which the string changes you only need to write:
Readable=true;*/