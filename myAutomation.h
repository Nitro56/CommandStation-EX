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
 
SERVO_TURNOUT(100, 100, 450, 110, Fast)
SERVO_TURNOUT(101, 101, 450, 110, Fast)
SERVO_TURNOUT(102, 102, 450, 110, Fast)
SERVO_TURNOUT(103, 103, 450, 110, Fast)
SERVO_TURNOUT(104, 104, 450, 110, Fast)
SERVO_TURNOUT(105, 105, 450, 110, Fast)
SERVO_TURNOUT(106, 106, 450, 110, Fast)
SERVO_TURNOUT(107, 107, 450, 110, Fast)
SERVO_TURNOUT(108, 108, 450, 110, Fast)
SERVO_TURNOUT(109, 109, 450, 110, Fast)
SERVO_TURNOUT(110, 110, 450, 110, Fast)
SERVO_TURNOUT(111, 111, 450, 110, Fast)
SERVO_TURNOUT(112, 112, 450, 110, Fast)
SERVO_TURNOUT(113, 113, 450, 110, Fast)
SERVO_TURNOUT(114, 114, 450, 110, Fast)
SERVO_TURNOUT(115, 115, 450, 110, Fast)

