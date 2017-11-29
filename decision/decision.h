#include <iostream>
#include <stopwatch.h>
#include <robot_instr.h>
#include <robot_link.h>
using namespace std;
#define ROBOT_NUM 14

void path_choice(string BoxType, string InitialPoint); //InitialPoint will always be P2 as we are not choosing to pick up stacked boxes
void D1_path(string InitialPoint);
/*void D4_path(string InitialPoint);
void D2orD5_path(string InitialPoint);
void D3orD6_path(string InitialPoint);*/
