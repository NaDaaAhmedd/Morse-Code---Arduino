/*assigment3*/
 
char english[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                  'M', 'N', 'O','P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 
                  'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8','9','0',
                  ',', '.', '?' };
String morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                ".---", "-.-", ".-..", "--", "-.", "---", ".---.", "--.-", ".-.",
                "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----",
                "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                "-----", "--..--", ".-.-.-", "..--.." };
void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}
 
 
void loop() {
  while(Serial.available() == 0);
 String y = Serial.readString();
 for(int i=0; i<y.length()-1;i++){
  if(y.charAt(i) == ' '){
    delay(7000);
  }
  else {
   int n = getindex(y.charAt(i));
   morseSplit(morse[n]);
   if(i!=y.length()-2&&y.charAt(i+1)!=' '){
    delay(3000);
  }}
 }
 while(Serial.available() > 0){
    Serial.read();
  }
}
 
int getindex(char c){
  for(int i=0;i<39;i++){
    if (english[i] == c){ 
      return i;
    }
  }
  }       
 
void morseAnalysis(char c){
  if (c == '.' || c == ' '){
    Blink(1);
  }
  else if (c == '-'){
  Blink(3);
  }
}
void Blink(int d){
      digitalWrite(13,HIGH);
delay(d*500);
    digitalWrite(13,LOW);
    delay(200);
}
 
void morseSplit(String s){
  for (int i =0; i<s.length();i++){
    morseAnalysis(s.charAt(i));
    if(i!=s.length()-1&&((s.charAt(i)=='.'&&s.charAt(i+1)=='-')||(s.charAt(i)=='-'&&s.charAt(i+1)=='.')))
    morseAnalysis(' ');
  }
}
