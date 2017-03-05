#include <Wire.h>
#include <BH1750.h>




BH1750 lightMeter(0x23);


int fotosensor=A0;         

extern volatile unsigned long timer0_millis;
unsigned long new_value = 0;

unsigned long pauzastart;
unsigned long signalstart;
unsigned long pauza=0;

boolean didadd;
boolean didprint;
boolean nosignal;

int previus;
int receptor;
int delta=0;
int timer=1;


char temp;
String morze="";
void setup(){

  Serial.begin(9600);
 lightMeter.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);
 didprint=false;
 didadd=false;
 pauza=0;
 nosignal=false;

}


void loop() {

  uint16_t signal = lightMeter.readLightLevel();
 //Serial.println(signal);

 if ((signal>10) && (previus<10))
 {
  signalstart=millis();
 didprint=false;
 didadd=false;
      Serial.println(pauza);

 pauza=0;
 nosignal=false;
 //Serial.println("swe got signa"); 
  
  }
  else if ((signal<10) && (previus>10))
  {
                 

    timer=millis()-signalstart;
      //Serial.println("si ziv");
     if ((timer>900) && (timer<1100))              //buffer
       {
        temp='*';     
       }
        else if ((timer>1900) && (timer<2100))    //buffer value of 20ms to avoid 
        {
          temp='-';
         }
         // Serial.print("timer");
       //  Serial.println(timer);
            //  Serial.println(temp);

      timer=0;
 //pauzastart=millis();
  setMillis(0);
  nosignal=true;
    
  }

  
  if (nosignal)
    {
      pauza=millis();
     //pauza=millis()-pauzastart;
      //Serial.println(pauza);
     
         if ((pauza>130) && (didadd=false)) 
             {
               morze.concat(temp);
              didadd=true;
              Serial.println(morze);
             }
             if ((pauza>400) && (didprint=false))
               {
                 printaj(morze);
                 morze="";
                 didprint=true;
               }
    }


  



    previus=signal;

delay(30);
  
}

void printaj(String prevodilac)         //prevodilac=translator
{  

  if (prevodilac=="*-")
    Serial.print("A");
  else if (prevodilac=="-***")  
    Serial.print("B");
  else if (prevodilac=="-*-*")  
    Serial.print("C");
  else if (prevodilac=="-**")  
    Serial.print("D");
  else if (prevodilac=="*")  
    Serial.print("E");
  else if (prevodilac=="**-*")  
    Serial.print("F");
  else if (prevodilac=="--*")  
    Serial.print("G");
  else if (prevodilac=="****")  
    Serial.print("H");
  else if (prevodilac=="**")  
    Serial.print("I");
  else if (prevodilac=="*---")  
    Serial.print("J");
  else if (prevodilac=="-*-")  
    Serial.print("K");
  else if (prevodilac=="*-**")  
    Serial.print("L");
  else if (prevodilac=="--")  
    Serial.print("M");
  else if (prevodilac=="-*")  
    Serial.print("N");
  else if (prevodilac=="---")  
    Serial.print("O");
  else if (prevodilac=="*--*")  
    Serial.print("P");
  else if (prevodilac=="--*-")  
    Serial.print("Q");
  else if (prevodilac=="*-*")  
    Serial.print("R");
  else if (prevodilac=="***")  
    Serial.print("S");
  else if (prevodilac=="-")  
    Serial.print("T");
  else if (prevodilac=="**-")  
    Serial.print("U");
  else if (prevodilac=="***-")  
    Serial.print("V");
  else if (prevodilac=="*--")  
    Serial.print("W");
  else if (prevodilac=="-**-")  
    Serial.print("X");
  else if (prevodilac=="-*--")  
    Serial.print("Y");
  else if (prevodilac=="--**")  
    Serial.print("Z");

  else if (prevodilac=="*----")  
    Serial.print("1");
  else if (prevodilac=="**---")  
    Serial.print("2");
  else if (prevodilac=="***--")  
    Serial.print("3");
  else if (prevodilac=="****-")  
    Serial.print("4");
  else if (prevodilac=="*****")  
    Serial.print("5");
  else if (prevodilac=="-****")
    Serial.print("6");
  else if (prevodilac=="--***")  
    Serial.print("7");
  else if (prevodilac=="---**")  
    Serial.print("8");
  else if (prevodilac=="----*")  
    Serial.print("9");
  else if (prevodilac=="-----")  
    Serial.print("0");
  
  Serial.print(" ");
    
  prevodilac=""; 
}
void setMillis(unsigned long new_millis) {
    uint8_t oldSREG = SREG;
    cli();
    timer0_millis = new_millis;
    SREG = oldSREG;
}
