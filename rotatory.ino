#define lineCount /* encoder specification (200 generally)*/ 
#define radiusWheel /*some value*/
const int encoin=6; //input pin for the interrupter (blue wire)
const int pulot=5;// plse output for external interfacing
int piezoPin = 8;

long int ti, tf, w,r;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(encoin, INPUT);
  pinMode(pulot, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(encoin)){
  ti=millis();  // time when rays reflected

  while(digitalRead(encoin));
  tf=millis();

  // time period = tf-ti
  //RPM = (Frequency X 60)/ Line Count
 
  int frequency = 1/(tf-ti);
  int rpm = (frequency * 60)/lineCount ;
 
  // speed(in kmph) = (radius of wheel in cm) X (RPM) X (0.00377)

  int speed = radiusWheel*rpm*0.00377;

  if(speed > /*certain value */)
    {
        tone(piezoPin, 1000, 500);
        // here 1000 is frequency of output sound and 500 is duration in ms
    }
  }
} 
