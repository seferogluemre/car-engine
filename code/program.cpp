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
void loop()
{
    // Read the temperature from the sensor
    int tempReading = analogRead(TEMP_SENSOR_PIN);

    // Convert the sensor reading to temperature in Celsius
    float temperature = ((tempReading * 5.0) / 1024.0) * 100.0;

    // Display the temperature on the LCD display
    lcd.setCursor(0, 1);
    lcd.print(temperature);
    lcd.print("C");

    // Activate the cooling system based on temperature thresholds
    if (temperature >= HIGH_TEMP_THRESHOLD)
    {
        digitalWrite(RELAY_PIN, HIGH); // Activate the cooling system
        digitalWrite(RED_PIN, HIGH);   // Turn on the red channel of the RGB LED
        digitalWrite(GREEN_PIN, LOW);  // Turn off the green channel
        digitalWrite(BLUE_PIN, LOW);   // Turn off the blue channel
    }
    else if (temperature <= LOW_TEMP_THRESHOLD)
    {
        digitalWrite(RELAY_PIN, LOW);  // Deactivate the cooling system
        digitalWrite(RED_PIN, LOW);    // Turn off the red channel
        digitalWrite(GREEN_PIN, HIGH); // Turn on the green channel
        digitalWrite(BLUE_PIN, LOW);   // Turn off the blue channel
    }
    else
    {
        digitalWrite(RELAY_PIN, LOW); // Deactivate the cooling system
        digitalWrite(RED_PIN, LOW);   // Turn off the red channel
        digitalWrite(GREEN_PIN, LOW); // Turn off the green channel
        digitalWrite(BLUE_PIN, HIGH); // Turn on the blue channel
    }

    // Print the temperature to the serial monitor
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("C");

    // Add a delay before the next temperature reading
    delay(1000);
}