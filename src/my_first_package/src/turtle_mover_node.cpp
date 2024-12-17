#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "my_first_package/ultrasonic_custom.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "turtle_mover_node"); //initial node name
  ros::NodeHandle n;   // node handler 
  ros::Publisher my_publisher = n.advertise<my_first_package::ultrasonic_custom>("/turtle1/ultrasonic", 10); //topic name and will be published 
  ros::Rate loop_rate(1); //how much i will publish my data per second 
 
  my_first_package::ultrasonic_custom ultrasonic_readings;

    ultrasonic_readings.index =1;
    ultrasonic_readings.min_range=0.5;
    ultrasonic_readings.max_range=10.0;

    ultrasonic_readings.distance=3.5;
    ultrasonic_readings.humidity=30;
    ultrasonic_readings.warning="humidity above 50% reading might be inaccurate";

    // ultrasonic_readings.robot_position.position.x =5;
  while (ros::ok())
  {
 
    if(ultrasonic_readings.humidity>50)
    {
        ROS_INFO("%s",ultrasonic_readings.warning.c_str());
    }
    
    my_publisher.publish(ultrasonic_readings);

    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}