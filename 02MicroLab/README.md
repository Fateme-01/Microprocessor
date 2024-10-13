## آزمایش اول: دو LED همزمان و با تناوب یک ثانیه روشن باشند.
## تجهیزات مورد نیاز:
* بورد Arduino uno
  * دوعدد LED
  * دو مقاومت 220اهم
  * 5عدد جامپر
  * برد بورد
  * کابل USB
    ## کد آزمایش:
    int led = 13;
    
int LED = 12;

void setup() {

 pinMode (led, OUTPUT);
 
 pinMode (LED, OUTPUT);

}

void loop() {

digitalWrite (led, HIGH);

delay (1000);

digitalWrite (LED, HIGH);

delay (1000);

}
## توضیح کد: 

##
