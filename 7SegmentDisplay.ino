// 2 digits 7-Segment-Display with common anode
//define the pins for the cathodes:
int a = 10;
int b = 9;
int c = 2;
int d = 4;
int e = 3;
int f = 6;
int g = 5;

int Dig1 = 7;
int Dig2 = 8;

int counter, units, tenths;
int Seg_Array[7] = {a,b,c,d,e,f,g};

void setup() {
  int i;
  counter = 0;  
  for( i = 0; i<7;i++){
    pinMode(Seg_Array[i], OUTPUT);
  } 
  pinMode(Dig1, OUTPUT);
  pinMode(Dig2, OUTPUT);
  Null();
  //Serial.begin(9600);
}

void loop() {
 unsigned long start_time;
 for(counter = 99; counter >= 0;counter--){  
    tenths = int(counter/10);
    units = int(counter%10);
    /*Serial.print("tenths:");
    Serial.println(tenths);
    Serial.print("Units:");
    Serial.println(units);*/
    start_time = millis(); 
    for(unsigned long t_elapsed = 0; t_elapsed < 800; t_elapsed = millis()-start_time){
      show_tenths(tenths);
      delay(10);
      show_units(units);
      delay(10);
      }   
  }
}

void Null(){
  for(int i = 0; i<7;i++){
    digitalWrite(Seg_Array[i],HIGH);
  }
}

void show_tenths(int digit)
{
  digitalWrite(Dig1, LOW);
  digitalWrite(Dig2, HIGH);
  show_Digit(digit);
}

void show_units(int digit)
{
  digitalWrite(Dig1, HIGH);
  digitalWrite(Dig2, LOW);
  show_Digit(digit);
}

void show_Digit(int digit)
{int i;
  switch (digit){
     case 0:
       for( i = 0; i < 6; i++){
         digitalWrite(Seg_Array[i],LOW);
       }
       digitalWrite(Seg_Array[6],HIGH);
       break;
     case 1:
       Null();
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[2],LOW);
       break;
     case 2:
        Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[6],LOW);
       digitalWrite(Seg_Array[4],LOW);
       digitalWrite(Seg_Array[3],LOW);
       break; 
     case 3:
       Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[6],LOW);
       digitalWrite(Seg_Array[2],LOW);
       digitalWrite(Seg_Array[3],LOW);
       break; 
     case 4:
       Null();
       digitalWrite(Seg_Array[5],LOW);
       digitalWrite(Seg_Array[6],LOW);
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[2],LOW);
       break; 
     case 5:
       Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[5],LOW);
       digitalWrite(Seg_Array[6],LOW);
       digitalWrite(Seg_Array[2],LOW);
       digitalWrite(Seg_Array[3],LOW);
       break; 
     case 6:
       Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[5],LOW);
       digitalWrite(Seg_Array[4],LOW);
       digitalWrite(Seg_Array[3],LOW);
       digitalWrite(Seg_Array[2],LOW);
       digitalWrite(Seg_Array[6],LOW);
       break;  
     case 7:
       Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[2],LOW);
       break;  
     case 8:
       for(i = 0; i<7;i++){
         digitalWrite(Seg_Array[i],LOW);
       }
       break; 
     case 9:
       Null();
       digitalWrite(Seg_Array[0],LOW);
       digitalWrite(Seg_Array[1],LOW);
       digitalWrite(Seg_Array[2],LOW);
       digitalWrite(Seg_Array[3],LOW);
       digitalWrite(Seg_Array[5],LOW);
       digitalWrite(Seg_Array[6],LOW);
       break;    
     default:
       Null();
       break;              
  }
  
}
/* Alternative fuction to dispaly a digit:
void Display_Num(int digit){
  if((digit != 1)||(digit != 4))
     {Null();
     digitalWrite(Seg_Array[0],LOW);}
  else if ((digit != 5)||(digit != 6))
     { Null();
     digitalWrite(Seg_Array[1],LOW);}
  else if ((digit != 2))
     { Null();
     digitalWrite(Seg_Array[2],LOW);}   
  else if ((digit != 1)||(digit != 4)||(digit != 7))
     {Null(); 
     digitalWrite(Seg_Array[3],LOW);} 
  else if ((digit == 0)||(digit == 2)||(digit == 6)||(digit == 8))
     {Null(); 
     digitalWrite(Seg_Array[4],LOW);}
  else if ((digit != 1)||(digit != 2)||(digit != 3)||(digit != 7))
     {Null(); 
     digitalWrite(Seg_Array[5],LOW);}   
  else if ((digit != 0)||(digit != 1)||(digit != 2)||(digit != 7))
     {Null(); 
     digitalWrite(Seg_Array[6],LOW);}        
}
*/
