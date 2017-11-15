#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14

robot_link rlink;

int read_sensors_line_following();
int distance_sensor(int sensors);
int line_following(int sensors);
void turn_left(speed);
void turn_right(void);
void turn_around(void);
void reverse_robot(time_reverse);
void straight_junction(void);
void stop(void);
void pick_up(void);
void drop_box(void);


