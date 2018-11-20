
#include "walker.h"

walker::walker()
{
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;
    veloclity_pub = n.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 10);
    laserScan_sub = n.subscribe<sensor_msgs::LaserScan>("/scan",10, &walker::laserScanCallBack, this); 
}


void walker::laserScanCallBack(const sensor_msgs::LaserScan::ConstPtr& scan){
    int ranges = scan->ranges.size();
    bool turn = false;

    for(int i = 0; i < ranges; ++i){
        if (scan->ranges[i] < 0.8)
            turn = true;
    }

    if(turn){
        msg.linear.x = 0.0;
        msg.angular.z = 0.5;
    } else {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
    }

    veloclity_pub.publish(msg);

}

