static int Bop=0;
static int Tilt=1;
static int Twist=0;
static int Speaker=3;
static int SevSeg[7]={4,5,6,7,8,9,10};
static int seg0[7]={1,1,1,1,1,1,0};
static int seg1[7]={0,1,1,0,0,0,0};
static int seg2[7]={1,1,0,1,1,0,1};
static int seg3[7]={1,1,1,1,0,0,1};
static int seg4[7]={0,1,1,0,0,1,1};
static int seg5[7]={1,0,1,1,0,1,1};
static int seg6[7]={0,0,1,1,1,1,1};
static int seg7[7]={1,1,1,0,0,0,0};
static int seg8[7]={1,1,1,1,1,1,1};
static int seg9[7]={1,1,1,0,0,1,1};
static int SegMode=2;
int state=0;
int diff=101;
int timer=10000;
int points=0;
int PrevTwist=0;
int dispMode=0;

void disp(int x){
  if(x==100){
    x=0;
  }
  int tens=x/10;
  int ones=x%10;
  
  if(dispMode==0){    //Display 10s digit
    dispMode=1;
    digitalWrite(SegMode,HIGH);
    switch(tens){
     case 0:
      for(int i=0;i<7;i++){
        if(seg0[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break; 
     case 1:
      for(int i=0;i<7;i++){
        if(seg1[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 2:
      for(int i=0;i<7;i++){
        if(seg2[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 3:
      for(int i=0;i<7;i++){
        if(seg3[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 4:
      for(int i=0;i<7;i++){
        if(seg4[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 5:
      for(int i=0;i<7;i++){
        if(seg5[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 6:
      for(int i=0;i<7;i++){
        if(seg6[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 7:
      for(int i=0;i<7;i++){
        if(seg7[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 8:
      for(int i=0;i<7;i++){
        if(seg8[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 9:
      for(int i=0;i<7;i++){
        if(seg9[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
    }
  }else{           //Display ones digit
    dispMode=0;
     digitalWrite(SegMode,LOW);
    switch(ones){
     case 0:
      for(int i=0;i<7;i++){
        if(seg0[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break; 
     case 1:
      for(int i=0;i<7;i++){
        if(seg1[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 2:
      for(int i=0;i<7;i++){
        if(seg2[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 3:
      for(int i=0;i<7;i++){
        if(seg3[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 4:
      for(int i=0;i<7;i++){
        if(seg4[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 5:
      for(int i=0;i<7;i++){
        if(seg5[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 6:
      for(int i=0;i<7;i++){
        if(seg6[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 7:
      for(int i=0;i<7;i++){
        if(seg7[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 8:
      for(int i=0;i<7;i++){
        if(seg8[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
     case 9:
      for(int i=0;i<7;i++){
        if(seg9[i]==1){
          digitalWrite(SevSeg[i],HIGH);
        }else{
          digitalWrite(SevSeg[i],LOW);
        }
      }
      break;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(Bop,INPUT);
  pinMode(Tilt,INPUT);
  pinMode(Speaker,OUTPUT);
  pinMode(SegMode,OUTPUT);
  for(int i=0;i<7;i++){
    pinMode(SevSeg[i],OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
 if(state==0){          //Start state
  if(digitalRead(Bop)==HIGH){
    state=1;            //Mover to choose task
    diff=101;           //Base difficulty, counts down with successful tasks
  }
  
 }else if(state==1){    //State to choose next action
    int pick=random(1,4);   //Select random task
    diff--;
    timer=diff*100;     //Timer decreases with successive tasks to increase difficulty
    if(pick==1){
      state=2;
    }else if(pick==2){
      state=3;
    }else if(pick==3){
      state=4;
    }
    if(points==100){    //Check for victory condition
      state=6;
    }
    disp(points);
    
 }else if(state==2){    //State for Bop It
  tone(Speaker,700,1000);
    while(timer>0){
      disp(points);
      if(digitalRead(Bop)==HIGH){
        points++;       //Iterate points on success
        state=1;
        break;
      }
      delay(1);
      timer--;
    }
    state=5;            //If the task is not completed, go to fail state
    
 }else if(state==3){    //State for Shake It
  tone(Speaker,500,1000);
    while(timer>0){
      disp(points);
      if(digitalRead(Tilt)==LOW){
        points++;       //Iterate points on success
        state=1;
        break;
      }
      delay(1);
      timer--;
    }
    state=5;            //If the task is not completed, go to fail state
  
 }else if(state==4){    //State for Twist It
  tone(Speaker,900,1000);
  PrevTwist=analogRead(Twist);
    while(timer>0){
      disp(points);
      if(analogRead(Twist)!=PrevTwist){
        points++;       //Iterate points on success
        state=1;
        break;
      }
      delay(1);
      timer--;
    }
    state=5;            //If the task is not completed, go to fail state

 }else if(state==5){    //State for failure
  disp(points);
  points=0;
  tone(Speaker,250);
  delay(1000);
  noTone(Speaker);
  disp(points);
  state=0;
 }else if(state==6){    //Victory State
  disp(points);
  points=00;
  tone(Speaker,2000);
  delay(1000);
  noTone(Speaker);
  disp(points);
  state=0;
 }
}
