/****
   Embedded Systems Development
   Exercise : Task 2.1P - First Name Blinky
   Name : Ereena Bagga
   Student ID : 2010993040
 ****/

// Define LED Pin
int ledPin = 8;
// Declare character input to be translated into morse code
char input;
// Declare duration for dot as 1 second
int dotDuration = 1000;
// Declare duration for dash as 3*dotDuration, i.e., 3 seconds
int dashDuration = dotDuration * 3;

// Array for letters 'A' to 'Z' in morse code
char *letters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Array for numbers 0 to 9 in morse code
char *numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....", "-....",
  "--...", "---..", "----."
};

void setup()
{
  // put your setup code here, to run once:

  // Set the LED Pin as output
  pinMode(ledPin, OUTPUT);// [1]
  Serial.begin(9600); // [2]
  Serial.println("************************************ TASK 1.2P *************************************");
  Serial.println("******************** TRANSLATION OF MORSE CODE INTO BLINKING LED *******************");
  Serial.println("**************************** PLEASE ENTER YOUR MESSAGE *****************************");
}

void loop()
{
  // put your main code here, to run repeatedly:

  // [3] While the number of characters being read from the Serial port are greater than 0
  while (Serial.available() > 0)
  {
    input = Serial.read(); // [4] We read the incoming serial data
    Serial.print(input); // [5] and print it

    // If the input given belongs to uppercase letters
    if (input >= 'A' && input <= 'Z')
    {
      flashMorseCode(letters[input - 'A']); // Method call to flash morse code on LED
    }

    // If the input given belongs to lowercase letters
    else  if (input >= 'a' && input <= 'z')
    {
      flashMorseCode(letters[input - 'a']); // Method call to flash morse code on LED
    }

    // If the input given belongs to numbers
    else if (input >= '0' && input <= '9')
    {
      flashMorseCode(numbers[input - '0']); // Method call to flash morse code on LED
    }

    // If the input given is a space between words
    else if (input == ' ')
    {
      // Give a delay equal to seven dots for space
      delay(dotDuration * 7);
    }
  }
}

/**
     This method flashes the morse code for the input letter or number
     @param *morseCode -- pointer to the morse code
*/
void flashMorseCode(char *morseCode)
{
  // Iterating through the entire string of morse code
  for (int i = 0 ; morseCode[i] != NULL ; i++)
  {
    // [6] Turn on the LED
    digitalWrite(ledPin, HIGH);

    // If the given character is a dot
    if (morseCode[i] == '.')
    {
      // Give a delay for 1 second
      delay(dotDuration);
    }

    // Else if the given character is a dash
    else
    {
      // Give a delay for 3 seconds
      delay(dashDuration);
    }

    // Turn the led off
    digitalWrite(ledPin, LOW);

    // A delay of 1 second is given after blinking each part of a character
    delay(dotDuration);
  }
  // A delay of 3 seconds is given after blinking each character
  delay(dashDuration);
}

/****
   [1] Reference for pinMode(pin,mode) Function: https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
   [2] Reference for Serial.begin(speed) Function: https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/
   [3] Reference for Serial.available() Function: https://www.arduino.cc/reference/en/language/functions/communication/serial/available/
   [4] Reference for Serial.read() Function: https://www.arduino.cc/reference/en/language/functions/communication/serial/read/
   [5] Reference for Serial.println(value) Function: https://www.arduino.cc/reference/en/language/functions/communication/serial/println/
   [6] Reference for digitalWrite(pin,value) Function: https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/
****/
