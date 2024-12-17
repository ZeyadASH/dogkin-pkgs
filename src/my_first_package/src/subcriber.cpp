#include "ros/ros.h"
#include "std_msgs/Int16.h"

void chatterCallback(const std_msgs::Int16::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->data);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("my_topic", 10, chatterCallback);

  ros::spin();

  return 0;
}