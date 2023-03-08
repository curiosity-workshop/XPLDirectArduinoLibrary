#include <Arduino.h>
#include <XPLDirect.h>
#include <Button.h>
#include <Encoder.h>
#include <Switch.h>
#include <LedShift.h>
#include <Timer.h>
#include <DigitalIn.h>
#include <AnalogIn.h>

Button btnNavFF(2);
Encoder encNavVol(3, 4, 5, eEnc4Pulse);
Switch swStrobe(6);

void setup() {
  Serial.begin(XPLDIRECT_BAUDRATE);
  XP.begin("Sample");

  btnNavFF.setCommand(
      XP.registerCommand(F("sim/GPS/g1000n3_nav_ff")));
  encNavVol.setCommand(
      XP.registerCommand(F("sim/GPS/g1000n1_nvol_up")),
      XP.registerCommand(F("sim/GPS/g1000n1_nvol_dn")),
      XP.registerCommand(F("sim/GPS/g1000n1_nvol")));
  swStrobe.setCommand(      
      XP.registerCommand(F("sim/lights/strobe_lights_on")),
      XP.registerCommand(F("sim/lights/strobe_lights_off")));
}

void loop() {
  XP.xloop();

  btnNavFF.handleCommand();
  encNavVol.handleCommand();
  swStrobe.handleCommand();

  if (swStrobe.state() == eSwitchOn)
  {
    //do something
  }
}