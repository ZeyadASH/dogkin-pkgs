#include "ros/ros.h"
#include "lidar_pkg/lidar.h"
#include "std_msgs/Header.h"

int main (int argc, char **argv)
{
    ros::init(argc, argv, "lidar");
    ros::NodeHandle nh;
    ros::Publisher lidar_pub = nh.advertise<lidar_pkg::lidar>("lidarscan", 1000);
    ros::Rate loop_rate(1);

    lidar_pkg::lidar myLidar;
    myLidar.range_max = 10.0;
    myLidar.header.frame_id = "base_lidar";
    myLidar.scan_time = 0.1;
    myLidar.time_increment = 0.1;

    while (ros::ok())
    {
        lidar_pub.publish(myLidar);
        ROS_INFO("Lidar range_max: %f", myLidar.range_max);
        ROS_INFO("Lidar frame_id: %s", myLidar.header.frame_id.c_str());
        ROS_INFO("Lidar scan_time: %f", myLidar.scan_time);
        ros::spinOnce();
        loop_rate.sleep();
        ++myLidar.range_max;
    }
    return 0;
}