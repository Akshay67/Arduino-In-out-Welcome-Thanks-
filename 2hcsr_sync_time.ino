#define s1trigPin 9
#define s1echoPin 8
#define s2trigPin 11
#define s2echoPin 10
#define catchled 12
#define catchled2 7

 // distance & duration 1 is for sensor 1
// distance & duration 2 is for sensor 2
long distance1,distance2,duration1,duration2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(s1trigPin,OUTPUT);
  pinMode(s1echoPin,INPUT);
  pinMode(s2trigPin,OUTPUT);
  pinMode(s2echoPin,INPUT);
  pinMode(catchled,OUTPUT);
  pinMode(catchled2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  sensor2();
  sensor1();

//-----For s1 start----------
  if(distance1 < 5){
      digitalWrite(catchled,HIGH);
      digitalWrite(s2trigPin,LOW);
      delay(5000);
      sensor2();
    }  
    else{
      digitalWrite(catchled,LOW);
      }
   if(distance1>=200 || distance1<=0 ){
    Serial.println("Out of range");
    }
    else{
      Serial.print(distance1);
      Serial.println("d1 cm");
      }
//-----For s1 end----------

//-----For s2 start----------
  if(distance2 < 5){
    digitalWrite(catchled2,HIGH);
    digitalWrite(s1trigPin,LOW);
      delay(5000);
      sensor1();   
    }  
    else{
      digitalWrite(catchled2,LOW);
      
      }
   if(distance2>=200 || distance2<=0 ){
    Serial.println("Out of range");
    }
    else{
      Serial.print(distance2);
      Serial.println("d2 cm");
      }
//-----For s2 end----------

      //delay(500);
}

void sensor1(){
  //-----For s1 start-------

  // Sensor 1 state first low
  digitalWrite(s1trigPin,LOW);
  delayMicroseconds(2);    // wait for 2 micro second
  digitalWrite(s1trigPin,HIGH); //sensor 1 state send signal for 10 micro seconds
  
  delayMicroseconds(10);
  digitalWrite(s1trigPin,LOW); // Afetr 10 ms again signal low
  
  duration1 = pulseIn(s1echoPin,HIGH);
  
  distance1 = (duration1/2) / 29.1;
  
  Serial.println(distance1);

//-------For s1 end------------

}

void sensor2(){
//-----For s2 start-------
  digitalWrite(s2trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(s2trigPin,HIGH);

  delayMicroseconds(10);
  digitalWrite(s2trigPin,LOW);

  duration2 = pulseIn(s2echoPin,HIGH);
  distance2 = (duration2/2) / 29.1;
  Serial.println(distance2);
//-------For s2 end------------
 
}
