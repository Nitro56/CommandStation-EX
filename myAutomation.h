/*  The presence of a file called "myAutomation.h" brings EX-RAIL code into
 *  the command station.
 *  The automation may have multiple concurrent tasks.
 *  A task may 
 *  - Act as a ROUTE setup macro for a user to drive over 
 *  - drive a loco through an AUTOMATION 
 *  - automate some cosmetic part of the layout without any loco.
 *  
 *  At startup, a single task is created to execute the startup sequence.
 *  This task may simply follow a route, or may START  
 *  further tasks (that is.. send a loco out along a route).
 *  
 *  Where the loco id is not known at compile time, a new task 
 *  can be created with the command:
 *  </ START [cab] route> 
 *  
 *  A ROUTE, AUTOMATION or SEQUENCE are internally identical in ExRail terms  
 *  but are just represented differently to a Withrottle user:
 *  ROUTE(n,"name") - as Route_n .. to setup a route through a layout
 *  AUTOMATION(n,"name") as Auto_n .. to send the current loco off along an automated journey
 *  SEQUENCE(n) is not visible to Withrottle.
 *  
 */

// This is the startup sequence, 
AUTOSTART
SET_TRACK(A,MAIN)
SET_TRACK(B,MAIN_AUTO)
SET_TRACK(C,MAIN_AUTO)
SET_TRACK(D,PROG)
DONE     // This just ends the startup thread, leaving 2 others running.
 
SERVO_TURNOUT(100, 100, 500, 200, Fast)
SERVO_TURNOUT(101, 101, 500, 200, Fast)
SERVO_TURNOUT(102, 102, 500, 200, Fast)
SERVO_TURNOUT(103, 103, 500, 200, Fast)
SERVO_TURNOUT(104, 104, 500, 200, Fast)
SERVO_TURNOUT(105, 105, 500, 200, Fast)
SERVO_TURNOUT(106, 106, 500, 200, Fast)
SERVO_TURNOUT(107, 107, 500, 200, Fast)
SERVO_TURNOUT(108, 108, 500, 200, Fast)
SERVO_TURNOUT(109, 109, 500, 200, Fast)
SERVO_TURNOUT(110, 110, 500, 200, Fast)
SERVO_TURNOUT(111, 111, 500, 200, Fast)
SERVO_TURNOUT(112, 112, 500, 200, Fast)
SERVO_TURNOUT(113, 113, 500, 200, Fast)
SERVO_TURNOUT(114, 114, 500, 200, Fast)
SERVO_TURNOUT(115, 115, 500, 200, Fast)

// HAL(EXTurntable,600,1,0x60)
EXTT_TURNTABLE(1,600,0,"My EX-Turntable")
TT_ADDPOSITION(1,1,114,0,"Roundhouse stall 1")
TT_ADDPOSITION(1,2,227,0,"Roundhouse stall 2")
TT_ADDPOSITION(1,3,341,0,"Roundhouse stall 3")
TT_ADDPOSITION(1,4,2159,0,"Reverse to stall 1")
TT_ADDPOSITION(1,5,2273,0,"Reverse to stall 2")
TT_ADDPOSITION(1,6,2386,0,"Reverse to stall 3")
