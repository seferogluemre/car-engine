#include <LiquidCrystal_I2C.h>

// Define the pins
#define TEMP_SENSOR_PIN A0
#define RELAY_PIN 7
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// Define temperature thresholds
#define HIGH_TEMP_THRESHOLD 80
#define LOW_TEMP_THRESHOLD 60

// Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address if necessary
