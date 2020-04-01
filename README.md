# sts_behavior_tree_testing

## Overview

This is a meta package to test the sts_behavior_tree library. It provides a server and client node.

## Installation

### Building from Source

#### Dependencies

- [Robot Operating System (ROS)](http://wiki.ros.org) (middleware for robotics),
- sts_behavior_tree_interface
- sts_behavior_tree


#### Building

To build from source, clone the latest version from this repository into your catkin workspace and compile the package using

	cd catkin_ws/src
	git clone http://gitlab_al.streetscooter.eu/al_SW_Team/sts_behavior_tree_testing
	cd ../
	catkin build

## Usage
Run the behavior tree server

	roslaunch sts_behavior_tree_server tree.launch

Run the behavior tree client sts_behavior_tree_client

	roslaunch sts_behavior_tree_client client.launch


## Nodes

### sts_behavior_tree_server

Provides a demo how to use the sts_bt_library to parse, build and execute behavior trees.

### sts_behavior_tree_visualisation

Provides a graph visualization (using xdot) and will draw the behavior tree state accordingly during runtime.

### sts_behavior_tree_client

Provides the behavior tree client node with a publisher, service server and action server which will be triggered and used by the sts_behavior_tree_server (running the behavior tree itself). It does that by using the sts_behavior_tree_interface implemented inside the sts_virtual_interfaces library.

## Bugs & Feature Requests

Please report bugs and request features using the [Issue Tracker](http://gitlab_al.streetscooter.eu/al_SW_Team/sts_behavior_tree_testing/issues).
