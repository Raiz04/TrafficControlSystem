int current=0;

int Top_Sensor1 = 12;
int Top_Sensor2 = 13;

int Top_Red = 9;
int Top_Yellow = 10;
int Top_Green = 8;

int Top_value1 = 0;
int Top_value2 = 0;

int Top_priority = 0;

int Right_Sensor1 = 2;
int Right_Sensor2 = 3;

int Right_Red = 5;
int Right_Yellow = 6;
int Right_Green = 7;

int Right_value1 = 0;
int Right_value2 = 0;

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
  
  	pinMode(Top_Red,OUTPUT);
  	pinMode(Top_Yellow,OUTPUT);
  	pinMode(Top_Green,OUTPUT);

    pinMode(Right_Sensor1,INPUT_PULLUP);
  	pinMode(Right_Sensor2,INPUT_PULLUP);
  
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
  	
  	Top_priority = Top_value1+Top_value2;
  	
  	Serial.print("Cars waiting in the top: ");
  	Serial.print(Top_priority);
    Serial.print("            ");
        
    Right_value1 = digitalRead(Right_Sensor1);
  	Right_value2 = digitalRead(Right_Sensor2);
  	
  	Right_priority = Right_value1+Right_value2;
  	
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
