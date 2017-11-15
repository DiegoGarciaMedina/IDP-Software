#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
int speed, time_reverse;

int read_sensors_line_following();
int distance_sensor(int sensors);
int line_following(int sensors);
int turn_left(speed);
void turn_right(void);
void turn_around(void);
int reverse_robot(time_reverse);
void straight_junction(void);
void stop(void);
void pick_up(void);
void drop_box(void);


