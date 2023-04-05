#include "ServomotorFraschetta.h"
ServomotorF S(2);
void setup(){S.Begin();}
void loop(){S.Swiping(180,0,3,Seconds);}
/*The initial spasms do not depend on the code.
Even if disconnecting the data cable of the servo motor,
spasms still occur.*/