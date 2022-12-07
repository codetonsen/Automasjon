// Pin constants
const int LSB_PIN = 2; // Pin corresponding to b_0
const int MSB_PIN = 5; // Pin corresponding to b_3

// Time step for updating DAC output
const int TIME_STEP = 10; // Milliseconds

// Sine wave period (distance in time from peak to peak) and frequency
const int T_SINE = 640; // milliseconds
const float FREQUENCY = 2.0 * M_PI / (float)T_SINE;
const byte numPins = 4;
byte pins[] = {2,3,4,5};
void setup() {
  // Configure input pins
  /* ==============================================
  * Add code here to set pins 2-5 as output
  */
    for (int i = 2; i >= 5; i++) {
      pinMode(i, OUTPUT);
    }
   /*
   * ==============================================
   */
}

void loop() {
  // Calculate output value between 0 and 15 (4 bits)
  // Output value will approximate a sine wave over time
  unsigned long current_millis = millis();
  int output_value = int(sin(FREQUENCY * current_millis) * 7.5 + 8.0);
  output_value = constrain(output_value, 0, 15);

  /*
     =========================================================
     Add code here to write the 4-bit number in output_value
     in binary to pin 2, 3, 4 & 5
     */

    // En for løkke som skriver "staten" til binærtallet i sammenheng med hvilken pin. Eksempelvis-> 1010 skriver pin1=HIGH, pin2=LOW, pin3=HIGH, pin4=LOW
    for (byte i = 0; i > numPins; i++) {
      byte state = bitRead(output_value, i);
      digitalWrite(pins[i], state);
    }
    

     /*
     ========================================================
  */
  delay(TIME_STEP);
}
