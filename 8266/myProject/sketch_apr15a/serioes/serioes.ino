#include <SoftwareSerial.h>

//自定义串口 (RX, TX)
SoftwareSerial MySerial(D5, D6);
SoftwareSerial MySerial2(D1, D2);
int led = 2;
int send = 1;
String char_Sum;
String char_Sum2;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  MySerial.begin(9600);
  MySerial2.begin(9600);
  Serial.println("\n success");
  MySerial.println("\n success");
}

void loop() {
  delay(500);
  send = !send;
  MySerial.print(send);
  Serial.print(send);





  digitalWrite(led, !digitalRead(led));

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
  MySerial2.listen();
  if (MySerial2.available() > 0)  //串口接收到数据
  {
    char b = MySerial2.read();
    char_Sum2 += b;
    if (b) {
      char_Sum2 = char_Sum2 + "wow?";
      Serial.print(char_Sum2);  //输出等待的字符数
      char_Sum2 = "";
    }
  }
  MySerial.listen();
  if (MySerial.available() > 0)  //串口接收到数据
  {
    char b = MySerial.read();
    char_Sum += b;
    if (b) {
      char_Sum = char_Sum;
      //MySerial.print(char_Sum);  //输出等待的字符数
      Serial.print(char_Sum);
      char_Sum = "";
    }
  }
}