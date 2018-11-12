#include <ros/ros.h>
#include <gazebo_msgs/GetModelState.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/String.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "model_pose");

    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::PoseStamped>("pose", 10);
    ros::Rate loop_rate(10);

    // std::string inputString = "unit_box_0";
    // std::string inputString = "ground_plane";
    std::string inputString = argv[1];

    while (ros::ok()) {
        ros::ServiceClient gms = nh.serviceClient<gazebo_msgs::GetModelState>("gazebo/get_model_state");
        gms.waitForExistence();

        gazebo_msgs::GetModelState getModelState;
        getModelState.request.model_name = inputString;

        gms.call(getModelState);

        geometry_msgs::PoseStamped pose;

        pose.header = getModelState.response.header;
        pose.pose = getModelState.response.pose;

        pub.publish(pose);

        ros::spinOnce();
    }

}