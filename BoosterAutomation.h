
#if defined(ARDUINO_ARCH_ESP32)
ALIAS(BOOSTER_START)
ALIAS(BOOSTER_CSMODE)
ALIAS(BOOSTER_BOOSTERMODE)
// Booster/CS switch automations
// uses sequences BOOSTER_START, BOOSTER_CSMODE, BOOSTER_BOOSTERMODE, BOOSTER_CHANGELOGIC
// uses latches 200
AUTOSTART  // remove this if you want manual start
ROUTE(BOOSTER_START, "BOOSTER/CS auto START")
  PRINT("BOOTER/CS auto mode starting for both tracks")
  CALL(BOOSTER_BOOSTERMODE) // try booster mode
FOLLOW(BOOSTER_CHANGELOGIC) // goto automatic mode

ROUTE(BOOSTER_CSMODE, "RUN AS CS")
  SET_TRACK(A, MAIN)
  SET_POWER(A, ON)
  SET_TRACK(B, MAIN)
  SET_POWER(B, ON)
  PRINT("CS START")
  LATCH(200)
RETURN

ROUTE(BOOSTER_BOOSTERMODE, "RUN AS BOOSTER")
  SET_TRACK(A, BOOST)
  SET_POWER(A, ON)
  SET_TRACK(B, BOOST)
  SET_POWER(B, ON)
  PRINT("BOOSTER START")
  UNLATCH(200)
RETURN

#define BOOSTER_TIMEOUT 500
SEQUENCE(BOOSTER_CHANGELOGIC)
  // Monitor pin change and get a timeout if not
  IF(BOOSTER_INPUT)
    ATTIMEOUT(-BOOSTER_INPUT,BOOSTER_TIMEOUT)
  ELSE
    ATTIMEOUT(BOOSTER_INPUT,BOOSTER_TIMEOUT)
  ENDIF
  IFTIMEOUT
    IF(200)
      // already switched to CS mode
    ELSE
      CALL(BOOSTER_CSMODE)
    ENDIF
    // hang here and wait for pin change
    IF(BOOSTER_INPUT)
      AT(-BOOSTER_INPUT)
    ELSE
      AT(BOOSTER_INPUT)
    ENDIF
    // pin change has happened, go to booster mode
    CALL(BOOSTER_BOOSTERMODE)
  ENDIF
FOLLOW(BOOSTER_CHANGELOGIC)
#undef BOOSTER_TIMEOUT
#endif
