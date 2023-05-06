float voltReadings() {
  float r_1 = 150;
  float r_2 = 10;
  float v_a = (analogRead(VOLTPIN) * 5.00) / 1024.00; // voltage arduino sees
  float v_in = v_a / (r_2/(r_1 + r_2));
  
  return v_in;
}

int isValidVolt() {
  float volt = voltReadings();
  if (volt < 1) {
    return 0;
  } else {
    return 1;
  }
}
