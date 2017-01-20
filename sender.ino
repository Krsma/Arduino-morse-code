String priv;
String prevod;
String slinger;
const int buzzer = 9;
char c;
char a;
int l;
int leng;
String database[26]{"*-","-***","-*-*","-**","*","**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-","*--","-**-","-*--","--**"};
void setup() {
Serial.begin(9600);  
pinMode(13,OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) 
  {
    priv=Serial.readString();
    l=priv.length();
    Serial.println(l);
    priv.toUpperCase(); // upcasing the whole string to avoid issuesm with undercase and upercase letters 
    Serial.println("Encoding and sending the message");
    for (int i=0; i<l; i++)
    {
  a=priv[i];
  translate(a); 
  delay(100);     // delay of 100ms to let the receiver code know that the transmition of the letter is over
    
    }
   Serial.println("Message sent"); 
  }

}


void translate(char b)        // comparing letters with the database array to find a string of * and - that coresponds to the letter
{
   prevod=database[b-'A'];
   leng=prevod.length();
   for (int k=0;k<leng;k++)
  {
    if (prevod[k]='*')
{
  digitalWrite(13, HIGH);   
  tone(buzzer, 2000);
  delay(200);
  digitalWrite(13,LOW);
  noTone(buzzer); 
  delay(50);
  }
if (prevod[k]='-')
{
  digitalWrite(13, HIGH);
  tone(buzzer, 2000);
  delay(450);
  noTone(buzzer);  
  digitalWrite(13,LOW);
  delay(50);
  }  
  
  
  }
  }




