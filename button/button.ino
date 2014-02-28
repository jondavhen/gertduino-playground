/*
  button
  Reads a digital on 
    PC2 = Port10 
    PC3 = Port3
*/

#define LED1 PB6
#define LED2 PB5

#define BUTTON_PRESSED( pin ) ( ( PINC & _BV( pin ) ) == 0 )

void setup() 
{
  Serial.begin( 57600 );

  // Set as INPUT        activate Pulldown internally
  // pinMode( PC2, INPUT ); // digitalWrite( PC2, HIGH );
  // pinMode( PC3, INPUT_PULLUP ); // digitalWrite( PC3, HIGH );

  pinMode( LED1, OUTPUT );
  pinMode( LED2, OUTPUT );

  digitalWrite( LED1, HIGH ); delay( 1000 );
  digitalWrite( LED1, LOW ); 

  digitalWrite( LED2, HIGH ); delay( 1000 );
  digitalWrite( LED2, LOW ); 

  // Register C to input
  DDRC  = 0b00000000;
  // Pullup on PC2 and PC3
  PORTC = 0b00001100; 
/*
  Serial.println( "------" );
  Serial.println( PINC );
  Serial.println( PORTC );
  Serial.println( PC2 );
  Serial.println( PC3 );
  Serial.println( "------" );
*/
}

void loop() 
{
/*
  Serial.println( "---b" );
  Serial.println( PINC & 0b00000100 );
  Serial.println( PINC & 0b00001000 );
  Serial.println( "--BV" );
  Serial.println( PINC & _BV( PC2 ) );
  Serial.println( PINC & _BV( PC3 ) );
  Serial.println( "--digitalread" );
  Serial.println( digitalRead( PC2 ) );
  Serial.println( digitalRead( PC3 ) );
  Serial.println( "---" );
*/
  digitalWrite( LED1, BUTTON_PRESSED( PC2 ) ); 
  digitalWrite( LED2, BUTTON_PRESSED( PC3 ) ); 

  delay( 1 );
}
