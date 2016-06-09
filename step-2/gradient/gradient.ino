
#define SENSOR_PIN A0
#define LED_PIN    11

// This will store the most recent value of our swipe sensor.
int currentSensorValue;

// This stores the value we will compare with.
int previousSensorValue;

// This stores how fast the sensor value is changing.
int sensorSteepness;

void setup() {
    // Start the serial connection with the PC.
    Serial.begin(115200);
}

void loop() {
    
    // read the sensor value and store it.
    currentSensorValue = analogRead(SENSOR_PIN);

    // Update the new steepness value.
    sensorSteepness = currentSensorValue - previousSensorValue;

    // Move the most recent sensor measurement to the previous one.
    previousSensorValue = currentSensorValue;

    // Make the LED brighter or dimmer.
    int brightness = map(currentSensorValue, 0,1023,0,25);
    analogWrite(LED_PIN, brightness);

    // print the sensor steepness value for the plotter.
    Serial.print(currentSensorValue);
    Serial.print(" ");
    Serial.println(sensorSteepness);
    delay(1);
}
