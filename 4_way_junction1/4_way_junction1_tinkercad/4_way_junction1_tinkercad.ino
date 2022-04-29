int current=0;

int Top_Sensor1 = 11;
int Top_Sensor2 = 12;
int Top_Sensor3 = 13;

int Top_Red = 10;
int Top_Yellow = 9;
int Top_Green = 8;

int Top_value1 = 0;
int Top_value2 = 0;
int Top_value3 = 0;

int Top_State1 = 0;
int Top_State2 = 0;
int Top_State3 = 0;

int Top_Last_State1 = 0;
int Top_Last_State2 = 0;
int Top_Last_State3 = 0;


int Top_priority = 0;

int Right_Sensor1 = 5;
int Right_Sensor2 = 6;
int Right_Sensor3 = 7;

int Right_Red = 4;
int Right_Yellow = 3;
int Right_Green = 2;

int Right_value1 = 0;
int Right_value2 = 0;
int Right_value3 = 0;

int Right_State1 = 0;
int Right_State2 = 0;
int Right_State3 = 0;

int Right_Last_State1 = 0;
int Right_Last_State2 = 0;
int Right_Last_State3 = 0;


int Right_priority = 0;

void Turn_Top_Green()
{
  
  digitalWrite(Right_Yellow,HIGH);
  delay(3000);
  digitalWrite(Right_Green,LOW);
  digitalWrite(Right_Yellow,LOW);
  digitalWrite(Right_Red,HIGH);		//turn right red
  digitalWrite(Top_Red,LOW);
  digitalWrite(Top_Green,HIGH);
  digitalWrite(Top_Yellow,LOW);
}

void Turn_Right_Green()
{
  digitalWrite(Top_Yellow,HIGH);
  delay(3000);
  digitalWrite(Top_Green,LOW);
  digitalWrite(Top_Yellow,LOW);
  digitalWrite(Top_Red,HIGH);		//turn right red
  digitalWrite(Right_Red,LOW);
  digitalWrite(Right_Green,HIGH);
  digitalWrite(Right_Yellow,LOW);
}

void setup()
{
	pinMode(Top_Sensor1,INPUT_PULLUP);
  	pinMode(Top_Sensor2,INPUT_PULLUP);
  	pinMode(Top_Sensor3,INPUT_PULLUP);
  
  	pinMode(Top_Red,OUTPUT);
  	pinMode(Top_Yellow,OUTPUT);
  	pinMode(Top_Green,OUTPUT);

    pinMode(Right_Sensor1,INPUT_PULLUP);
  	pinMode(Right_Sensor2,INPUT_PULLUP);
  	pinMode(Right_Sensor3,INPUT_PULLUP);
  
  	pinMode(Right_Red,OUTPUT);
  	pinMode(Right_Yellow,OUTPUT);
  	pinMode(Right_Green,OUTPUT);

  	Serial.begin(9600);
    Turn_Right_Green();
}

void loop()
{
  	Top_value1 = digitalRead(Top_Sensor1);
  	Top_value2 = digitalRead(Top_Sensor2);
  	Top_value3 = digitalRead(Top_Sensor3);
  	
  	if(Top_value1 == HIGH && Top_Last_State1 == LOW)
    {
      Top_State1 = (Top_State1-1)*-1;
      Top_Last_State1 = HIGH;
      
      if (Top_State1 == 1)
      {
        Top_priority = 1;
      }
      else
      {
        Top_priority = 0;
      }
    }
  	else if(Top_value1 == LOW && Top_Last_State1 == HIGH)
    {
      Top_Last_State1 = LOW;
    }

    if(Top_value2 == HIGH && Top_Last_State2 == LOW)
    {
      Top_State2 = (Top_State2-1)*-1;
      Top_Last_State2 = HIGH;
      
      if (Top_State2 == 1)
      {
        Top_priority = 2;
      }
      else
      {
        Top_priority = 1;
      }
    }
  	else if(Top_value2 == LOW && Top_Last_State2 == HIGH)
    {
      Top_Last_State2 = LOW;
    }
    
    if(Top_value3 == HIGH && Top_Last_State3 == LOW)
    {
      Top_State3 = (Top_State3-1)*-1;
      Top_Last_State3 = HIGH;
      
      if (Top_State3 == 1)
      {
        Top_priority = 3;
      }
      else
      {
        Top_priority = 2;
      }
    }
  	else if(Top_value3 == LOW && Top_Last_State3 == HIGH)
    {
      Top_Last_State3 = LOW;
    }
  	
  	Serial.print("Cars waiting in the top: ");
  	Serial.println(Top_priority);

    Right_value1 = digitalRead(Right_Sensor1);
  	Right_value2 = digitalRead(Right_Sensor2);
  	Right_value3 = digitalRead(Right_Sensor3);
  	
  	if(Right_value1 == HIGH && Right_Last_State1 == LOW)
    {
      Right_State1 = (Right_State1-1)*-1;
      Right_Last_State1 = HIGH;
      
      if (Right_State1 == 1)
      {
        Right_priority = 1;
      }
      else
      {
        Right_priority = 0;
      }
    }
  	else if(Right_value1 == LOW && Right_Last_State1 == HIGH)
    {
      Right_Last_State1 = LOW;
    }

    if(Right_value2 == HIGH && Right_Last_State2 == LOW)
    {
      Right_State2 = (Right_State2-1)*-1;
      Right_Last_State2 = HIGH;
      
      if (Right_State2 == 1)
      {
        Right_priority = 2;
      }
      else
      {
        Right_priority = 1;
      }
    }
  	else if(Right_value2 == LOW && Right_Last_State2 == HIGH)
    {
      Right_Last_State2 = LOW;
    }
    
    if(Right_value3 == HIGH && Right_Last_State3 == LOW)
    {
      Right_State3 = (Right_State3-1)*-1;
      Right_Last_State3 = HIGH;
      
      if (Right_State3 == 1)
      {
        Right_priority = 3;
      }
      else
      {
        Right_priority = 2;
      }
    }
  	else if(Right_value3 == LOW && Right_Last_State3 == HIGH)
    {
      Right_Last_State3 = LOW;
    }
  	
  	Serial.print("Cars waiting in the Right: ");
  	Serial.println(Right_priority);
  	Serial.println("");
    Serial.println("");
    Serial.println("");
  
  	
  	
    if(Top_priority>Right_priority && current!=1)
    {
      Turn_Top_Green();
      current=1;
    }
    else if(Right_priority>Top_priority && current!=2)
    {
      Turn_Right_Green();
      current=2;
    }
}