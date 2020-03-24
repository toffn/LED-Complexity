/*
DigitalReadSerial is referenced as a base for this code
*/


  const int internalLED = 13;
  const int externalLED = 12;
  int counter = 0;
  int i = 0;

  // A0 has the pushbutton attached to it. Give it a name:
  int pushButton = A0;

  // the setup routine runs once when you press reset:
  void setup() {
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(internalLED, OUTPUT);
  pinMode(externalLED, OUTPUT);
  }

  // the loop routine runs over and over again forever:
  void loop() {
   // read the input pin:
  int buttonState = digitalRead(pushButton);
   // print out the state of the button:
   Serial.println(buttonState);
   Serial.println(counter);
   delay(1);        // delay in between reads for stability

   //increment counter when button held
   if (buttonState==1)
   {
    counter++;
   }
   //if not held, reset counter to 0
   else
   {
    digitalWrite(externalLED, LOW);
    counter = 0;
   }

    //if counter is divisible by 20 with no remainders, turn off and delay a second
    if (counter%20==0)
    {
      digitalWrite(externalLED, LOW);
      delay(100);
    }
    else
    {
      digitalWrite(externalLED, HIGH);
    }
   
  }
