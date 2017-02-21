
#include <Wire.h>
#include <BH1750.h>




BH1750 lightMeter(0x23);


int fotosensor=A0;         


unsigned long pauzastart;
unsigned long signalstart;


boolean didadd;
boolean didprint;
boolean nosignal;

int previus;
int receptor;
int delta=0;
int timer=1;
int pauza=0;

char temp;
String morze="";
void setup(){

  Serial.begin(9600);
 lightMeter.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);
 

}


void loop() {

  uint16_t signal = lightMeter.readLightLevel();
 //Serial.println(signal);

 if ((signal>20000) && (previus<2000))
 {
  signalstart=millis();
 didprint=false;
 didadd=false;
 pauza=0;
 //Serial.println("swe got signa"); 
  
  }
  else if ((signal<1000) && (previus>20000))
  {
    timer=millis()-signalstart;
      //Serial.println("si ziv");
     if ((timer<980) && (timer>1020))              //buffer
       {
        temp='*';     
       }
        else if ((timer<1980) && (timer>2020))    //buffer value of 20ms to avoid 
        {
          temp='-';
         }
         Serial.println(timer);
      timer=0;
  pauzastart=millis();
  nosignal=true;
    
  }

  
  if (nosignal)
    {
     pauza=millis()-pauzastart;
     
         if ((pauza>180) && (didadd=false)) 
             {
               morze=morze+temp;
              didadd=true;
             }
             if ((pauza>480) && (didprint=false))
               {
                 printaj(morze);
                 didprint=true;
               }
    }


  



    previus= signal;

delay(20);
  
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
