#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <actionlib/server/simple_action_server.h>
#include "my_first_package/counterAction.h"

class ActionDemo
{
protected:
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<my_first_package::counterAction> as; 
  my_first_package::counterFeedback feedback;
  my_first_package::counterResult result;

  std::string action_name;
  int progress;

public:
  ActionDemo(std::string name) :
    as(nh_, name, boost::bind(&ActionDemo::executeCB, this, _1), false),
    action_name(name)
  {
    as.registerPreemptCallback(boost::bind(&ActionDemo::preemptCB, this));
    as.start();
  }

  ~ActionDemo() {}

  void preemptCB()
  {
    ROS_WARN("%s got preempted!", action_name.c_str());
    result.final_count = progress;
    as.setPreempted(result, "Action preempted");
  }

  void executeCB(const my_first_package::counterGoalConstPtr &goal)
  {
    if (!as.isActive() || as.isPreemptRequested()) return;

    ros::Rate rate(5);
    ROS_INFO("%s is processing the goal %d", action_name.c_str(), goal->count);

    for (progress = 1; progress <= goal->count; ++progress)
    {
      if (!ros::ok())
      {
        result.final_count = progress;
        as.setAborted(result, "Node shutting down!");
        ROS_ERROR("%s shutting down", action_name.c_str());
        return;
      }

      if (as.isPreemptRequested())
      {
        ROS_WARN("%s preempted!", action_name.c_str());
        result.final_count = progress;
        as.setPreempted(result, "Preemption requested");
        return;
      }

      feedback.current_number = progress;
      as.publishFeedback(feedback);
      rate.sleep();
    }

    result.final_count = progress - 1;
    ROS_INFO("%s succeeded at goal %d", action_name.c_str(), goal->count);
    as.setSucceeded(result);
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "demo_action");
  ROS_INFO("Starting Demo Action Server");
  ActionDemo demo_action_obj(ros::this_node::getName());
  ros::spin();
  return 0;
}
