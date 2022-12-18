//tanque vacio
const char c1[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000};
const char c2[8] PROGMEM = {B00001,B00001,B00001,B00001,B00001,B00001,B00001,B00001};
const char c3[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B01000,B00111};
const char c4[8] PROGMEM = {B00001,B00001,B00001,B00001,B00001,B00001,B00010,B11100};
const char c5[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111};


//Agua+tanque
const char BL10[8] PROGMEM ={B10000,B10000,B10000,B10000,B10111,B10111,B01111,B00111,}; //10% bottom left
const char BL20[8] PROGMEM ={B10000,B10000,B10111,B10111,B10111,B10111,B01111,B00111,}; //20% bottom left
const char BL30[8] PROGMEM ={B10111,B10111,B10111,B10111,B10111,B10111,B01111,B00111,}; //30% bottom left

const char BR10[8] PROGMEM ={B00001,B00001,B00001,B00001,B11101,B11101,B11110,B11100,}; //10% bottom rigth
const char BR20[8] PROGMEM ={B00001,B00001,B11101,B11101,B11101,B11101,B11110,B11100,}; //20% bottom rigth
const char BR30[8] PROGMEM ={B11101,B11101,B11101,B11101,B11101,B11101,B11110,B11100,}; //30% bottom rigth

const char BC10[8] PROGMEM ={B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111,}; //10% bottom center x2 
const char BC20[8] PROGMEM ={B00000,B00000,B11111,B11111,B11111,B11111,B11111,B11111,}; //20% bottom center x2
const char BC30[8] PROGMEM ={B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111,}; //30% bottom center x2

const char WL48[8] PROGMEM ={B10000,B10000,B10000,B10000,B10000,B10000,B10111,B10111,}; //40% y 80%  wall left
const char WL59[8] PROGMEM ={B10000,B10000,B10000,B10000,B10111,B10111,B10111,B10111,}; //50% y 90% wall left
const char WL61[8] PROGMEM ={B10000,B10000,B10111,B10111,B10111,B10111,B10111,B10111,}; //60% y 100% wall left
const char WL70[8] PROGMEM ={B10111,B10111,B10111,B10111,B10111,B10111,B10111,B10111,}; //70% wall left

const char WR48[8] PROGMEM ={B00001,B00001,B00001,B00001,B00001,B00001,B11101,B11101,}; //40% y 80% wall rigth
const char WR59[8] PROGMEM ={B00001,B00001,B00001,B00001,B11101,B11101,B11101,B11101,}; //50% y 90% wall rigth
const char WR61[8] PROGMEM ={B00001,B00001,B11101,B11101,B11101,B11101,B11101,B11101,}; //60% y 100% wall rigth
const char WR70[8] PROGMEM ={B11101,B11101,B11101,B11101,B11101,B11101,B11101,B11101,}; //70% wall rigth

const char C48[8] PROGMEM ={B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111,}; //40% y 80% center
const char C59[8] PROGMEM ={B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111,}; //50% y 90% center
const char C61[8] PROGMEM ={B00000,B00000,B11111,B11111,B11111,B11111,B11111,B11111,}; //60% y 100% center

//Porcientos de 10 en 10
void empty(){
//vacio
lcd.createChar(1 , c1);   
lcd.createChar(2 , c2);                              
lcd.createChar(3 , c3);
lcd.createChar(4 , c4);
lcd.createChar(5 , c5);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");  
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(1));
lcd.setCursor(16 ,3);
lcd.print(char(3));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(5));
lcd.setCursor(18 ,3);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(2));
lcd.setCursor(19 ,3);
lcd.print(char(4));
  }
void ten(){
  //lleno 10%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , BL10);
lcd.createChar(4 , BR10);
lcd.createChar(5 , BC10);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(1));
lcd.setCursor(16 ,3);
lcd.print(char(3));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(5));
lcd.setCursor(18 ,3);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(2));
lcd.setCursor(19 ,3);
lcd.print(char(4));
  }  
void twenty(){
//lleno 20%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , BL20);
lcd.createChar(4 , BR20);
lcd.createChar(5 , BC20);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(1));
lcd.setCursor(16 ,3);
lcd.print(char(3));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(5));
lcd.setCursor(18 ,3);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(2));
lcd.setCursor(19 ,3);
lcd.print(char(4));
  } 
void thirty(){
//lleno 30%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , BL30);
lcd.createChar(4 , BR30);
lcd.createChar(5 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(1));
lcd.setCursor(16 ,3);
lcd.print(char(3));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(5));
lcd.setCursor(18 ,3);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(2));
lcd.setCursor(19 ,3);
lcd.print(char(4));
  } 
void forty(){
//lleno 40%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , WL48);
lcd.createChar(4 , WR48);
lcd.createChar(5 , C48);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,2);
lcd.print(char(5));
lcd.setCursor(18 ,2);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));
 } 
void fifty(){ 
//lleno 50%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , WL59);
lcd.createChar(4 , WR59);
lcd.createChar(5 , C59);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    "); 
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,2);
lcd.print(char(5));
lcd.setCursor(18 ,2);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));
 } 
void sixty(){
//lleno 60% 
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , WL61);
lcd.createChar(4 , WR61);
lcd.createChar(5 , C61);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,2);
lcd.print(char(5));
lcd.setCursor(18 ,2);
lcd.print(char(5));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));         
}
void seventy(){
//lleno 70%
lcd.createChar(1 , c1);
lcd.createChar(2 , c2);
lcd.createChar(3 , WL70);
lcd.createChar(4 , WR70);
lcd.createChar(5 , BL30);
lcd.createChar(6 , BR30);
lcd.createChar(7 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
//wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(5));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(7));
lcd.setCursor(17 ,2);
lcd.print(char(7));
lcd.setCursor(18 ,2);
lcd.print(char(7));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(6));         
}
void eighty(){
//lleno 80%  
lcd.createChar(1 , WL48);
lcd.createChar(2 , WR48);
lcd.createChar(3 , WL70);
lcd.createChar(4 , WR70);
lcd.createChar(5 , C48);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30);
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
 //wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,1);
lcd.print(char(5));
lcd.setCursor(18 ,1);
lcd.print(char(5));
lcd.setCursor(17 ,2);
lcd.print(char(8));
lcd.setCursor(18 ,2);
lcd.print(char(8));

//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));     
}
void ninety(){
//lleno 90% 
lcd.createChar(1 , WL59);
lcd.createChar(2 , WR59);
lcd.createChar(3 , WL70);
lcd.createChar(4 , WR70);
lcd.createChar(5 , C59);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30); 
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    ");
 //wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,1);
lcd.print(char(5));
lcd.setCursor(18 ,1);
lcd.print(char(5));
lcd.setCursor(17 ,2);
lcd.print(char(8));
lcd.setCursor(18 ,2);
lcd.print(char(8));

//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));     
} 
void full(){
//lleno 100% 
lcd.createChar(1 , WL61);
lcd.createChar(2 , WR61);
lcd.createChar(3 , WL70);
lcd.createChar(4 , WR70);
lcd.createChar(5 , C61);
lcd.createChar(6 , BL30);
lcd.createChar(7 , BR30);
lcd.createChar(8 , BC30); 
lcd.setCursor(16 ,1);
lcd.print("    ");
lcd.setCursor(16 ,2);
lcd.print("    ");
lcd.setCursor(16 ,3);
lcd.print("    "); 
 //wall left
lcd.setCursor(16 ,1);
lcd.print(char(1));
lcd.setCursor(16 ,2);
lcd.print(char(3));
lcd.setCursor(16 ,3);
lcd.print(char(6));
//bottom
lcd.setCursor(17 ,3);
lcd.print(char(8));
lcd.setCursor(18 ,3);
lcd.print(char(8));
lcd.setCursor(17 ,1);
lcd.print(char(5));
lcd.setCursor(18 ,1);
lcd.print(char(5));
lcd.setCursor(17 ,2);
lcd.print(char(8));
lcd.setCursor(18 ,2);
lcd.print(char(8));
//wall rigth
lcd.setCursor(19 ,1);
lcd.print(char(2));
lcd.setCursor(19 ,2);
lcd.print(char(4));
lcd.setCursor(19 ,3);
lcd.print(char(7));
}