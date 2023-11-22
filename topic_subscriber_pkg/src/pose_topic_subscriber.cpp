#include "ros/ros.h"
#include "turtlesim/Pose.h"

// Callback function to handle the pose updates
void poseCallback(const turtlesim::Pose::ConstPtr& pose_msg) {
    // Print the x, y, and theta poses
    ROS_INFO("Robot Pose - X: %f, Y: %f, Theta: %f", pose_msg->x, pose_msg->y, pose_msg->theta);
}

int main(int argc, char** argv) {
    // Initialize the ROS node
    ros::init(argc, argv, "pose_subscriber");

    // Create a ROS NodeHandle
    ros::NodeHandle nh;

    // Create a Subscriber to listen to the turtle's pose updates
    ros::Subscriber pose_subscriber = nh.subscribe("/turtle1/pose", 10, poseCallback);

    // Spin to allow the callback function to process incoming messages
    ros::spin();

    return 0;
}
