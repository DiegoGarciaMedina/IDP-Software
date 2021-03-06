#include <iostream>
#include <stopwatch.h>
#include <vector>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14
//int speed, time_reverse,turn;

int line_following(int sensors);
int turn_left(void);
int turn_right(void);
void turn_around(void);
int reverse_robot(int time_reverse);
void straight_junction(void);
int box_id(void);
void pick_up(void);
void high_dropbox(void);
void drop_box(void);
int turn_detection(int sensors, int turn);
int sensors_read(void);
bool object_ahead(void);
void alignment_drop(void);
void blind_turn(int turn);
void stop(void);
void alignment_pickup(void);


