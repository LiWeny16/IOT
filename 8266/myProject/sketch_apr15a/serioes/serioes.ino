#include <SoftwareSerial.h>

//自定义串口 (RX, TX)
SoftwareSerial MySerial(D5, D6);
SoftwareSerial MySerial2(D1, D2);
String char_Sum;
void setup() {
  Serial.begin(9600);
  MySerial.begin(9600);
  MySerial2.begin(9600);
  Serial.println("\n success");
}

void loop() {
  delay(100);
  // const char* data_Char = "1234567a";
  // const int data_Int =114514;
  // MySerial2.print(data_Char);
  // if (MySerial.available() > 0) {
  //   Serial.print(MySerial.read());
  // }
  // if (MySerial.available() > 0) {
  //   char b = MySerial.read();
  //   sum += b;
  //   if ((char)b == 'a') {
  //     Serial.print(sum);
  //     sum = "";
  //   }
  //   // int data_Int=MySerial.read();
  // }
  if (MySerial.available() > 0)  //串口接收到数据
  {
    char b = MySerial.read();
    char_Sum += b;
    if(b=='?'){
      Serial.print(char_Sum);  //输出等待的字符数
      char_Sum="";
    }
  }
}