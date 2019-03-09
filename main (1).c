#include <kipr/botball.h>

void forward()
{
	mav(1,1000);
    mav(2,1000);
}
void squareup()
{
	mav(1,500);
    mav(2,500);
}
int main()
{
	squareup();
    msleep(2000);
    forward();
    msleep(3000);
    return 0;
}
