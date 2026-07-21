#include <Servo.h>

// Initialize 4 servos
Servo s1, s2, s3, s4;

void setup() {
  // Attach servos to PWM pins
  s1.attach(3); s2.attach(5); s3.attach(6); s4.attach(9);
}

void loop() {
  // Start an internal stopwatch (milliseconds)
  unsigned long time = millis(); 

  // Check if less than 2 seconds (2000 ms) have passed
  if (time < 2000) {
    // Sweep all motors from 0 to 180 and back
    for(int p = 0; p <= 180; p += 2) { 
      s1.write(p); s2.write(p); s3.write(p); s4.write(p); delay(10); 
    }
    for(int p = 180; p >= 0; p -= 2) { 
      s1.write(p); s2.write(p); s3.write(p); s4.write(p); delay(10); 
    }
  } 
  // After 2 seconds have passed
  else {
    // Stop sweeping and lock all motors at 90 degrees
    s1.write(90); s2.write(90); s3.write(90); s4.write(90);
  }
}
