#include "sts_behavior_tree_server/sts_behavior_tree_server.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sts_behavior_tree_server");
    ros::NodeHandle nodeHandle("~");

    BehaviorTreeExample::BehaviorTreeExample node(&nodeHandle);

    node.runBehaviorTree();

    return 0;
}
