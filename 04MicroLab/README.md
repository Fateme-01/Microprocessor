## آزمایش dancing light
## تجهیزات موردنیاز
* 5عدد led
* 6عدد مقاومت
* پوش باتن
* بورد آردوینو
* بردبورد
* سیم
## کد آزمایش
#define key1 digitalRed(A0)

void setup() 
{
 
 pinMode(A0, INPUT);
 
 pinMode(0, OUTPUT);
 
 pinMode(1, OUTPUT);
 
 pinMode(2, OUTPUT);
 
 pinMode(3, OUTPUT);
 
 pinMode(4, OUTPUT);
}

void loop() 
{

int i,a;

int dancinglight [ 6 ][ 5 ]=
{

  { 0 , 0 , 0 , 0 , 1 },
  
  { 0 , 0 , 0 , 1 , 1 },
  
  { 0 , 0 , 1 , 1 , 0 },
  
  { 0 , 1 , 1 , 0 , 0 },
  
  { 1 , 1 , 0 , 0 , 0 },
  
  { 1 , 0 , 0 , 0 , 0 },

};

if (key == 1)
{

  for (int a=0 ; a<=5 ; a++)
  {
  
    for (int i=0 ; i<=6 ; i++)
    
    digitalWrite (i , dancinglight [a][i] )
    
    delay(200)
  
  }

}

}
## توضیحات کد
* تابع setup
تعریف کلید: کلید key1 با استفاده از پایه A0 تعریف شده است. برای خواندن ورودی آن از دستور digitalRead استفاده می‌شود.
پیکربندی پین‌ها: تمامی پین‌های خروجی، شامل A0 و پین‌های 0 تا 5، به عنوان خروجی تنظیم شده‌اند تا به ترتیب چراغ‌ها را کنترل کنند.
* آرایه dancinglight
آرایه dancinglight شامل یک ماتریس با الگوهای روشن و خاموش شدن LED ها است. هر ردیف نشان‌دهنده حالت‌های مختلف LEDها است و به ترتیب اجرا می‌شود تا جلوه‌ی رقص نور ایجاد شود.
* تابع loop
در این بخش، با فشردن کلید (key1)، حلقه‌ای فعال می‌شود که به ترتیب، الگوهای dancinglight را اجرا می‌کند. هر حالت با تأخیر 50 میلی‌ثانیه‌ای نمایش داده می‌شود.
با استفاده از دستور digitalWrite و مقدارهای موجود در آرایه dancinglight، هر LED به ترتیب روشن و خاموش می‌شود.
با فشردن یک کلید (key1)، چراغ‌ها به ترتیب روشن و خاموش می‌شوند و جلوه‌ ای شبیه به رقص نور ایجاد می‌کنند.

