String priv;
String prevod;
String slinger;
const int buzzer = 9;
char c;
char a;
int l;
int leng;
String database[26]{"*-","-***","-*-*","-**","*","**-*","--*","****","**","*---","-*-","*-**","--","-*","---","*--*","--*-","*-*","***","-","**-","***-","*--","-**-","-*--","--**"};// database[ktia-'A']
void setup() {
Serial.begin(9600);  // put your setup code here, to run once:
pinMode(13,OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {

  if (Serial.available() > 0) 
  {
    priv=Serial.readString();
    l=priv.length();
    Serial.println(l);
    priv.toUpperCase();
   
    for (int i=0; i<l; i++)
{
  a=priv[i];
  translate(a);
  delay(100);
    
    }
    
  }

}


void translate(char b)        //treba samo zameniti mesta ovom sranju a za to nemam zivaca
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




