//Setting Pin Numbers
const int bottomGreen = A0;
const int bottomYellow = 3;
const int bottomRed = 4;
const int leftGreen = 5;
const int leftYellow = 6;
const int leftRed = 7;
const int rightGreen = 8;
const int rightYellow = 9;
const int rightRed = 10;
const int topGreen = 11;
const int topYellow = 12;
const int topRed = 13;
const int switchPin = 2; 

// variable
int initialConditionActivator = 0;
int switchState = 0;
int randomDirection = 0;
int evDirectionG, evDirectionY, evDirectionR, redOneG, redOneY, redOneR, redTwoG, redTwoY, redTwoR, redThreeG, redThreeY, redThreeR;
String randDirection = "";
unsigned long oldTime = 0;
long yellowInterval = 3000;
long redInterval = 2000;
long greenInterval = 5000;
int count = 1;
unsigned long currentTime;
int tempcount = 1;
int resetcount = 0;
int resetbottom = 0;
int resettop = 0;
int resetright = 0;
int resetleft = 0;
int x = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bottomGreen, OUTPUT);
  pinMode(bottomYellow, OUTPUT);
  pinMode(bottomRed, OUTPUT);
  pinMode(leftGreen, OUTPUT);
  pinMode(leftYellow, OUTPUT);
  pinMode(leftRed, OUTPUT);
  pinMode(rightGreen, OUTPUT);
  pinMode(rightYellow, OUTPUT);
  pinMode(rightRed, OUTPUT);
  pinMode(topGreen, OUTPUT);
  pinMode(topYellow, OUTPUT);
  pinMode(topRed, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly

  if (initialConditionActivator == 0)
  {
    initialSetUp();
    initialConditionActivator++;
  }
  // change changelights to step by step functions using the time functions
  //digitalRead(switchPin) //0 is not active, 1 is active
  //inserting change lights function
  currentTime = millis();
  if (digitalRead(switchPin) == 1)
  {
    resetcount = 0;
    resetbottom = 0;
    resettop = 0;
    resetright = 0;
    resetleft = 0;
  EV();
  oldTime = currentTime;
  }
if (digitalRead(switchPin) == 0)
{
  if (readLED(bottomGreen) == 1)
  {
    resetcount++; 
    resetbottom++;
  //  Serial.println("RESETTINGB");
  }
  
   if (readLED(topGreen) == 1)
  {
    resetcount++; 
    resettop++;
    //Serial.println("RESETTINGT");
  }

   if (readLED(leftGreen) == 1)
  {
    resetcount++; 
    resetleft++;
    //Serial.println("RESETTINGL");
  }

   if (readLED(rightGreen) == 1)
  {
    resetcount++; 
    resetright++;
    //Serial.println("RESETTINGR");
  }
  
  if (resetcount == 1)
  {
    if (resetright == 1)
    {
      Serial.println("RESETTING RIGHT");
      delay(3000);
      digitalWrite(rightYellow, HIGH);
      digitalWrite(rightGreen, LOW);
      delay(3000);
      digitalWrite(rightYellow, LOW);
      digitalWrite(rightRed, HIGH);
      resetright = 0;
      resetcount = 0;
      delay(2000);
      initialSetUp();
      count = 0;
      oldTime = currentTime;
    }
     if (resetleft == 1)
    {
      Serial.println("RESETTING LEFT");
      delay(3000);
      digitalWrite(leftYellow, HIGH);
      digitalWrite(leftGreen, LOW);
      delay(3000);
      digitalWrite(leftYellow, LOW);
      digitalWrite(leftRed, HIGH);
      resetleft = 0;
      resetcount = 0;
      delay(2000);
      initialSetUp();
      count = 0;
      oldTime = currentTime;
    }
     if (resettop == 1)
    {
      Serial.println("RESETTING TOP");
      delay(3000);
      digitalWrite(topYellow, HIGH);
      digitalWrite(topGreen, LOW);
      delay(3000);
      digitalWrite(topYellow, LOW);
      digitalWrite(topRed, HIGH);
      resettop = 0;
      resetcount = 0;
      delay(2000);
      initialSetUp();
      count = 0;
      oldTime = currentTime;
    }
     if (resetbottom == 1)
    {
      Serial.println("RESETTING RIGHT");
      delay(3000);
      digitalWrite(bottomYellow, HIGH);
      analogWrite(bottomGreen, 0);
      delay(3000);
      digitalWrite(bottomYellow, LOW);
      digitalWrite(bottomRed, HIGH);
      resetbottom = 0;
      resetcount = 0;
      delay(2000);
      initialSetUp();
      count = 0;
      oldTime = currentTime;
    }
    else
    {
      resetright = 0;
    }
  }
//  {
//    
//    
//    Serial.println("111111111111");
//    Serial.println(oldTime);
//    if (resetright == 1)
//    {
//      if (currentTime-oldTime>greenInterval && x == 0)
//      {
//        digitalWrite(rightYellow, HIGH);
//        digitalWrite(rightGreen, LOW);
//        x++;
//        oldTime = currentTime;
//      }
//      if (currentTime-oldTime>yellowInterval && x == 1)
//      {
//        digitalWrite(rightRed, HIGH); 
//        digitalWrite(rightYellow, LOW); 
//        oldTime = currentTime;
//        initialSetUp();
//        resetright = 0;
//        resetcount = 0;
//      }
//    }
//        if (resetleft == 1)
//    {
//      if (currentTime-oldTime>greenInterval && x == 0)
//      {
//        digitalWrite(leftYellow, HIGH);
//        digitalWrite(leftGreen, LOW);
//        x++;
//        oldTime = currentTime;
//      }
//      if (currentTime-oldTime>yellowInterval && x == 1)
//      {
//        digitalWrite(leftRed, HIGH); 
//        digitalWrite(leftYellow, LOW); 
//        oldTime = currentTime;
//        initialSetUp();
//        resetleft = 0;
//        resetcount = 0;
//      }
//    }
//        if (resetright == 1)
//    {
//      if (currentTime-oldTime>greenInterval && x == 0)
//      {
//        digitalWrite(topYellow, HIGH);
//        digitalWrite(topGreen, LOW);
//        x++;
//        oldTime = currentTime;
//      }
//      if (currentTime-oldTime>yellowInterval && x == 1)
//      {
//        digitalWrite(topRed, HIGH); 
//        digitalWrite(topYellow, LOW); 
//        oldTime = currentTime;
//        initialSetUp();
//        resettop = 0;
//        resetcount = 0;
//      }
//    }
//        if (resetright == 1)
//    {
//      if (currentTime-oldTime>greenInterval && x == 0)
//      {
//        digitalWrite(bottomYellow, HIGH);
//        analogWrite(bottomGreen, 0);
//        x++;
//        oldTime = currentTime;
//      }
//      if (currentTime-oldTime>yellowInterval && x == 1)
//      {
//        digitalWrite(bottomRed, HIGH); 
//        digitalWrite(bottomYellow, LOW); 
//        oldTime = currentTime;
//        initialSetUp();
//        resetbottom = 0;
//        resetcount = 0;
//      }
//    }
//    
//   else 
//  {
//    resetcount = 0;
//  } 
//  }
  
}
  if (readLED(bottomGreen) == 1 && count % 6 == 1)
  {
    if (currentTime - oldTime > greenInterval)
    {
     
  //    Serial.println("XXXXXX");
  //  Serial.println(digitalRead(switchPin));
    //Serial.print("TIME: ");
   // Serial.println(currentTime);
    oldTime = currentTime;
    digitalWrite(bottomGreen, 0);
    digitalWrite(topGreen, LOW);
    digitalWrite(bottomYellow, HIGH);
    digitalWrite(topYellow, HIGH);
    //greenInterval = greenInterval + 5000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
  }
 if (readLED(bottomYellow) == 1 && count % 6 == 2)
 {
    if (currentTime - oldTime > yellowInterval)
    {
      //checkForEV();
       oldTime = currentTime;
    digitalWrite(topYellow, LOW);
    digitalWrite(bottomYellow, LOW);
    digitalWrite(topRed, HIGH);
    digitalWrite(bottomRed, HIGH);
    //yellowInterval = yellowInterval + 7000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
    //Serial.println("2");
 }
 if (readLED(bottomRed) == 1 && count % 6 == 3)
 {  
    if (currentTime - oldTime > redInterval)
    {
     // checkForEV();
      oldTime = currentTime;
    digitalWrite(rightRed, LOW);
    digitalWrite(leftRed, LOW);
    digitalWrite(rightGreen, HIGH);
    digitalWrite(leftGreen, HIGH);
    //redInterval = redInterval +8000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
    //Serial.println("3");
   
  }

  if (readLED(rightGreen) == 1 && count % 6 == 4)
  {
   
    if (currentTime - oldTime > greenInterval)
    {
     
  //    Serial.println("XXXXXX");
  //  Serial.println(digitalRead(switchPin));
    //Serial.print("TIME: ");
   // Serial.println(currentTime);
   
    oldTime = currentTime;
    digitalWrite(rightGreen, LOW);
    digitalWrite(leftGreen, LOW);
    digitalWrite(rightYellow, HIGH);
    digitalWrite(leftYellow, HIGH);
    //greenInterval = greenInterval + 5000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
  }
  if (readLED(rightYellow) == 1 && count % 6 == 5)
  {
   
    if (currentTime - oldTime > yellowInterval)
    {
      //checkForEV();
       oldTime = currentTime;
    digitalWrite(rightYellow, LOW);
    digitalWrite(leftYellow, LOW);
    digitalWrite(rightRed, HIGH);
    digitalWrite(leftRed, HIGH);
    //yellowInterval = yellowInterval + 7000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
    //Serial.println("2");
  }
  if (readLED(rightRed) == 1 && count % 6 == 0)
  {
    if (currentTime - oldTime > redInterval)
    {
     // checkForEV();
      oldTime = currentTime;
    digitalWrite(bottomRed, LOW);
    digitalWrite(topRed, LOW);
    digitalWrite(bottomGreen, 255);
    digitalWrite(topGreen, HIGH);
    //redInterval = redInterval +8000;
      Serial.println(currentTime);
      Serial.println(oldTime);
      count++;
      Serial.println(count);
      tempcount = 1;
    }
  }
}

void EV()
{
    //randomDirection = generateRandom();
    //randDirection = getDirection(randomDirection);
    emergencyVehicleProtocol("bottom");
    
}

void initialSetUp()
{
  digitalWrite(bottomGreen, 255);
  digitalWrite(topGreen, HIGH);
  digitalWrite(rightRed, HIGH);
  digitalWrite(leftRed, HIGH);
  digitalWrite(leftYellow, LOW);
  digitalWrite(leftGreen, LOW);
  digitalWrite(rightYellow, LOW);
  digitalWrite(rightGreen, LOW);
  digitalWrite(topRed, LOW);
  digitalWrite(topYellow, LOW);
  digitalWrite(bottomYellow, LOW);
  digitalWrite(bottomRed, LOW);
}

int readLED(int LED)
{
  if (LED == 14)
  {
    if (digitalRead(LED) == 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    return digitalRead(LED);
  }
}

void emergencyVehicleProtocol(String xx)
{
  //Serial.println("EVPrunning");
  if (xx == "bottom")
  {
    evDirectionG = bottomGreen;
    evDirectionY = bottomYellow;
    evDirectionR = bottomRed;
    redOneG = topGreen;
    redOneY = topYellow;
    redOneR = topRed;
    redTwoG = leftGreen;
    redTwoY = leftYellow;
    redTwoR = leftRed;
    redThreeG = rightGreen;
    redThreeY = rightYellow;
    redThreeR = rightRed;
  }
  else if (xx == "left")
  {
    evDirectionG = leftGreen;
    evDirectionY = leftYellow;
    evDirectionR = leftRed;
    redOneG = rightGreen;
    redOneY = rightYellow;
    redOneR = rightRed;
    redTwoG = bottomGreen;
    redTwoY = bottomYellow;
    redTwoR = bottomRed;
    redThreeG = topGreen;
    redThreeY = topYellow;
    redThreeR = topRed;
  }
  else if (xx == "top")
  {
    evDirectionG = topGreen;
    evDirectionY = topYellow;
    evDirectionR = topRed;
    redOneG = bottomGreen;
    redOneY = bottomYellow;
    redOneR = bottomRed;
    redTwoG = leftGreen;
    redTwoY = leftYellow;
    redTwoR = leftRed;
    redThreeG = rightGreen;
    redThreeY = rightYellow;
    redThreeR = rightRed;
  }
  else if (xx == "right")
  {
    evDirectionG = rightGreen;
    evDirectionY = rightYellow;
    evDirectionR = rightRed;
    redOneG = leftGreen;
    redOneY = leftYellow;
    redOneR = leftRed;
    redTwoG = bottomGreen;
    redTwoY = bottomYellow;
    redTwoR = bottomRed;
    redThreeG = topGreen;
    redThreeY = topYellow;
    redThreeR = topRed;
  }
  //Testing Code
  //  Serial.print("The Emergency vehicle direction is: ");
  //  Serial.print(xx);
  //  Serial.print(", 1: ");
  //  Serial.print(evDirectionG);
  //  Serial.print(", 2: ");
  //  Serial.print(evDirectionY);
  //  Serial.print(", 3: ");
  //  Serial.print(evDirectionR);
  //  Serial.print(", 4: ");
  //  Serial.print(redOneG);
  //  Serial.print(", 5: ");
  //  Serial.print(redOneY);
  //  Serial.print(", 6: ");
  //  Serial.print(redOneR);
  //  Serial.print(", 7: ");
  //  Serial.print(redTwoG);
  //  Serial.print(", 8: ");
  //  Serial.print(redTwoY);
  //  Serial.print(", 9: ");
  //  Serial.print(redTwoR);
  //  Serial.print(", 10: ");
  //  Serial.print(redThreeG);
  //  Serial.print(", 11: ");
  //  Serial.print(redThreeY);
  //  Serial.print(", 12: ");
  //  Serial.println(redThreeR);

  if (readLED(evDirectionG) == 1 && tempcount == 1)
  { //case1
    //Some code to make redOne red
    Serial.println("CASE1");
     while (digitalRead(switchPin) == 1 && tempcount == 1)
    {
      case1();
    }
    Serial.println(currentTime);
      Serial.println(oldTime);
  }
  else if (readLED(evDirectionY) == 1 && tempcount == 1)
  { //case2
    //some code to make ev direction to green and make redOne red
    Serial.println("CASE2");
    while (digitalRead(switchPin) == 1 && tempcount == 1)
    {
      case2();
    }
    Serial.println(currentTime);
      Serial.println(oldTime);
  }
  else if (readLED(redTwoG) == 1 && tempcount == 1)
  { //case3
    //some code to redtwo and redthree red and make ev direction green
    Serial.println("CASE3");
     while (digitalRead(switchPin) == 1 && tempcount == 1)
    {
      case3();
    }
    Serial.println(currentTime);
      Serial.println(oldTime);
  }
  else if (readLED(redTwoY) == 1 && tempcount == 1)
  { //case4
    //some code to complete sequence to red for redtwo and red three and make only ev direction green
    Serial.println("CASE4");
     while (digitalRead(switchPin) == 1 && tempcount == 1)
    {
      case4();
    }
    Serial.println(currentTime);
      Serial.println(oldTime);
  }
  else if (readLED(evDirectionR) == 1 && readLED(redOneR) == 1 && readLED(redTwoR) == 1 && readLED(redThreeR) == 1 && tempcount == 1)
  {
    while (digitalRead(switchPin) == 1 && tempcount == 1)
    {
      case5();
    }
  }
}

void case1()
{
  //In this situation, the emergency vehicle's light is already green. The cross road's lights are red. The light for the path opposite to the emergency vehicles path needs to be made red.
  //Due to the limitation of the arduino board, an if loop needs to be implemented to make input 14's output value set to 255 or 0 depending on the situation

  if (redOneG == 14)
  {
    analogWrite(redOneG, 0);
  }
  else
  {
    digitalWrite(redOneG, LOW);
  }
  digitalWrite(redOneY, HIGH);
  delay(3000);
 
  digitalWrite(redOneR, HIGH);
   digitalWrite(redOneY, LOW);
  tempcount++;
}

void case2()
{
  //In this situation, the lights on the street which the EV is on turned yellow and are about to turn red. The safest way to make the light green again would be to make the light red
  //and then make the light for the EV's path green. The amount of time that the light has been yellow is not known. Therefore, the same 3 second rule applies
  delay(3000);
  digitalWrite(evDirectionY, LOW);
  digitalWrite(redOneY, LOW);
  digitalWrite(evDirectionR, HIGH);
  digitalWrite(redOneR, HIGH);
  delay(2000);
  tempcount++;
  if (evDirectionG == 14)
  {
    analogWrite(evDirectionG, 255);
  }
  else
  {
    digitalWrite(evDirectionG, HIGH);
  }
  digitalWrite(evDirectionR, LOW);
}

void case3()
{
  //some code to redtwo and redthree red and make ev direction green
  //In this situation, the lights on the cross street of the EV's path are green and the lights in the path of the EV are red.
  if (redTwoG == 14)
  {
    analogWrite(redTwoG, 0);
    digitalWrite(redThreeG, LOW);
  }
  else if (redThreeG == 14)
  {
    analogWrite(redThreeG, 0);
    digitalWrite(redTwoG, LOW);
  }
  else
  {
    digitalWrite(redThreeG, LOW);
    digitalWrite(redTwoG, LOW);
  }
  digitalWrite(redTwoY, HIGH);
  digitalWrite(redThreeY, HIGH);
  delay(3000);
  digitalWrite(redTwoY, LOW);
  digitalWrite(redThreeY, LOW);
  digitalWrite(redTwoR, HIGH);
  digitalWrite(redThreeR, HIGH);
  delay(2000);
  tempcount++;
  if (evDirectionG == 14)
  {
    analogWrite(evDirectionG, 255);
  }
  else
  {
    digitalWrite(evDirectionG, HIGH);
  }
  digitalWrite(evDirectionR, LOW);
}

void case4()
{
  //some code to complete sequence to red for redtwo and red three and make only ev direction green
  //in this situation, the time that the light has been yellow is not known. An additional 3 seconds is added as a precaution.
  //The yellow lights turn red after this period. the EV's light turns green.
  delay(3000);
  digitalWrite(redTwoY, LOW);
  digitalWrite(redThreeY, LOW);
  digitalWrite(redTwoR, HIGH);
  digitalWrite(redThreeR, HIGH);
  delay(2000);
  if (evDirectionG == 14)
  {
    analogWrite(evDirectionG, 255);
  }
  else
  {
    digitalWrite(evDirectionG, HIGH);
  }
  digitalWrite(evDirectionR,LOW);
  tempcount++;
}

void case5()
{
  delay(2000);
  digitalWrite(evDirectionR, LOW);
  if (evDirectionG == 14)
  {
    analogWrite(evDirectionG, 255);
  }
  else
  {
    digitalWrite(evDirectionG, HIGH);
  }
}

int generateRandom()
{
  int x = 0;//random(0,4);
  return x;
}
String getDirection(int x)
{
  switch (x)
  {
    case 0:
      return "bottom";
      break;
    case 1:
      return "left";
      break;
    case 2:
      return "top";
      break;
    case 3:
      return "right";
      break;
  }
}

void deactivateEmergencyVehicleProtocol()
{
}


