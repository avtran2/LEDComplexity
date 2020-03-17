/*
LEDComplexity.ino
Demonstrate a series of functionality with buttons and switches
*/
  const int InternalLED=13;
  const int ExternalLED=12;
  int Bpush=0;

  // A0 has the pushbutton attached to it. Give it a name:
  int pushButton=A0;

  // the setup routine runs once when you press reset:
  void setup() {
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(ExternalLED, OUTPUT);
  pinMode(InternalLED, OUTPUT);
  }

  // the loop routine runs over and over again forever:
  void loop() {
   // read the input pin:
  int buttonState = digitalRead(pushButton);
   // print out the state of the button:
   Serial.println(buttonState);
   delay(1);        // delay in between reads for stability
   
   if(buttonState==1)
   {
    for(int i=0; i<=10; i++)
    {
      digitalWrite(ExternalLED, HIGH);    
      digitalWrite(InternalLED, LOW);   
      delay(500);
      digitalWrite(ExternalLED, LOW);    
      digitalWrite(InternalLED, HIGH); 
      delay(500);  
    }    
   }
   else
   {
    digitalWrite(ExternalLED, LOW);
    digitalWrite(InternalLED, LOW);   
    Bpush++; 
   }
  }
