#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the I2C address if necessary

int tempPin = A0; // LM35 sensor connected to analog pin A0
int tempReading;   // Variable to store raw sensor data
float temperature; // Variable to store the calculated temperature in Celsius
int threshold = 30; // Temperature threshold (in Celsius)

void setup() {
  lcd.begin();          // Start LCD
  lcd.backlight();      // Turn on backlight
  pinMode(tempPin, INPUT); // Set the temperature pin as input
  Serial.begin(9600);   // Start serial communication for debugging
}

void loop() {
  tempReading = analogRead(tempPin); // Read the sensor value
  temperature = (tempReading * 5.0 * 100.0) / 1024.0; // Convert the value to Celsius
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);  // Display the temperature on LCD
  
  if (temperature > threshold) {
    lcd.setCursor(0, 1);
    lcd.print("Warning! High Temp");
    // You can also activate a buzzer or LED here for alert
  }
  
  delay(1000); // Wait for a second before updating
}