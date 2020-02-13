#include <ros_tutorial_src/robot_controller.h>

RobotController::RobotController(ros::NodeHandle nh) : nh_(nh)
{
  // ### Tell ROS that this node publishes Twist messages on the '/cmd_vel' topic
  // TODO
  
  // ### Tell ROS that this node subscribes to Odometry messages on the '/odom' topic
  // ### When a message is received, call RobotController::odometryCB
  // TODO
  
  // ### Tell ROS that this node subscribes to PoseStamped messages on the '/move_base_simple/goal' topic
  // ### When a message is received, call RobotController::goalCB
  // TODO
}

RobotController::~RobotController()
{
}

void RobotController::odometryCB(const nav_msgs::Odometry &msg)
{
  // TODO
}

void RobotController::goalCB(const geometry_msgs::PoseStamped &msg)
{
  goal_available_ = true;
  // TODO
}

void RobotController::publishVelocity(const float linear_vel, const float angular_vel)
{
  // # Create twist message
  // TODO
  
  // # Send command
  // TODO
}

void RobotController::driveRobot(const float distance, const float linear_velocity)
{
  // TODO
}

void RobotController::rotateRobot(const float angle, const float angular_velocity)
{
  // TODO
}

void RobotController::goToGoal()
{
  // TODO
}

void RobotController::smoothDriveRobot(const float distance, const float linear_velocity)
{
  // TODO
}

int main(int argc, char **argv)
{
  // ### Initialize node, name it 'robot_controller'
  // TODO

  // # Create Nodehandle 
  // TODO

  ros::Rate rate(500);
  // #spinners are needed for subscribers
  ros::AsyncSpinner spinner(1);

  spinner.start();

  // # Create object 'controller' of class 'RobotController'.
  // TODO

  // ### Sleep a little to give ROS time to register this node
  ros::Duration(1.0).sleep();

  while (ros::ok())
 {
  //  # Check if goal has published.
   if (controller.goal_available_)
   {
    //  # if goal is available, move the robot
     // TODO
   }
  //  # Sleep for some time
   rate.sleep();
  }

  spinner.stop();
  ros::Duration(1.0).sleep();
  return 0;
}
