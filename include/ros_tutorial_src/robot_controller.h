#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf/LinearMath/Quaternion.h>
#include <tf/tf.h>

class RobotController
{
private:
  ros::NodeHandle nh_;

  /**
   * @brief Updates the current pose of the robot.
   *        This method is a callback bound to a Subscriber.
   * 
   * @param msg [Odometry] The current odometry information.
   */
  void odometryCB(const nav_msgs::Odometry &msg);
  
  /**
   * @brief Updates the Goal Poisition for robot
   *        This method is a callback bound to a Subscriber.
   * 
   * @param msg [PoseStamped] The target pose.
   */
  void goalCB(const geometry_msgs::PoseStamped &msg);

  /**
   * @brief Sends the speeds to the motors.
   * 
   * @param linear_vel  [float] [m/s]   The forward linear speed.
   * @param angular_vel [float] [rad/s] The angular speed for rotating around the body center.
   */
  void publishVelocity(const float linear_vel, const float angular_vel);
  
  /**
   * @brief  Drives the robot in a straight line.
   * 
   * @param distance         [float] [m]   The distance to cover.
   * @param linear_velocity  [float] [m/s] The forward linear speed.
   */
  void driveRobot(const float distance, const float linear_velocity);

  /**
   * @brief Rotates the robot around the body center by the given angle.
   * 
   * @param angle             [float] [rad]   The distance to cover.
   * @param angular_velocity  [float] [rad/s] The angular speed.
   */
  void rotateRobot(const float angle, const float angular_velocity);
  
  /**
   * @brief Drives the robot in a straight line by changing the actual speed smoothly.
   * 
   * @param distance         [float] [m]   The distance to cover.
   * @param linear_velocity  [float] [m/s] The maximum forward linear speed.
   */
  void smoothDriveRobot(const float distance, const float linear_velocity);



public:
  
  /**
   * @brief Construct a new Robot Controller:: Robot Controller object
   * 
   * @param nh 
   */
  RobotController(ros::NodeHandle nh);

  /**
   * @brief Destroy the Robot Controller:: Robot Controller object
   *        Delete pointers here, if used
   * 
   */
  ~RobotController();
  
  // Set true when goal is available on topic: /move_base_simple/goal
  bool goal_available_ = false;
  
  /**
   * @brief Calls rotate(), drive(), and rotate() to attain a given pose.
   * 
   */
  void goToGoal();
};
