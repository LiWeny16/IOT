#include <ESP8266WiFi.h>       // 本程序使用 ESP8266WiFi库
#include <ESP8266WiFiMulti.h>  //  ESP8266WiFiMulti库
#include <ESP8266WebServer.h>  //  ESP8266WebServer库
#include <SoftwareSerial.h>
#include <string.h>

ESP8266WiFiMulti wifiMulti;  // 建立ESP8266WiFiMulti对象,对象名称是 'wifiMulti'
SoftwareSerial MySerialMySerial(D5, D6);

ESP8266WebServer esp8266_server(80);  // 建立网络服务器对象，该对象用于响应HTTP请求。监听端口（80）
String char_sum;
String string1;
String string1_last;
String string1_past;
String whichSwitch;
String stateSwitch;
void setup(void) {
  digitalWrite(LED_BUILTIN,1);
  Serial.begin(9600);  // 启动串口通讯
  MySerial.begin(9600);
  char_sum = "";
  string1 = "";
  string1_last = "";
  string1_past = "";
  pinMode(LED_BUILTIN, OUTPUT);  //设置内置LED引脚为输出模式以便控制LED

  wifiMulti.addAP("bigonion2Gk", "454888395");  // 将需要连接的一系列WiFi ID和密码输入这里
  wifiMulti.addAP("245k", "12345678");          // ESP8266-NodeMCU再启动后会扫描当前网络
  wifiMulti.addAP("onionPhone", "454888395");   // 环境查找是否有这里列出的WiFi ID。如果有
  Serial.println("Connecting ...");             // 则尝试使用此处存储的密码进行连接。

  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) {  // 此处的wifiMulti.run()是重点。通过wifiMulti.run()，NodeMCU将会在当前
    delay(1000);                             // 环境中搜索addAP函数所存储的WiFi。如果搜到多个存储的WiFi那么NodeMCU
    Serial.print(i++);
    Serial.print(' ');  // 将会连接信号最强的那一个WiFi信号。
  }                     // 一旦连接WiFI成功，wifiMulti.run()将会返回“WL_CONNECTED”。这也是
                        // 此处while循环判断是否跳出循环的条件。

  // WiFi连接成功后将通过串口监视器输出连接成功信息
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());  // 通过串口监视器输出连接的WiFi名称
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());  // 通过串口监视器输出ESP8266-NodeMCU的IP

  esp8266_server.begin();                           // 启动网站服务
  esp8266_server.on("/", HTTP_GET, handleRoot);     // 设置服务器根目录即'/'的函数'handleRoot'
  esp8266_server.on("/LED", HTTP_POST, handleLED);  // 设置处理LED控制请求的函数'handleLED'
  esp8266_server.onNotFound(handleNotFound);        // 设置处理404情况的函数'handleNotFound'

  esp8266_server.on("/getdata", HTTP_GET, handleData);
  esp8266_server.on("/switch", HTTP_GET, handleSwitch);


  Serial.println("HTTP esp8266_server started");  //  告知用户ESP8266网络服务功能已经启动
}

void loop(void) {
  if (MySerial.available() > 0)  //串口接收到数据
  {
    char b = MySerial.read();
    char_sum += b;
    if (b == '?') {
      string1_past = string1_last;
      string1_last = string1;
      string1 = char_sum;
      Serial.print(char_sum);
      char_sum = "";
    }
  }
  esp8266_server.handleClient();  // 检查http服务器访问
}
void handleSwitch() {
  esp8266_server.sendHeader("Access-Control-Allow-Origin", "*");
  esp8266_server.send(200, "text/plain", "test switch");
  // Serial.println("用户访问了总开关");
  // Serial.println("\n");
  // const String temp =esp8266_server.arg(1);
  // Serial.println(esp8266_server.arg(1));  //不懂为啥这个会乱码
  // Serial.println("\n");
  stateSwitch = esp8266_server.arg("a");
  whichSwitch = esp8266_server.arg("b");
  // Serial.println(whichSwitch);
  // if (whichSwitch == "0") {
  //   toggleLED();
  // }
  if (stateSwitch == "1") {  //状态：开
    if (whichSwitch == "0") {
      MySerial.print(0);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "1") {
      MySerial.print(1);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "2") {
      MySerial.print(2);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "3") {
      MySerial.print(3);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "4") {
      MySerial.print(4);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "5") {
      MySerial.print(5);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "6") {
      MySerial.print(6);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "7") {
      MySerial.print(7);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "8") {
      MySerial.print(8);
      MySerial.println("?");
      toggleLED();
    }
  }
  if (stateSwitch == "2") {  //状态：关
    if (whichSwitch == "0") {
      MySerial.print(20);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "1") {
      MySerial.print(21);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "2") {
      MySerial.print(22);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "3") {
      MySerial.print(23);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "4") {
      MySerial.print(24);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "5") {
      MySerial.print(25);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "6") {
      MySerial.print(26);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "7") {
      MySerial.print(27);
      MySerial.println("?");
      toggleLED();
    } else if (whichSwitch == "8") {
      MySerial.print(28);
      MySerial.println("?");
      toggleLED();
    }
  }

  // switch (whichSwitch) {
  //   case "0":
  //     Serial.print(0);
  //     toggleLED();
  //     break;
  //   case "1":
  //     Serial.print(1);
  //     toggleLED();
  //     break;
  //   case "2":
  //     Serial.print(2);
  //     toggleLED();
  //     break;
  //   case "3":
  //     Serial.print(3);
  //     toggleLED();
  //     break;
  // }
}

/*设置服务器根目录即'/'的函数'handleRoot'
  该函数的作用是每当有客户端访问NodeMCU服务器根目录时，
  NodeMCU都会向访问设备发送 HTTP 状态 200 (Ok) 这是send函数的第一个参数。
  同时NodeMCU还会向浏览器发送HTML代码，以下示例中send函数中第三个参数，
  也就是双引号中的内容就是NodeMCU发送的HTML代码。该代码可在网页中产生LED控制按钮。 
  当用户按下按钮时，浏览器将会向NodeMCU的/LED页面发送HTTP请求，请求方式为POST。
  NodeMCU接收到此请求后将会执行handleLED函数内容*/
void handleRoot() {
  esp8266_server.sendHeader("Access-Control-Allow-Origin", "*");
  esp8266_server.send(200, "text/html", sendHTML(string1));
}

void handleData() {
  esp8266_server.sendHeader("Access-Control-Allow-Origin", "*");
  esp8266_server.send(200, "text/html", sendData(string1, string1_last, string1_past));
}
void handleLED() {
  esp8266_server.sendHeader("Access-Control-Allow-Origin", "*");
  toggleLED();  // 改变LED的点亮或者熄灭状态
  // esp8266_server.sendHeader("Location", "/");            // 跳转回页面根目录
  // esp8266_server.send(303);                              // 发送Http相应代码303 跳转
}
void toggleLED() {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}
void handleNotFound() {
  esp8266_server.send(404, "text/plain", "404: Not found");  // 发送 HTTP 状态 404 (未找到页面) 并向浏览器发送文字 "404: Not found"
}




String sendHTML(String str) {
  String htmlCode = "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>";
  htmlCode += "\n<br>";
  htmlCode += str;
  return htmlCode;
}
String sendData(String str, String str1, String str2) {
  String htmlCode = "";
  htmlCode += str;
  htmlCode += ",";
  htmlCode += str1;
  htmlCode += ",";
  htmlCode += str2;
  return htmlCode;
}
