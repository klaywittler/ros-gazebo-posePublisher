# ros-gazebo-posePublisher

* Add to catkin workspace
  * examples use catkin_ws
* ```source /opt/ros/<distro>/setup.bash```
  * melodic was used to create this package
  * ```source /opt/ros/melodic/setup.bash```
* ```catkin_make``` to build the package
* ```source <path to workspace>/devel/setup.bash```
  * ```source /home/<user>/catkin_ws/devel/setup.bash```
* ```roslaunch model_pose box_pose.launch``` to run
  * Default model is unit_box_0
    * Default can be changed in the box_launch file line 3 ```<arg name="args" default="unit_box_0" />```
  * Other model poses can be found by running: 
    * ```roslaunch model_pose box_pose.launch args:="<model name>"```
    * Example to find ground_plane pose: ```roslaunch model_pose box_pose.launch args:="ground_plane"```
* In a new terminal run ```rostopic echo /pose``` to see the published data of type geometry_msgs/PoseStamped
