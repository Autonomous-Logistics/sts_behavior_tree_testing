#include "sts_behavior_tree_testing/BehaviorTreeNodeInterface.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "sts_behavior_tree_testing_node");
    ros::NodeHandle nodeHandle("~");

    sts_behavior_tree_testing::BehaviorTreeNodeInterface node(&nodeHandle);

    std::thread t1(&sts_behavior_tree_testing::BehaviorTreeNodeInterface::resetConditionResult,&node);

    ros::spin();
    return 0;
}
