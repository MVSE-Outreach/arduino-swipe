
#define SENSOR_PIN A0

// This will store the value of our swipe sensor.
int sensorValue;

void setup() {
    
    // Start the serial connection with the PC.
    Serial.begin(9600);
}

void loop() {
    
    // read the sensor value and store it.
    sensorValue = analogRead(SENSOR_PIN);

    // print the results to the serial monitor:
    Serial.println(sensorValue);
}
