#include <Servo.h>

Servo servo_under1;
Servo servo_under2;
Servo servo_ud;

bool servo_ud_flag = 0;
int servo_ud_max = 90, servo_ud_min = 10;
int servo_ud_now = 90;
bool servo_under1_flag = 0, servo_under2_flag = 0;
int servo_under_max = 170, servo_under_min = 10;
int servo_under1_now = 90, servo_under2_now 90;

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

int servo_fun(int servo_now, int servo_max, int servo_min, bool *servo_flag)
{
    if(servo_now == servo_max)
        *servo_flag = 1;
    if(servo_now == servo_min)
        *servo_flag = 0;

    if(*servo_flag)
    {
        servo_now -= 1;
    }
    else
    {
        servo_now += 1;
    }
    return servo_now;
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
    servo_under1_now = servo_fun(servo_under1_now, servo_under_max, servo_under_min, &servo_under1_flag);
    servo_under1.write(servo_under1_now);

    servo_under2_now = servo_fun(servo_under2_now, servo_under_max, servo_under_min, &servo_under2_flag);
    servo_under2.write(servo_under2_now);

    servo_ud_now = servo_ud_fun(servo_ud_now);
    servo_ud.write(servo_ud_now);
}
