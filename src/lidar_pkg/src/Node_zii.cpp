#include "ros/ros.h"
#include "std_msgs/String.h" // String msg type from std_msgs pkg

int main(int argc, char **argv)
{
    // Init -> name remapping through CLI
    // NodeHandle -> communicate with ROS
    // The first NodeHandle created will actually do the initialization of the node
    // and the last one destructed will cleanup any resources the node was using. 
    ros::init(argc, argv, "Zii_publisher", ros::init_options::AnonymousName);
    ros::NodeHandle n;

    ros::Publisher Zii_pub = n.advertise<std_msgs::String>("Zii_topic", 1000);
    ros::Rate loop_rate(10);    

    
}