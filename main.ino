#include <LiquidCrystal.h>

// Define constants for LCD pins
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

// Initialize the LiquidCrystal library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define the input pin for the signal
const int inputPin = 8;

void setup() {
  // Set up the LCD with the number of columns and rows
  lcd.begin(16, 2);

  // Configure the input pin
  pinMode(inputPin, INPUT);

  // Print the initial message on the LCD
  lcd.print("Frequency Meter");
}

void loop() {
  // Measure the pulse duration using the pulseIn() function
  unsigned long pulseDuration = pulseIn(inputPin, HIGH, 200000);

  // Calculate the frequency from the pulse duration
  float frequency = 0;
  if (pulseDuration > 0) {
    frequency = 1000000.0 / float(pulseDuration);
  }

  // Display the frequency on the LCD
  lcd.setCursor(0, 1);
  lcd.print("Freq: ");
  lcd.print(frequency, 1);
  lcd.print(" Hz     "); // Extra spaces to clear previous characters

  // Optional: Add a short delay between measurements
  delay(100);
}
