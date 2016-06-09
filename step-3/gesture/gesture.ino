
#define SENSOR_PIN A0
#define LED_PIN    13

// This will store the most recent value of our swipe sensor.
int currentSensorValue;

// This stores the value we will compare with.
int previousSensorValue;

// This stores how fast the sensor value is changing.
int sensorSteepness;

// We use this to make sure we don't accidentally detect lots of swipes.
int swipe_damper = 1;

// Record which direction we are going in here.
int swipe_direction;

void setup() {
    // Start the serial connection with the PC.
    Serial.begin(115200);
}

void left_or_right(){
    // This function will work out whether we are swiping in a particular
    // direction or not.
    
    // These will determine how fast we have to move to make a swipe.
    const int threshold_1 = 10;
    const int threshold_2 = 20;

    if(sensorSteepness > threshold_2){
        // We swiped left!
        swipe_direction = 100;
        swipe_damper    = 100;
    }else if(sensorSteepness < -threshold_2){
        // We swiped right!
        swipe_direction = -100;
        swipe_damper    = 100;
    }else if(sensorSteepness < threshold_1 && sensorSteepness > - threshold_1){
        // No swipe
        swipe_direction = 0;
    }else{
        // Not sure if there is a swipe, so assume no.
        swipe_direction = 0;
    }
}

void loop() {
    
    // read the sensor value and store it.
    currentSensorValue = analogRead(SENSOR_PIN);

    // Update the new steepness value.
    sensorSteepness = (currentSensorValue - previousSensorValue) / swipe_damper;
    swipe_damper    = swipe_damper > 1 ? swipe_damper - 1 : 1;

    // Lets work out the direction of a swipe.
    left_or_right();

    // Move the most recent sensor measurement to the previous one.
    previousValues[valueIndexAdd] = currentSensorValue;

    // print the sensor steepness value for the plotter.
    Serial.print(currentSensorValue);
    Serial.print(" ");
    Serial.print(swipe_direction);
    Serial.print(" ");
    Serial.println(sensorSteepness);
    delay(1);
}

