// from optical frame to mobile base frame
// x: the middle point of turtlebot plane to kinect camera
// y: place a box in front of the kinect camera, and adjust the place of box
//    until it is in the middle of the scan, then measure the distance of
//    mid robot point and box point.
// z: set a suitable height. or measure it by yourself.
// rotation: RPY or quaternion, child_link's rotation relative to parent's.
// warning: we usually use (w,x,y,z) however in ROS (x,y,z,w)!!!

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "addtf");
	ros::NodeHandle node;

	tf::TransformBroadcaster br;
	tf::Transform transform;

    ros::Rate rate(10.0);
	while (node.ok())
	{
        ros::Time now = ros::Time::now();

//        // Kinect horizonal placed.
//        transform.setOrigin(tf::Vector3( 0.132, 0.05, 0.4));
	transform.setOrigin(tf::Vector3( 0.1, 0, 0.2));
  //      transform.setRotation(tf::Quaternion( -0.5, 0.5, -0.5, 0.5 ));
        transform.setRotation(tf::Quaternion( 0, 0, 0, 1 ));
//        // Kinect vertical placed, base on the left.
//        transform.setOrigin(tf::Vector3( 0.125, 0, 0.4 ));
//        transform.setRotation(tf::Quaternion( 0, sqrt(2)/2, 0, sqrt(2)/2 ));

        // Kinect vertical placed, base on the right.
//        transform.setOrigin(tf::Vector3( 0.0, 0.0, 0.0 ));  // scan test
        // distance of kinect optical frame to camera frame is 0.11m
        // add this with the distance of camera frame to base frame.      
//        transform.setOrigin(tf::Vector3( 0.125, 0.0, 0.6 ));
//        transform.setRotation(tf::Quaternion( sqrt(2)/2, 0, sqrt(2)/2, 0 ));

        br.sendTransform(tf::StampedTransform(transform, now, "base_link", "camera_link"));
//        br.sendTransform(tf::StampedTransform(tf::Transform(tf::Quaternion(0,0,0,1),tf::Vector3(0.132,0.0,0.87)),ros::Time::now(),"base_link","camera_link"));
		rate.sleep();
	}
	return 0;
}
