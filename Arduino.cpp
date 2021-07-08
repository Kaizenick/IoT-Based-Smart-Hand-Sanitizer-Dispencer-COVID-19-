#include <LiquidCrystal.h>

#define trigPin 9
#define echoPin 8
#define motorPin 7
#define buttonPin 2
#define alertPin 13

String ssid     = "Simulator Wifi";  // SSID to connect to

//SSID is simply the technical term for a network name. When you set up a wireless home network, you give it a name to distinguish it from other networks in your neighbourhood. You'll see this name when you connect your computer to your wireless network. WPA2 is a standard for wireless security.
String password = ""; // Our virtual wifi has no password (so dont do your banking stuff on this network)
String host     = "api.thingspeak.com"; // Open Weather Map API
const int httpPort   = 80;
// provide your API key below in between thr '=' sign and '&' sign


String uri_temp      = "/update?api_key=3E8CV2EHTC146PKQ&field2=";
String uri_mask     = "/channels/1136896/feeds.json?api_key=7DO0CZ5BB52P8G0O&results=2";


int setupESP8266(void) {
  // Start our ESP8266 Serial Communication
  Serial.begin(115200);   // Serial connection over USB to computer
  Serial.println("AT");   // Serial connection on Tx / Rx port to ESP8266
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 1;
    
  // Connect to 123D Circuits Simulator Wifi
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 2;
  
  // Open TCP connection to the host:
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 3;
    return 0;
}


void anydata_temp(int temperature) 
{ 
  
 // int temperature = map(analogRead(A1),20,358,-40,125);
  
  // Construct our HTTP call
  String httpPacket_temp = "GET " + uri_temp + String(temperature) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length_temp = httpPacket_temp.length();
  
  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length_temp);
  delay(10); // Wait a little for the ESP to respond if (!Serial.find(">")) return -1;

  // Send our http request
  Serial.print(httpPacket_temp);
  delay(10); // Wait a little for the ESP to respond
  if (!Serial.find("SEND OK\r\n")) return;
  
}





// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 6, 5, 4, 3); 

int Contrast=20;
int count=0;
int temperature;
//volatile long duration;

void anydata_mask(void) {
  
  
  // Construct our HTTP call
  String httpPacket = "GET " + uri_mask + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();
  //String httpPacket = "GET https://api.thingspeak.com/channels/1104800/fields/1.json?api_key=CX5ZHR91RBPV0RSW&results=2";
  //int length = httpPacket.length(); 
  
  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length);
  delay(10); // Wait a little for the ESP to respond if (!Serial.find(">")) return -1;

  // Send our http request
  Serial.print(httpPacket);
  delay(10); // Wait a little for the ESP to respond
  String ch;
  ch = Serial.readString();
  Serial.println(ch);
  int point  = 0;
  for(int i = 0 ;i<500 ; i++)
  {
    if(ch[i]=='x')	
    {
      
      point  = i+1;
      break;
    
    }
  }
  Serial.println(ch[point]);
 // Serial.println("yoyo");
  //Serial.println(ch[point]);
  if(ch[point]=='n')
  {
    Serial.println("No mask");
   // digitalWrite(motor,LOW);
    //digitalWrite(red,HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("No mask no entry");
    lcd.setCursor(0,1);
    lcd.print("Please wear mask");
    delay(2000);
    
  }
  else if (ch[point]=='m')
  {
    Serial.println("Mask is detected");
    //digitalWrite(motor,HIGH);
    //digitalWrite(red,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You are masked");
    lcd.setCursor(0,1);
    lcd.print("Entry is granted");
    delay(2000);
    
  }
  else{
    Serial.println("Please scan");
    //digitalWrite(motor,LOW);
    //digitalWrite(red,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please scan ");
    lcd.setCursor(0,1);
    lcd.print("Yourself");
    delay(2000);
  }
  if (!Serial.find("SEND OK\r\n")) return;
  
  
}

volatile boolean handPresent;
volatile boolean isPouring;
volatile int seconds;
volatile int buttonState = 0;


void setup() {
  
  setupESP8266();
 
  analogWrite(10,Contrast);
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(alertPin,OUTPUT);
  handPresent = false;
 // Serial.begin(115200);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(buttonPin), interrupt, CHANGE);
}

void loop() {
  delay(10);
  buttonState = digitalRead(buttonPin);
  //to measure distance
  if (measureDistance()<30){
    handPresent=true;
    pour();
    temp_detect();
    removeHand();
    delay(100);
    mask_detect();
    delay(100);
    
  }
  else{  
  stopPump();
  }
  delay(50);
  
}

void printReady(){
  lcd.setCursor(0, 0);
lcd.print("dispenser           ");
  lcd.setCursor(0, 1);
  lcd.print("*****Ready******");
}
void printBusy(int temperature,int count){
 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("count:");
  lcd.print(count);

   lcd.print(" temp:");
  lcd.print(temperature);
  lcd.print("C");
  
  lcd.setCursor(0, 1);
  lcd.print("*****Busy*********");
}

void removeHand(){
 
    digitalWrite(motorPin, LOW);
    lcd.setCursor(0, 0);
lcd.print("Please remove   ");
  lcd.setCursor(0, 1);
  lcd.print("Your Hand!!!        ");

  if(measureDistance()<30)
  {
    removeHand();
  }
  
}
void temp_detect()
{
   temperature=analogRead(A0);
  
   float tempC=(temperature*4.88)/10 -50;
  Serial.print("TEMPERATURE in CELSIUS=");
  Serial.println(tempC);
  if(tempC>=37)
  {
    digitalWrite(alertPin,HIGH);
  }
  else{
    digitalWrite(alertPin,LOW);
  }
  printBusy(tempC,count);
  anydata_temp(tempC);
  //delay(10000);
  delay(1500);
 
  // printBusy(temperature,count);
}
//pour function
void pour(){
count=count+1;
digitalWrite(motorPin, HIGH);

  delay(500);
 
}
void stopPump(){
  
    digitalWrite(motorPin, LOW);
    printReady();
}
void interrupt(){
 
    digitalWrite(motorPin, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Interrupted!!!  ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(3000);
    lcd.clear();
 
     removeHand();

}

void mask_detect()
{
  anydata_mask();
}
//distance measure function
volatile int measureDistance(){
  volatile long duration;
  volatile int distance=100;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculate the distance:
  distance= duration*0.034/2;
  // Print the distance on the Serial Monitor:
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}
