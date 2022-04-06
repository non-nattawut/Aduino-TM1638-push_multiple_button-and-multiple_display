/*จริงๆถ้าไม่ขี้เกียจก็ hardcode if หลายรอย if ได้*/
/* Code ชุดนี้ยังมีบัคบางส่วน หากกด 1-8 จะรันได้ถึงแค่เลข 5*/
/*หากกด >5 ปุ่ม แล้วมือหลุดจากปุ่มใดปุ่มหนึ่ง กดปุ่มต่อไป เลขจะไม่แสดงผลแล้ว*/

/*การกด 1 ปุ่ม แล้วไปกดอีกปุ่ม ให้ขึ้น >= 2 เลขขึ้นไป*/
/*แล้วทำการปล่อยปุ่มก่อนหน้า เลขที่แสดงจากกการกดปุ่มก่อนหน้าจะไม่หายไป*/

#include <TM1638plus.h>

#define Brd_STB 5
#define Brd_CLK 18
#define Brd_DIO 19 
bool high_freq = true;

TM1638plus tm(Brd_STB, Brd_CLK , Brd_DIO, high_freq);

void setup() {
  Serial.begin(115200);
  tm.displayBegin();

}

int prev=0;
int current_sw=0,count = 0;
int sw1=0,sw2=0,sw3=0,sw4=0,sw5=0,sw6=0,sw7=0,sw8=0;
void loop() {
  int SwInput = tm.readButtons();
  Serial.print("Switch Input = ");
  Serial.println(SwInput,HEX);
  //current_sw = SwInput - current_sw - sw2;
  if(count == 0){
    current_sw = SwInput;
    sw1 = current_sw;
    prev = SwInput;
    count++;
  }
  else if(count == 1 && prev!=SwInput){
    current_sw = SwInput - sw1;
    sw2 = current_sw;
    prev = SwInput;
    count++;
  }else if(count == 2 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2;
    sw3 = current_sw;
    prev = SwInput;
    count++;
  }
  else if(count == 3 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2 - sw3;
    sw4 = current_sw;
    prev = SwInput;
    count++;
  }else if(count == 4 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2 - sw3 - sw4;
    sw5 = current_sw;
    prev = SwInput;
    count++;
  }else if(count == 5 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2 - sw3 - sw4 - sw5;
    sw6 = current_sw;
    prev = SwInput;
    count++;
  }else if(count == 6 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2 - sw3 - sw4 - sw5 - sw6;
    sw7 = current_sw;
    prev = SwInput;
    count++;
  }else if(count == 7 && prev!=SwInput){
    current_sw = SwInput - sw1 - sw2 - sw3 - sw4 - sw5 - sw6 - sw7;
    sw8 = current_sw;
    prev = SwInput;
    count++;
  }
  /*--------*/
  if(SwInput == 0x00){
    count = 0; current_sw = 0;
    tm.setLED(0, 0); tm.setLED(1, 0);
    tm.setLED(2, 0); tm.setLED(3, 0);
    tm.setLED(4, 0); tm.setLED(5, 0);
    tm.setLED(6, 0); tm.setLED(7, 0);
    tm.display7Seg(0, 0x40);
    tm.display7Seg(1, 0x40);
    tm.display7Seg(2, 0x40);
    tm.display7Seg(3, 0x40);
    tm.display7Seg(4, 0x40);
    tm.display7Seg(5, 0x40);
    tm.display7Seg(6, 0x40);
    tm.display7Seg(7, 0x40);
  }

  /*1-8 and LED*/
  if (current_sw == 0x01){
    tm.displayHex(0, 1);
    tm.setLED(0, 1);
  }
  if (current_sw == 0x02){
    tm.displayHex(1, 2);
    tm.setLED(1, 1);
  }
  if (current_sw == 0x04){
    tm.displayHex(2, 3);
    tm.setLED(2, 1);
  }
  if (current_sw == 0x08){
    tm.displayHex(3, 4);
    tm.setLED(3, 1);
  }
  if (current_sw == 0x10){
    tm.displayHex(4, 5);
    tm.setLED(4, 1);
  }
  if (current_sw == 0x20){
    tm.displayHex(5, 6);
    tm.setLED(5, 1);
  }
  if (current_sw == 0x40){
    tm.displayHex(6, 7);
    tm.setLED(6, 1);
  }
  if (current_sw == 0x80){
    tm.displayHex(7, 8);
    tm.setLED(7, 1);
  }
  //count == 2;
}
