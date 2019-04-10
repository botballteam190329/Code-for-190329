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

#define ARM_SERVO_PORT 0   
#define ARM_RETRACTED 0
#define ARM_EXTENDED 1425
#define ARM_EXTENDED_HIGHER 1400
#define ARM_DOWN 2047
#define ARM_START 1814

#define CLAW_ARM_SERVO_PORT 3
#define CLAW_ARM_RETRACTED 1900
#define CLAW_ARM_UP 1300
#define CLAW_ARM_EXTENDED 207
#define CLAW_ARM_EXTENDED_FURTHER 0

#define CLAW_SERVO_PORT 2
#define CLAW_OPEN 900
#define CLAW_OPEN_WIDE 1900
#define CLAW_CLOSED 200

#define LEFT_LIGHT_SENSOR_PORT 5
#define LEFT_LIGHT_SENSOR_THRESH 1200 //200-3800
#define RIGHT_LIGHT_SENSOR_PORT 4
#define RIGHT_LIGHT_SENSOR_THRESH 1200 //200-3800

#define LIGHT_START_PORT 2

double bias; //variable to hold the calibration value

void arm_all();
void create_measured_turn_test();
void create_measured_drive(int distance, int speedLeft, int speedRight);
void line_square_up(int speed);
void drive_until_bump(int speed);
void slow_servo(int servoPort, int currentPosition, int finishPosition);

int main()
{

    printf("START\n");
    arm_all();
    msleep(1000);
   	wait_for_light(LIGHT_START_PORT); //put wait-for-light crap here
    shut_down_in(119);
    //msleep(5000);

    //start with the arm down, then extend it HERE
    set_servo_position(CLAW_ARM_SERVO_PORT, CLAW_ARM_UP);
    msleep(500);
    set_servo_position(ARM_SERVO_PORT, ARM_RETRACTED);

    //line-square, then square-back
    create_drive_direct(-100, -100);
    msleep(2000);
    line_square_up(-25);
    create_drive_direct(100, -100);
    msleep(3300);
    create_drive_direct(-100, -100);
    msleep(2900);

    //END OF BEGINING
    create_drive_direct(100, 100);
    msleep(750);
    create_drive_direct(100, -100);
    msleep(1650);
    create_drive_direct(100, 100);
    msleep(1000);
    line_square_up(25);
    msleep(500);
    ////BIG ARC ADDITION
    create_drive_direct(50,50);
    msleep(300);

    //from homebase to powerlines (BIG ARC)
    create_drive_direct(170, 200);
    msleep(3150);
    create_drive_direct(-85, 100);
    msleep(1400);
    create_drive_direct(200, 200);
    msleep(2300);

    line_square_up(-25);

    //prep arm, connect power line on far side in relation to homebase
    create_drive_direct(100, 100);
    msleep(1750);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_DOWN);
    msleep(1000);
    create_drive_direct(-100, -100);
    msleep(1500);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED);
    create_drive_direct(100, 100);
    msleep(1650);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED_HIGHER);
    drive_until_bump(75);
    create_stop();
    //CONECTED FIRST POWELINE
    create_drive_direct(-100, -100);
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED);
    msleep(2500); //EDITED HEERE
    create_stop();
    create_drive_direct(0, 100);
    msleep(1500);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_RETRACTED);
    create_drive_direct(0, -100);
    //OUT OF 1ST POWERLINE
    msleep(1500);
    create_stop();
    line_square_up(-25);
    //GO TO SECOND LINE
    create_drive_direct(-100, -100);
    msleep(2000); //EDITED HERE
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_DOWN);
    msleep(1000);
    create_drive_direct(100, 100);
    msleep(1500);
    create_stop();
    //CONNECT SECOND POWERLINE
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED);
    create_drive_direct(-100, -100);
    msleep(1800);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED_HIGHER);
    create_drive_direct(-100, -100);
    msleep(1170);
    create_stop();
    //SECOND LINE CONNECTED
    set_servo_position(ARM_SERVO_PORT, ARM_EXTENDED);
    create_drive_direct(0, 100);
    msleep(1500);
    create_stop();
    set_servo_position(ARM_SERVO_PORT, ARM_RETRACTED);
    create_drive_direct(100, 0);
    msleep(1500);
    //DONE WITH BOTH POWERLINES

    //travel out to orange gas thingy closest to power lines
    //course correction
 	create_drive_direct(100, -100);
    msleep(1650);
    create_drive_direct(50, 50);
    msleep(200);
    create_drive_direct(-100, 100);
    msleep(1650);
    ////////////////////////////////////////////
    create_drive_direct(200, 200);
    msleep(1300);
    create_drive_direct(100, -100);
    msleep(3300);
    set_servo_position(CLAW_ARM_SERVO_PORT, CLAW_ARM_EXTENDED);
    line_square_up(25);
    create_drive_direct(-75, -75);
    msleep(750);
    create_drive_direct(-100, -100);
    msleep(1500);
    set_servo_position(CLAW_ARM_SERVO_PORT, CLAW_ARM_EXTENDED);
    create_drive_direct(50, 50);
    msleep(500);
    create_drive_direct(-50, -50);
    msleep(500);
    create_stop();
    //MODIFIED 4-8-19
    //create_drive_direct(-25, -25);
    slow_servo(CLAW_ARM_SERVO_PORT, CLAW_ARM_EXTENDED, CLAW_ARM_UP);
    create_stop();
    create_drive_direct(100, 100);
    msleep(1000);
    line_square_up(25);
    create_drive_direct(100, 100);
    msleep(4500);
    create_drive_direct(100, -100);
    msleep(1650);
    create_drive_direct(100, 100);
    msleep(3800);
    line_square_up(25);
    
    //////////????REEEE
    //create_drive_direct(-50,-100);
    //msleep(250);
    
    create_drive_direct(-35, -165);
    msleep(1200);
    create_stop();
    printf("Begining Final\n");
    slow_servo(CLAW_ARM_SERVO_PORT, CLAW_ARM_UP, 742);
    //create_drive_direct(0,-25);
    //msleep(750);
    create_drive_direct(50, 50);
    msleep(400);
    
    create_stop();
    slow_servo(CLAW_ARM_SERVO_PORT, 742, CLAW_ARM_UP);
    msleep(250);
    slow_servo(CLAW_ARM_SERVO_PORT, CLAW_ARM_UP, 742);
    printf("End\n");
    //END
    create_stop();
    create_disconnect();
    disable_servos();
    return 0;
}

void arm_all()
{
    create_connect();
    create_full();
    enable_servos();
    set_servo_position(CLAW_ARM_SERVO_PORT, CLAW_ARM_UP);
    set_servo_position(CLAW_SERVO_PORT, CLAW_OPEN_WIDE);
    msleep(500);
    set_servo_position(ARM_SERVO_PORT, ARM_START);
    msleep(500);
    set_servo_position(CLAW_ARM_SERVO_PORT, CLAW_ARM_RETRACTED);
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

void create_measured_drive(int distance, int speedLeft, int speedRight)
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
        create_drive_direct(speed, 0);
    }
    create_stop();
    while (analog(RIGHT_LIGHT_SENSOR_PORT) < RIGHT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(0, speed);
    }
    create_stop();
    while (analog(LEFT_LIGHT_SENSOR_PORT) > LEFT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(-speed, 0);
    }
    create_stop();
    while (analog(RIGHT_LIGHT_SENSOR_PORT) > RIGHT_LIGHT_SENSOR_THRESH)
    {
        create_drive_direct(0, -speed);
    }
    create_stop();
}

void drive_until_bump(int speed)
{
    while (get_create_lbump() == 0 || get_create_rbump() == 0)
    {
        create_drive_direct(speed, speed);
    }
    create_stop();
}

void slow_servo(int servoPort, int currentPosition, int finishPosition)
{
    set_servo_position(servoPort, currentPosition);
    msleep(200);
    while (currentPosition != finishPosition)
    {
        if (currentPosition < finishPosition)
        {
            currentPosition += 1;
        }
        if (currentPosition > finishPosition)
        {
            currentPosition -= 1;
        }
        set_servo_position(servoPort, currentPosition);
        msleep(2);
    }
}
