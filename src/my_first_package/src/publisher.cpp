#include "ros/ros.h"
#include "std_msgs/Int16.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_first_publisher_node"); //initial node name
  ros::NodeHandle n;   // node handler 
  ros::Publisher my_publisher = n.advertise<std_msgs::Int16>("my_topic", 10); //topic name and will be published 
  ros::Rate loop_rate(2); //how much i will publish my data per second 

  std_msgs::Int16 count;
  count.data=0;

  while (ros::ok())
  {
   
    ROS_INFO("%d",count.data );
  
    my_publisher.publish(count);

    ros::spinOnce();

    loop_rate.sleep();
    count.data++;
  }


  return 0;
}