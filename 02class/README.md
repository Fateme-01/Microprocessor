## آزمایش اول: روشن و خاموش کردن LED با Pushbotton
## تجهیزات مورد نیاز:
بورد Arduino uno
LED
دو مقاومت 220اهم
5عدد سیم
Push button
برد بورد
کابل USB
## کد آزمایش:
const int but = 2;  

const int led = 13;

int buttonstate = 0;

void setup() {

  pinMode(led, OUTPUT);
  
  pinMode(but, INPUT_PULLUP);
}

void loop() {
  
  buttonstate = digitalRead(but);
  
  if (buttonstate == HIGH) {
  
    digitalWrite(led , HIGH);
  } 
  else {
  
    digitalWrite(led , LOW);
  }
}
## توضیح آزمایش(قسمت سخت افزاری): پوش باتن را به صورت عمودی روی بردبورد متصل می کنیم.با دو عدد سیم یکی از پایه های پایینی آن را به پایه ی دو بردآردوینو و پایه ی پایینی بعدی را به 5ولت متصل می کنیم. پایه ی دیگر پوش باتن را به مقاومت وصل می کنیم و بعد مقاومت را به زمین وصل می کنیم.



