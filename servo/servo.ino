#include <Servo.h>

Servo servo_under1;
Servo servo_under2;
Servo servo_ud;

bool servo_ud_flag = 0;
int servo_ud_max = 90, servo_ud_min = 10;


int servo_ud_fun(int servo_ud_now)
{
    if(servo_ud_now == servo_ud_max)
        servo_ud_flag = 1;
    if(servo_ud_now == servo_ud_min)
        servo_ud_flag = 0;

    if(servo_ud_flag)
    {
        servo_ud_now -= 1;
    }
    else
    {
        servo_ud_now += 1;
    }
    return servo_ud_now;
}

void setup()
{
    Serial.begin(9600);
    servo_under1.attach(9);
    servo_under2.attach(10);
    servo_ud.attach(11);
    //servo_under1.attach(9,500,2400);    //SG90脈衝寬度範圍是500到2400µs, pin 9 
    servo_under1.write(90);
    delay(20);
    servo_under2.write(90);
    delay(20);
    servo_ud.write(90);
    delay(3000);
}

void loop()
{

    int servo_ud_now = 90;
    //*以角度控制
    for(int i = 10;i <= 170;i++)
    {
        servo_under1.write(i);
        delay(20);
        servo_under2.write(i);
        delay(100);
        servo_ud_now = servo_ud_fun(servo_ud_now);
        servo_ud.write(servo_ud_now);
    }
    
    for(int i = 170;i >= 10;i--)
    {
        servo_under1.write(i);
        delay(20);
        servo_under2.write(i);
        delay(100);
        servo_ud_now = servo_ud_fun(servo_ud_now);
        servo_ud.write(servo_ud_now);
    }

    /*
    for(int i = 500; i <= 2400; i+=100)
    {
        servo_under1.writeMicroseconds(i); // 直接以脈衝寬度控制
        delay(300);
    }
    for(int i = 2400; i >= 500; i-=100)
    {
        servo_under1.writeMicroseconds(i);
        delay(300);
    }
    */

}
