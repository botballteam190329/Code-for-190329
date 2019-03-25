#include <kipr/botball.h>

int turnSpeed = 100;
int speed = 100;
int turnTime90 = 1640; //turn time for a 90 degree turn
int turnTime45 = 820; //turn time for a 45 degree turn

int main()
{
    printf("Skeleton Code\n");
  
//Enable everything
	create_connect();
  	printf("Connected\n");
//Leave starting zone by going right
	moveForward(3.6);
  
 
//Square up against wall:
//Turn left
  	turnLeft90();
//Go backwards to square up against the wall
	
  	moveBackwardSlow(2.0);
  	msleep(1000);

//1st stack:
//Go straight to the right-most stack
  
  	moveForward(3.5);
  	msleep(1000);
/*
//Collect cubes
	collectCubes();
  	moveForward(0);
  	collectCubes();
*/ 
  
  	moveForward(3.2);
//Going to 2nd stack:
//Turn left
  	turnLeft90();
//Line follow? along the outside of the black line until the next stack
  	travelToNextStack();
 /*
	moveForward(2.6);
  
//2nd stack:

//Turn left 90 (lining robot up with the 2nd stack)
  	turnLeft90();
  	msleep(500);
*/
//Go forward and collect 2nd stack
  	moveForward(1.0);
  	msleep(1000);
/*  
//Collect cubes
	collectCubes();
  	moveForward(0);
*/
  
//Going to 3rd stack:
//move backward
  	moveBackward(1.0);
//Turn turn right
  	turnRight90();
//Line follow along the outside of the black line until the next stack
	travelToNextStack();

//3rd stack:

//Go forward
  	moveForward(1.0);
  	msleep(1000);
  	moveBackward(1.0);
  	turnRight90();
  /*
//Collect cube
	collectCubes();
  	moveForward(0);
  	collectCubes();
*/
//Going to 4th stack:
  	travelToNextStack();


//4th stack:

//Go forward
  	moveForward(1.5);
  	msleep(500);
  /*
//Collect cubes
  	collectCubes();
*/
//Turn 45 degrees left to go to disaster relief zone
  	turnLeft45();
  	msleep(500);
  	moveForward(3.5);

//Stop everything
	create_disconnect();
  
    return 0;
}

void moveForward(double time) {
	create_drive_direct(speed,speed);
  	msleep(time*1000);
  	printf("Moving Forward\n");
  	create_stop();
}

void moveBackward(double time) {
	create_drive_direct(-speed,-speed);
  	msleep(time*1000);
  	create_stop();
}

void moveBackwardSlow(double time) {
	create_drive_direct(-50,-50);
  	msleep(time*1000);
  	create_stop();
}

void turnLeft90() {
	create_drive_direct(-turnSpeed,turnSpeed);
  	msleep(turnTime90);
  	create_stop();
}

void turnLeft45() {
	create_drive_direct(-turnSpeed,turnSpeed);
  	msleep(turnTime45);
  	create_stop();
}

void turnRight90() {
	create_drive_direct(turnSpeed,-turnSpeed);
  	msleep(turnTime90);
  	create_stop();
}

void collectCubes() {

}

void travelToNextStack(){
	//Line follow? along the outside of the black line until the next stack
 
	moveForward(2.8);
  
//Next stack stack:

//Turn left 90 (lining robot up with the 2nd stack)
  	turnLeft90();
  	msleep(500);
}
