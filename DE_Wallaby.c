#include <kipr/botball.h>

void forward()
{
	mav(0,-1475);
    mav(1,-1480);
}
void back()
{
	mav(0,1475);
    mav(1,1500);
}
void openclaw()
{
    set_servo_position(1,640);
    msleep(250);
    set_servo_position(1,550);
    msleep(250);
    set_servo_position(1,460);
}
void closeclaw()
{
    set_servo_position(1,550);
    msleep(250);
    set_servo_position(1,640);
    msleep(250);
    set_servo_position(1,730);   
}
void wait()
{
    msleep(500);   
}
void stop()
{
    mav(0,1);
    mav(1,1);
}
void right()
{
    mav(0,-1500);
    mav(1,1500);
}
void squareup()
{
    while (analog(4) < 2500 && analog(5) < 3100)
    {
        mav(0,-500);
        mav(1,-500);
    }
    stop();
    msleep(100);
    while (analog(4) < 2500)
    {
        mav(0,-100);
    }
    stop();
    msleep(100);
    while (analog(5) < 3100)
    {
        mav(1,-100);
    }
    stop();
    msleep(100);
    while (analog(4) > 2500)
    {
        mav(0,100);
    }
    stop();
    msleep(100); 
    while (analog(5) > 3100)
    {
        mav(1,100);
    }
    stop();
    msleep(100);
}
int main()
{
	//wait_for_light(1);
    enable_servos();
    closeclaw();
    //msleep(2000);
    //wait();
    //wait();
    //wait();
    //forward();
    //msleep(3800);
    //openclaw();
    //msleep(2000);
    //forward();
    //msleep(1900);
    //stop();
    //msleep(500);
    //wait();
    //closeclaw();
    //back();
    msleep(4000);
    stop(500);
    openclaw();
    back(5000);
    return 0;
}
