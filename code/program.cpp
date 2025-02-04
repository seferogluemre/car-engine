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

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address if necessary

void setup()
{
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Engine Temp:");

    Serial.begin(9600);
}
