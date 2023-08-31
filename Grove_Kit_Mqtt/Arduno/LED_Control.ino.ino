//LED Blink
//The LED will turn on for one second and then turn off for one second
int ledPin = 4;
const byte numChars = 32;
static char receivedChars[numChars];   // an array to store the received data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initializes the serial port with a baud rate of 9600
  pinMode(ledPin, OUTPUT);
  Serial.println("<Arduino is ready>");

}

void loop() {
String rc = "";
memset(receivedChars, '\n', 32);
if (Serial.available()> 0)  {
        rc = Serial.readStringUntil('\n');
        if((rc[0]=='O')&&(rc[1]=='F')&&(rc[2]=='F')&&(rc[3]=='\0')){
              digitalWrite(ledPin, LOW);
              Serial.println("LED is OFF");
            }

        if((rc[0]=='O')&&(rc[1]=='N')&&(rc[2]=='\0')){
              digitalWrite(ledPin, HIGH);
              Serial.println("LED is ON");
            }
  }
        
}