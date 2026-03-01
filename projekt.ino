#define AKCELETROMETR A0 
#define GYROSCOPE A1 
#define ANALOG_BUTTON_PIN A4
	 
//Default values when axis not actioned 
#define AKCELETROMETR 0 
#define ANALOG_Y_CORRECTION 128 
	 
struct button { 
	 byte pressed = 0; 
}; 
	 
struct analog { 
	 short x, y; 
	 
	 button button; 
}; 
	 
void setup() 
{ 
	 pinMode(ANALOG_BUTTON_PIN, INPUT_PULLUP); 
	 Serial.begin(9600); 
} 
	 
void loop() 
{ 
	 analog analog; 
	 
	 analog.x = readAnalogAxisLevel(AKCELETROMETR); 
	 analog.y = readAnalogAxisLevel(GYROSCOPE); 
	 
	 analog.button.pressed = isAnalogButtonPressed(ANALOG_BUTTON_PIN); 
	 
   
	 
	 if (analog.button.pressed) { 
    Serial.print("AKCELETROMETR:"); 
    Serial.println(analog.x); 
    Serial.print("GYROSCOPE:"); 
    Serial.println(analog.y); 
	 } 
	 
	 delay(200); 
} 
	 
byte readAnalogAxisLevel(int pin) 
{ 
	 return map(analogRead(pin), 0, 1023, 0, 255); 
} 
	 
bool isAnalogButtonPressed(int pin) 
{ 
	 return digitalRead(pin) == 0; 
} 
