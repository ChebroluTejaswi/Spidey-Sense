//defining the PIN numbers
#define trigPin 8 
#define echoPin 10 
#define buzzer 5 

void setup() {
    Serial.begin (9600);   //setting the baud rate
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);  
    pinMode(buzzer, OUTPUT);
}

void loop() { 
    long duration, distance;
    //generating the trigger
    digitalWrite(trigPin, LOW);    
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    //total time calculation
    duration = pulseIn(echoPin, HIGH);
    //calculating the distance
    distance = (duration/2) / 29.1; // speed of sound is 343 meter per second
    Serial.print(distance);
    Serial.println(" cm");
    
    // this part of the code below determines whether to
    // beep depending on the distance detected.
    
    if (distance > 31 and distance < 60) { 
        tone(buzzer,50,10); 
        Serial.println(" low");
    }
    else if (distance > 0 and distance < 30) { 
        tone(buzzer,100); 
        Serial.println(" high");
    }
    else {
    }
    delay (500);
}
