int fotosensor=A0;          // ubaci millis, duinonije sposoban
const int ledPin = 13;

int previus;
int receptor;
int delta=0;
int timer=1;
int pauza=0;
boolean countup=false;
boolean countdown=false;
boolean didprint;
boolean didprint2;
char temp;
String morze="";
void setup() 
{
 
Serial.begin(115200);
pinMode(ledPin, OUTPUT);
receptor=analogRead(fotosensor);
previus=receptor;
}

void loop() {
  receptor=analogRead(fotosensor);
  delta=abs(receptor-previus);
  if (timer>0)
  {
  Serial.println(timer);
  // Serial.println(pauza);
  if (delta>150)
  {
    Serial.println(delta);
    }
   
  }
  
  if ((delta>150) && (receptor>previus)) //value jump because of the laser signal
  {
    countup=true;             
    countdown=false;
    didprint=false;
    didprint2=false;
    pauza=0;
  }
   
    
    else if ((delta>150) && (previus>receptor))   //value dip due to the loss of signal from the laser
   {
    
      countup=false;
      countdown=true;
      digitalWrite(13, LOW); 
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
     
      
      else    //two coounters depending on if we are counting the length of the signal or the delay
      {
        if (countdown)
        {
        pauza=pauza+1;
        }
          else if (countup) 
            {
              timer=timer+1;
              digitalWrite(13, HIGH); 
            }
        }

  if ((pauza>48) && (didprint=false))   //did print is used to avoid printing the same letter more then once
    {
    morze=morze+temp;
    didprint=true;
    }
   if ((pauza>150) && (didprint2=false))  
      {
       printaj(morze);  //it would be optimal to use a LED screen to print the words instead of the serial print 
       didprint2=true;
      }                       
        

  previus=receptor;
  delay(1);
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

