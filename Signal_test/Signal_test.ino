int IR1=2;
int IR2=3;

void setup() {
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  Serial.begin(9600);
}
 
void loop() {

  int First = digitalRead(IR1);
  int Second = digitalRead(IR2);
//  Serial.print("First: ");
//  Serial.println(First);
//  Serial.print("Second: ");
//  Serial.println(Second);
  int sum=First+Second;
  Serial.print("Sum: ");
  Serial.println(sum);
  
  if(sum==0)
  {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
  }
  if(sum==1)
  {
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
  }
  if(sum==2)
  {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
  }
  delay(20);
}
