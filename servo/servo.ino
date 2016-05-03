#include <Servo.h>

Servo servo_under1;
Servo servo_under2;
Servo servo_ud;


void setup()
{
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
    

    //*以角度控制
    for(int i = 10;i <= 170;i++)
    {
        servo_under1.write(i);
        delay(20);
        servo_under2.write(i);
        delay(100);
    }
    
    for(int i = 170;i >= 10;i--)
    {
        servo_under1.write(i);
        delay(20);
        servo_under2.write(i);
        delay(100);
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
