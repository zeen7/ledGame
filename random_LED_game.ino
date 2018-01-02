 /*  Zeen Wang
  *  Random LED Game
  *  Win when led of same colour is pressed 3 times in a row
  */
 int array []{11, 10, 9, 6, 5, 3}; //array for each LED pin
 int delayTime=1000; //the delay time between each flash
 int LED1=11; // at digital pin 11
 int LED2=10; // at digital pin 10
 int LED3= 9; // at digital pin 9
 int LED4=6;// at digital pin 7
 int LED5=5;// at digital pin 6
 int LED6=3; // at digital pin 3
 int button =8;
 int userPress=0;
 int yellow=0;
 int red=0;
 int green=0;
 int delayEnd=100000000;

void setup() {
  // put your setup code here, to run once:
  for(int p = 0; p<=5; p++)
  {
pinMode(array[p], OUTPUT);
digitalWrite(array[p], LOW);
  }
pinMode(button, INPUT);
int random1=analogRead(0); // random numeric value for random seed
randomSeed(random1);
}

void loop() {
// put your main code here, to run repeatedly:
 userPress= digitalRead(button);
//random led generator 
 while(userPress==LOW)
  {
     long rnd=random(0, 6);
 userPress= digitalRead(button);
digitalWrite(array[rnd], HIGH);
delay(delayTime);
digitalWrite(array[rnd], LOW);

//yellow LEDs
if(userPress==HIGH && rnd==0 ||userPress==HIGH && rnd==5)
{
  digitalWrite(array[0], HIGH);
  digitalWrite(array[5], HIGH);
  delay(delayTime);
  digitalWrite(array[0], LOW);
  digitalWrite(array[5], LOW);
  yellow++;
  green=0;
  red=0;
}
//green LEDs
else if (userPress==HIGH && rnd==1 ||userPress==HIGH && rnd==2)
{
  digitalWrite(array[1], HIGH);
  digitalWrite(array[2], HIGH);
  delay(delayTime);
  digitalWrite(array[1], LOW);
  digitalWrite(array[2], LOW);
  green++;
  red=0;
  yellow=0;
}
//red LEDs
else if (userPress==HIGH && rnd==3 ||userPress==HIGH && rnd==4)
{
  digitalWrite(array[3], HIGH);
  digitalWrite(array[4], HIGH);
  delay(delayTime);
  digitalWrite(array[3], LOW);
  digitalWrite(array[4], LOW);
  red++;
  yellow=0;
  green=0;
}
//win condition
if(yellow==3||red==3||green==3)
{
  for(int a =0; a<=5; a++)
{
for(int r = 0; r < 6; r++) {
    digitalWrite(array[r], HIGH);
  }
  delay(delayTime);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  delay(delayTime);
   }
   delay(delayEnd);
}
}
}



