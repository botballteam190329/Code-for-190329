/*

IDEAS AND STRATEGIES

Go aggresive for the items the other team can get easily in the beginning, either collecting them or knocking them down
Try and sweep poms for water point
PEOPLE and POWER LINES and GAS VALVE (and possibly WATER POMS)

________________________________________________________________________________________________________________________________

Pseudocode for DE Create
Drive out of base, turn towards the power lines
Square up to the power line area, use scoop to pick up downed power line
Shove power line towards connecting magnet
Do the same for the other side

Back up, turn around, go for the people, pick them up
Maybe pick up pom-poms on the way?


*/

#include <kipr/botball.h>

#define ARM_SERVO_PORT 3
#define ARM_RETRACTED 0
#define ARM_EXTENDED 1445
#define ARM_EXTENDED_HIGHER 1350
#define ARM_DOWN 2047

#define LEFT_LIGHT_SENSOR_PORT 5
#define LEFT_LIGHT_SENSOR_THRESH 3000 //200-3800
#define RIGHT_LIGHT_SENSOR_PORT 4
#define RIGHT_LIGHT_SENSOR_THRESH 3000 //200-3800


double bias; //variable to hold the calibration value

void arm_all();
void create_measured_turn_test();
void create_measured_drive(int distance,int speedLeft,int speedRight);
void line_square_up(int speed);

int main()
{
    printf("Print\n");
    msleep(250);
    arm_all();
    msleep(250);
    
    //square-back then line-square
    create_drive_direct(-100,-100);
    msleep(250);
    create_drive_direct(100,100);
    msleep(750);
    create_drive_direct(100,-100);
    msleep(1650);
    create_drive_direct(100,100);
    msleep(1000);
    line_square_up(25);
    msleep(500);
    
    //from homebase to powerlines
    create_drive_direct(180,200);
    msleep(3000);
    create_drive_direct(-85,100);
    msleep(1500);
    create_drive_direct(200,200);
    msleep(2500);
    return 0;
    
    line_square_up(-25);
    
    //prep arm, connect power line on far side in relation to homebase
    create_drive_direct(100,100);
    msleep(1750);
    set_servo_position(ARM_SERVO_PORT,ARM_DOWN);
    create_drive_direct(-75,-75);
    msleep(2000);

    create_stop();
    
 
    
	/*create_drive_direct(150,200);
    msleep(4000);
    create_drive_direct(60,100);
    msleep(2500);
    create_drive_direct(50,50);
    msleep(1000);
    printf("Program Finished.\n");
    */
    
    create_disconnect();
    disable_servos();
    return 0;
}

void arm_all()
{
    create_connect();
    create_full();
    enable_servos();
    set_servo_position(ARM_SERVO_PORT,ARM_RETRACTED);
    //cg();
    printf("Successfully Armed All.\n");
}

void create_measured_turn_test()
{
    set_create_total_angle(0);
    while (get_create_total_angle() >= -360)
    {
        create_drive_direct(50, -50);
    }
    create_stop();
    //printf(get_create_total_angle());
}

void create_measured_drive(int distance,int speedLeft,int speedRight)
{
    set_create_distance(0);
    while (get_create_distance() < 1000)
        {
            create_drive_direct(200, 200);
        }
    create_stop();
}

void line_square_up(int speed)
{
    while (analog(LEFT_LIGHT_SENSOR_PORT) < LEFT_LIGHT_SENSOR_THRESH && analog(RIGHT_LIGHT_SENSOR_PORT) < RIGHT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(speed, speed);
    }
    create_stop();
    while (analog(LEFT_LIGHT_SENSOR_PORT) < LEFT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(speed,0);
    }
    create_stop();
    while (analog(RIGHT_LIGHT_SENSOR_PORT) < RIGHT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(0,speed);
    }
    create_stop();
    while (analog(LEFT_LIGHT_SENSOR_PORT) > LEFT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(-speed,0);
    }
    create_stop();
    while (analog(RIGHT_LIGHT_SENSOR_PORT) > RIGHT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(0,-speed);
    }
    create_stop();
}