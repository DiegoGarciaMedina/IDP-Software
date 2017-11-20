#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
extern robot_link rlink;

//index of variables
//sensors:decimal number corresponding to the binary number made by sesnsors being set or off
//ms_r:motor speed right
//ms_l:motor speed left
//speed: value that will be decided experimentally
//distance: boolean value set to true if close to the wall


/*int read_sensors_line_following(void){
  double sensors_init;
  int sensors;
  sensors_init = rlink.request(READ_PORT_1);
  sensors_init += 0.5
  int sensors = (int)sensors_init
  return (sensors)
    }*/

/*int distance_sensor(int sensors){
  int distance;
  if(sensors<8){
    distance = 0;
}
  else{
    distance = 1;
}
}*/

int line_following(int sensors) {
    int ms_r, ms_l, speed; //outputs
    stopwatch watch;
    watch.start();
    speed =100;
    switch(sensors){
		case 0:
		ms_r = (speed)/3 +127;
		ms_l = ms_r-127;
		break;
		case 6:
		ms_r = speed;
		ms_l = ms_r + 127;
		break;
		case 15:
		ms_r = 0;
		ms_l = 0;
		break;
		case 1:
		ms_l = speed +127;
		ms_r = (ms_l-127)/4;
		break;
		case 2:
		ms_l = speed +127;
		ms_r = (ms_l-127)/2;
		break;
		case 3:
		ms_l = speed +127;
		ms_r = 0; // (ms_l)/2 if we want the right wheel to reverse
		break;
		case 7:
		ms_l = speed +127;
		ms_r = 0; // (ms_l)/2 if we want the right wheel to reverse
		break;
		case 4:
		ms_r = speed;
		ms_l = ms_r/2 + 127;
		break;
		case 8:
		ms_r = speed;
		ms_l = ms_r/4 + 127;
		break;
		case 12:
		ms_r = speed;
		ms_l = 0;
		break;
		case 14:
		ms_r = speed;
		ms_l = 0;
		break;
		case 5:
		cout << "something is seriously wrong" << endl;
		break;
		case 9:
		cout << "something is seriously wrong" << endl;
		break;
		case 10:
		cout << "something is seriously wrong" << endl;
		break;
		case 11:
		cout << "something is seriously wrong" << endl;
		break;
		case 13:
		cout << "something is seriously wrong" << endl;
		break;
		default : cout << "just stop trying" << endl;
		break;
	}

rlink.command(MOTOR_3_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_1_GO,ms_l); //update the left motor speed

 while (watch.read() < 100){}
 return(sensors);
  }

void turn_left(void) {
int speed, ms_l, ms_r;
speed = 100;
ms_r = speed;
ms_l = speed; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<1200){
}
}

void turn_right(void) {

int ms_l, ms_r,speed;
speed = 100;
ms_l = 127 +speed;
ms_r = ms_l; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<1200){
}
}

/*void turn_around(void){
int speed, ms_l, ms_r;

speed = rlink.request(MOTOR_1); //reads the current motor speed

ms_l = speed;
ms_r = 0; //sets the motor speeds

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed

stopwatch watch;
watch.start();
while (watch.read()<2200){
}
}

void reverse_robot(time_reverse){
int speed, ms_l, ms_r;

speed = rlink.request(MOTOR_1);
ms_r = (speed)/3 +127;
ms_l = ms_r-127;

rlink.command(MOTOR_1_GO,ms_r); //update the right motor speed
rlink.command(MOTOR_3_GO,ms_l); //update the left motor speed
watch.start()
while (watch.read()<time_reverse){
}

}

void straight_junction(void){
double ms_r,ms_l;
  ms_r=rlink.request(MOTOR_1);
  ms_l=rlink.request(MOTOR_3);
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
  watch.start();
  while (watch.read() < 500)  {
 }
}

void stop(void){
double ms_r,ms_l;
  ms_r=0;
  ms_l=0;
  rlink.command(MOTOR_1_GO,ms_r);
  rlink.command(MOTOR_3_GO,ms_l);
}

void pick_up(void){
}

void drop_box(void){
}
*/

