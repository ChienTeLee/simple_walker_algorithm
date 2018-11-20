#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>


class walker{
public:
    walker();

private:
    geometry_msgs::Twist msg;
    ros::NodeHandle n;
    ros::Publisher veloclity_pub;
    ros::Subscriber laserScan_sub;
    void laserScanCallBack(const sensor_msgs::LaserScan::ConstPtr& scan);
};
