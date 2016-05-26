
#define SENSOR_PIN A0
#define BUFFER_SIZE 20

// This will store the most recent value of our swipe sensor.
int currentSensorValue;
int cm2;

// This one will store the last 20 values.
int previousValues[BUFFER_SIZE];

// This stores the value we will compare with.
int previousSensorValue;

// This keeps track of the newest value.
int valueIndexAdd;

// This stores how fast the sensor value is changing.
int sensorSteepness;

void setup() {
    // Set this to zero to begin with.
    valueIndexAdd = 0;

    // Start the serial connection with the PC.
    Serial.begin(115200);
}

void loop() {
    
    // read the sensor value and store it.
    currentSensorValue = analogRead(SENSOR_PIN) - 1023/2;

    // Update the new steepness value.
    sensorSteepness = currentSensorValue - previousSensorValue;

    // Move the most recent sensor measurement to the previous one.
    previousValues[valueIndexAdd] = currentSensorValue;
    valueIndexAdd = (valueIndexAdd+1) % BUFFER_SIZE;
    previousSensorValue = previousValues[(valueIndexAdd+2) % BUFFER_SIZE];

    // print the sensor steepness value for the plotter.
    Serial.print(" -10 10 ");
    Serial.println(sensorSteepness);
    delay(10);
}
