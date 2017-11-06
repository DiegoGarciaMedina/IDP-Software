#include <iostream>
using namespace std;
#include <robot_instr.h>
#include <robot_link.h>

int main ()
{
    float speed;
    speed = 100;
    rlink.command(BOTH_MOTORS_GO_SAME, speed);
return 0;
}
