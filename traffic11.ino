#include <LiquidCrystal.h>
#include<SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
SoftwareSerial mySerial(2,3);
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN    7
#define LED_COUNT 4
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int buz =6;
int es=A0;
int ws=A3;
int ns=A2;
int ss=A1;
int rf1=5;
int x=0;
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int et,wt,nt,st;
int cnt=0,ecnt=0,wcnt=0,ncnt=0,scnt=0,sts=0,i=0;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
 mySerial.begin(9600);
  pinMode(rf1,INPUT);
  pinMode(es,INPUT);
  pinMode(ws,INPUT);
  pinMode(ns,INPUT);
  pinMode(ss,INPUT);
  pinMode(buz,OUTPUT);
  lcd.begin(16,2);
  lcd.print("  WELCOME");
   strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
strip.setBrightness(100);
   
   strip.setPixelColor(0, strip.Color(255,   0,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
  strip.show();            // Turn OFF all pixels ASAP
  
  
}
void loop() 
{

lcd.clear();
cnt=5+ecnt;
 et=ecnt;
 ecnt=0;
lcd.print("EAST :"+ String(cnt));
 
 for(i=cnt;i>0;i--)
 {
  lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(i);
   strip.setPixelColor(0, strip.Color(0,     255,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
   scan_rfid();
   
    for(int k=0;k<10;k++)
   {
   delay(100);
   scan(); 
   } 
 }
 cnt=5+ncnt;
  nt=ncnt;
 ncnt=0;
lcd.clear();
lcd.print("NORTH:"+ String(cnt));
 
 for(i=cnt;i>0;i--)
 {
    lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(i);
   strip.setPixelColor(0, strip.Color(255,   0,   0));
   strip.setPixelColor(1, strip.Color(0,   255,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
   scan_rfid();
   scan();
   for(int k=0;k<10;k++)
   {
   delay(100);
   scan(); 
   }
    
 }
 cnt=5+wcnt;
  wt=wcnt;
 wcnt=0;
lcd.clear();
lcd.print("WEST :"+ String(cnt));
 
 for(i=cnt;i>0;i--)
 {
    lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(i);
   strip.setPixelColor(0, strip.Color(255,   0,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(0,   255,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
   scan_rfid();
   for(int k=0;k<10;k++)
   {
   delay(100);
   scan(); 
   } 
 }
 cnt=5+scnt;
 st=scnt;
 scnt=0;
lcd.clear();
lcd.print("SOUTH:"+ String(cnt));
 
 for(i=cnt;i>0;i--)
 {
    lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(i);
   strip.setPixelColor(0, strip.Color(255,   0,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(0,   255,   0));  
   strip.show();
   scan_rfid();
      for(int k=0;k<10;k++)
   {
   delay(100);
   scan(); 
   }
 }

  mySerial.print("220270,CQPWY5PRWRNE17NH,0,0,SRC 24G,src@internet,"+String(et) + ","+String(wt)+","+String(nt)+","+String(st)+",0,\n");
  
  

}

 void scan_rfid()
 {
  if(Serial.available())
  {
    x=Serial.read();
  }
   
  if (x=='1' || x=='2' || x=='3' || x=='4') //change here the UID of the card/cards that you want to give access
  {
    if(x=='1')
    {
    digitalWrite(buz,1);
    sts=1;
    delay(1000);
    digitalWrite(buz,0);
    cnt=5+ecnt;
    lcd.clear();
    lcd.print("EAST :"+ String(cnt));

   strip.setPixelColor(0, strip.Color(0,     255,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
    }

    if(x=='2')
    {
    digitalWrite(buz,1);
    sts=1;
    delay(1000);
    digitalWrite(buz,0);
    cnt=5+wcnt;
    lcd.clear();
    lcd.print("WEST :"+ String(cnt));
       strip.setPixelColor(0, strip.Color(255,     0,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(0,   255,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
    }

    if(x=='3')
    {
    digitalWrite(buz,1);
    sts=1;
    delay(1000);
    digitalWrite(buz,0);
    cnt=5+scnt;
    lcd.clear();
    lcd.print("SOUTH:"+ String(cnt));
       strip.setPixelColor(0, strip.Color(255,     0,   0));
   strip.setPixelColor(1, strip.Color(255,   0,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(0,   255,   0));  
   strip.show();
    }

    if(x=='4')
    {
    digitalWrite(buz,1);
    sts=1;
    delay(1000);
    digitalWrite(buz,0);
    cnt=5+ncnt;
    lcd.clear();
    lcd.print("NORTH:"+ String(cnt));
       strip.setPixelColor(0, strip.Color(255,     0,   0));
   strip.setPixelColor(1, strip.Color(0,   255,   0));
   strip.setPixelColor(2, strip.Color(255,   0,   0));
   strip.setPixelColor(3, strip.Color(255,   0,   0));  
   strip.show();
    }

    x=2;
    
    lcd.setCursor(0,1);
    lcd.print("Emergency Vhcle");
 for(i=cnt;i>0;i--)
 {
    lcd.setCursor(6,0);
  lcd.print("   ");
  lcd.setCursor(6,0);
  lcd.print(i);

   delay(1000); 
 }
  
  }

   
 }

 void scan()
 {
  if(digitalRead(es)==0)
  {
    ecnt=ecnt+1;
  }

    if(digitalRead(ws)==0)
  {
    wcnt=wcnt+1;
  }

    if(digitalRead(ns)==0)
  {
    ncnt=ncnt+1;
  }

    if(digitalRead(ss)==0)
  {
    scnt=scnt+1;
  }
 }

 
