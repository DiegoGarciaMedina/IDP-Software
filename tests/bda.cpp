//Basic demonstrability tests
#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
robot_link rlink;
#include "movement.h"
int val,sensors, TIME;
bool distance_sensor;


//test 1 Start robot pointing towards the ramp, turn left, at junction turn right, keep straight over other junction and stop when it detects a wall

void test_1(void)
	{distance_sensor() = false;
	stopwatch watch;
	watch.start();
	speed = 100;
    rlink.command(MOTOR_3_GO,speed); //update the right motor speed
    rlink.command(MOTOR_1_GO,speed);

    turn_left(); //90 degrees stationary left turn
    rlink.command(WRITE_PORT_5,255);
    while (watch.read()<50000)
    {
		sensors = 15 -(255-rlink.request(READ_PORT_5));
		line_following(sensors);
		if (sensors == 15)
			{break;}
    }
	watch.start();
    while (watch.read()<800)
		{rlink.command(MOTOR_3_GO,speed);
		rlink.command(MOTOR_1_GO,speed+127);}

    turn_right(); // 90 degrees stationary right turn

    while (watch.read()<1000000)
    {
		sensors = 15 -(255-rlink.request(READ_PORT_5));
		straight_junction(sensors)
		if (distance_sensor == true)
			{break;}
    }
 }

void test_2(void)
{
stopwatch watch;
watch.start();

  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	straight_junction(sensors);

watch.start();

  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	if (sensors == 15)
		{break;}
    cout << sensors  << endl;
    TIME = watch.read();
    while (watch.read()-TIME < 250){}
  }

  watch.start();

  while (watch.read()<2000){
	rlink.command(MOTOR_3_GO,50+127); //update the right motor speed
	rlink.command(MOTOR_1_GO,50); //update the left motor speed
  }

  watch.start();

  while (watch.read() < 200){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	cout << sensors  << endl;
    TIME = watch.read();
    while (watch.read()-TIME < 250){}
  }

  cout << watch.read() << endl;

}

void test_3()//test 3 Start 20 cm from collection point and go towards it and get aligned for pick-up. Show that robot knows that it has arrived at collection point.
{
rlink.command(WRITE_PORT_2,255); //setting all the bits to 1
distance_sensor = false;
stopwatch watch;
watch.start();

  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	straight_junction(sensors);

watch.start();

  while (watch.read() < 100000){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	if (distance_sensor == true)
		{break;}
  }

  watch.start();
  while (watch.read()<2000){
	rlink.command(MOTOR_3_GO,50+127); //update the right motor speed
	rlink.command(MOTOR_1_GO,50); //update the left motor speed
  }

  watch.start();

  while (watch.read() < 200){
	rlink.command(WRITE_PORT_5,255);
	sensors = 15 -(255-rlink.request(READ_PORT_5));
	line_following(sensors);
	cout << sensors  << endl;
    TIME = watch.read();
    while (watch.read()-TIME < 250){}
    rlink.command(WRITE_PORT_2,127);
    cout << "A box has been detected and ready to pick up"<< endl; //When it has detected the box
  }
}

int main(){
stopwatch watch;

#ifdef __arm__
   if (!rlink.initialise ("127.0.0.1")) {       // setup for local hardware
#else
   if (!rlink.initialise (ROBOT_NUM)) {
	   // setup the link
#endif
}

  val = rlink.request (TEST_INSTRUCTION); // send test instruction
  if (val == TEST_INSTRUCTION_RESULT) {   // check result
    cout << "Test passed" << endl;
  }
  else if (val == REQUEST_ERROR) {
    cout << "Fatal errors on link:" << endl;
    rlink.print_errs();
    rlink.reinitialise(); // flush the link
  }
  else {
    cout << "Test failed (bad value returned)" << endl;

}

	//test_1();
	test_2();
	//test_3();
	return 0;
}
