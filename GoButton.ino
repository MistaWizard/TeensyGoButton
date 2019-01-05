#include <Bounce.h>

const int ledPin = 13;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce goButton = Bounce(9, 10);  // 10 ms debounce time is appropriate
Bounce upButton = Bounce(10, 10);  // for most mechanical pushbuttons
Bounce downButton = Bounce(11, 10);  // if a button is too "sensitive" 
Bounce stopButton = Bounce(12, 10);  // you can increase this time.

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH); // set the LED on Serial.begin(9600); //set baud rate
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  goButton.update();
  upButton.update();
  downButton.update();
  stopButton.update();

  // Check each button for "falling" edge.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (goButton.fallingEdge()) {
    Keyboard.press(KEY_SPACE);
    Keyboard.release(KEY_SPACE);
  }
  if (upButton.fallingEdge()) {
    Keyboard.press(KEY_UP);
    Keyboard.release(KEY_UP);
  }
  if (downButton.fallingEdge()) {
    Keyboard.press(KEY_DOWN);
    Keyboard.release(KEY_DOWN);
  }
  if (stopButton.fallingEdge()) {
    Keyboard.press(KEY_ESC);
    Keyboard.release(KEY_ESC);
  }
}
