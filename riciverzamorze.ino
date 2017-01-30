int fotosensor=A0;          // ubaci millis, duinonije sposoban
const int ledPin = 13;

unsigned long pauzastart;
unsigned long firstsignal;
unsigned long lastsignal;

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
void setup() 
{
 
Serial.begin(115200);
pinMode(ledPin, OUTPUT);
receptor=analogRead(fotosensor);
previus=receptor;
nosignal=false;
}

void loop() {
  receptor=analogRead(fotosensor);
  delta=abs(receptor-previus);
 
   
  
  
  if ((delta>150) && (receptor>previus)) //value jump because of the laser signal
  {
    nosignal=false;
    didadd=false;
    didprint=false;
                   
    firstsignal=millis();
   
    pauza=0;
  }
   
    
    else if ((delta>150) && (previus>receptor))   //value dip due to the loss of signal from the laser
   {
      lastsignal=millis();
      timer=lastsignal-firstsignal;
      pauzastart=millis();
      nosignal=true;
      
      
     if ((timer<160) && (timer>140))              //buffer
       {
        temp='*';     
       }
        else if ((timer<460) && (timer>440))    //buffer value of 20ms to avoid 
        {
          temp='-';
         }
      timer=0;

      
    }

  

   if (nosignal)
    {
     pauza=pauzastart-millis();
     
         if ((pauza>48) && (didadd=false)) 
             {
               morze=morze+temp;
              didadd=true;
             }
   if ((pauza>150) && (didprint=false))
       {
       printaj(morze);
       didprint=true;
       }

      
    }
 

           
        

  previus=receptor;
 // delay(1); pitanje je da li je ovo potrebno
 
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
