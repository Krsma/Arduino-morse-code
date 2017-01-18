int fotosensor=A0;
int previus;
int receptor;
int delta=0;
int timer=0;
int pauza=0;
boolean countup=false;
boolean countdown=false;
boolean didprint;
char temp;
String morze="";
void setup() 
{
 
Serial.begin(9600);
receptor=analogRead(fotosensor);
previus=receptor;
}

void loop() {
  receptor=analogRead(fotosensor);
  delta=abs(receptor-previus);
   //Serial.println(delta);
   
  if ((delta>150) && (receptor>previus)) //skok u vrednosti zbog lasera
  {
    countup=true;             // count up i countdown samo odredjuju da li brojimo duzinu izmedju signala ili duzinu samog signala
    countdown=false;
    didprint=false;
    pauza=0;
  }
   
    
    else if ((delta>150) && (previus>receptor))   //pad u vrednost ybog gubitka kontakta sa laserom
   {
      countup=false;
      countdown=true;
     if ((timer<160) && (timer>140)) //uzimamo za obzir sanse da dodje do loseg signala
       {
        temp='*';     
       }
        else if ((timer<460) && (timer>440))    //buffer u vrednosti od 20ms
        {
          temp='-';
         }
      timer=0;
     }
     
      
      else    //dva brojaca ya duzine pauze i duzine signala
      {
        if (countdown)
        {
        pauza=pauza+1;
        }
          else if (countup) 
            {
              timer=timer+1;
            }
        }

  if ((pauza>48) && (didprint=false))   //didprint se korisit da bi smo izbegli konstanto upisivanje temp chara u string
    {
    morze=morze+temp;
    didprint=true;
    }
   if (pauza>150)    //ovde bi trebalo yavrsavanje slova
      {
       printaj(morze);  // digital write slova na led scren bi bilo najbolje da se iybacio kompjuter ali ya sad radi ispisivanjem na terminal
      }                       
        

  previus=receptor;
  delay(1);
}
void printaj(String prevodilac)
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

