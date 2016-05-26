
#define SENSOR_PIN A0
#define LED_PIN    6

// This will store the value of our swipe sensor.
int sensorValue;

void setup() {
    // Setup our input / output pins.
    pinMode(LED_PIN, OUTPUT);

    // Start the serial connection with the PC.
    Serial.begin(9600);
}

void loop() {
    
    // read the sensor value and store it.
    sensorValue = analogRead(SENSOR_PIN);

    // print the results to the serial monitor:
    Serial.println(sensorValue);
}
