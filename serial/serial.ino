/*
 * serial
 * Gertduino Manual Page 5 for configuration serial to 328
 */

String inData;
char ch;

void setup()
{
  Serial.begin( 57600 );
  pinMode( 13, OUTPUT );
  inData = "";
}

void loop()
{
  while( Serial.available() > 0 ) {
    ch = Serial.read();
    inData += ch;
    if( ch == '\n' || ch == 13 || ch == 10 || ch == '\r' ) {
      Serial.print( "+" );
      Serial.println( inData );
      inData = "";
    } else {
      Serial.print( "." );
    }
  }

  digitalWrite( 13, HIGH ); delay( 500 );
  digitalWrite( 13, LOW ); delay( 500 );
  Serial.println( "Hello World." );
}
