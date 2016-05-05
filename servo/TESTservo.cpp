#include <iostream>

using namespace std;

bool servo_ud_flag = 0;
int servo_ud_max = 90, servo_ud_min = 10;
int servo_ud_now = 90;
bool servo_under1_flag = 0, servo_under2_flag = 0;
int servo_under_max = 170, servo_under_min = 10;
int servo_under1_now = 90, servo_under2_now = 90;

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


int main()
{
    for(int i = 0;i < 1000;i++)
    {
        servo_under1_now = servo_fun(servo_under1_now, servo_under_max, servo_under_min, &servo_under1_flag);
        cout << servo_under1_now << " ";

        servo_under2_now = servo_fun(servo_under2_now, servo_under_max, servo_under_min, &servo_under2_flag);
        cout << servo_under2_now << " ";

        servo_ud_now = servo_fun(servo_ud_now, servo_ud_max, servo_ud_min, &servo_ud_flag);
        cout << servo_ud_now << endl;

    }
}
