int gor = 8;
int dol = 9;
int stopButton = 10;
int limiter = 11;
int green = 12;
int red = 13;
int low = 0;
int high = 10000;
int counter = 5000;
String state = "stopped";


void setup() {
  pinMode(gor,INPUT);
  pinMode(dol,INPUT);
  pinMode(stopButton,INPUT);
  pinMode(limiter,INPUT);
  pinMode(green,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(gor)==HIGH){
    state="rising";
  }
  if(digitalRead(dol)==HIGH){
    state="falling";
  }
  if(digitalRead(stopButton)==HIGH){
    state="stopped";
  }
  if(digitalRead(limiter)==HIGH){
    if(state=="rising"){
      state="stopped";
      high=counter;
    }
    else if(state=="falling"){
      state="stopped";
      low=counter;
    }
  }
  
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
 
  if(state=="rising"){
    if(counter<high){
        digitalWrite(green,HIGH);
        counter++;
    }
  }
  else if(state=="falling"){
    if(counter>low){
        digitalWrite(red,HIGH);
        counter--;
    }
  }
  if(counter>=high){
    state="stopped";
  }
  if(counter<=low){
    state="stopped";
  }
  Serial.print(state+" "+low+" "+high+" "+counter+"    ");
  delay(10);
}
