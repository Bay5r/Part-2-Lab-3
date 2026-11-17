#include <Arduino.h>


void setup() {
  Serial.begin(9600);
  DDRD &= 0xF0; // Set PD4-PD7 as inputs (DIP switches), PD0-PD3 as outputs (LEDs)
  PORTD |= 0xF0; // Enable pull-up resistors for PD4-PD7
  DDRB |= 0x0F; // Set PB0-PB3 as outputs (LEDs)
  PORTB &= ~0x0F; // Initialize PB0-PB3 to LOW (turn off LEDs)

}

void loop() {
  uint8_t value = PIND; // Read the state of DIP switches (PD4-PD7)
          value = value & 0xF0; // Mask to get only the lower 4 bits
          value = value >> 4; // Shift right to align the bits for LED output
          value = ~value; // Invert the bits for active-low LED control
          value = value & 0x0F; // Mask to get only the lower 4 bits
          value = value + 1; // Increment the value to create a counting effect
          value = value & 0x0F; // Mask to get only the lower 4 bits
  PORTB = (PORTB & ~0x0F) | value; // Update the LED states on PB0-PB3
  
  Serial.println(value);
}