

#include <stdlib.h>
#include "walker.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "simpleWalker");

    walker simpleWalker;

    ros::Rate loop_rate(10);

    ros::spin();

    return 0;
}
