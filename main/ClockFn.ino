//
//void on_LED(int on, int off1, int off2){
//  digitalWrite(on, HIGH);
//  digitalWrite(off1, LOW);
//  digitalWrite(off2, LOW);
//}
//
//void LED_control(int percent) {
//  if (percent < 70) {
//    // on_LED(RED_LED, YELLOW_LED, GREEN_LED);
//  }
//  else if (percent < 96) {
//    // on_LED(YELLOW_LED, RED_LED,GREEN_LED);
//  }
//  else {
//    // on_LED(GREEN_LED, YELLOW_LED, RED_LED);
//  }
//}

void initializeFutTime(){
  now = rtc.now();
  fut_time = now + TimeSpan(2);
}

int isValidTime() {
  if (rtc.now() > fut_time) {
    initializeFutTime();
    return 1;
  }
  return 0;
}
