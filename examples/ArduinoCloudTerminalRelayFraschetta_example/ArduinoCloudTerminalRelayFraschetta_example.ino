#include <ArduinoCloudTerminalRelayFraschetta.h>
bool Readible=false;
ArduinoCloudTerminalRelayF R(/*arduino cloud string*/,Readible,"R",13,ReverseLogic,SaveStatus)
void Setup(){R.Begin();}
void Loop(){R.FunctionSerialRelay();}