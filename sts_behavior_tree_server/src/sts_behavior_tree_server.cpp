#include "sts_behavior_tree_server/sts_behavior_tree_server.h"

namespace BehaviorTreeExample {


/// **************************
///         Constructors
/// **************************
///base node derivative
BehaviorTreeExample::BehaviorTreeExample(ros::NodeHandle* nodeHandlePtr) : sts_core::sts_base::StsCoreNode(nodeHandlePtr)
{
    if(this->isOk())
        this->PRINT_NOTIFY("Node launched Successfully");

    if (!readParameters())
    {
        STS_ERROR("Could not read parameters.");
        ros::requestShutdown();
    }
}

/// **************************
///         Destructor
/// **************************
BehaviorTreeExample::~BehaviorTreeExample()
{
    if(this->rootPtr_ != nullptr)
        delete this->rootPtr_;
}

/// **************************
///         Methods
/// **************************

bool BehaviorTreeExample::readParameters()
{
    if (!this->getNodeHandle()->param<int>("tree_tick_period", this->treeTickPeriod_, 1000)) return false;
    if (!this->getNodeHandle()->param<int>("tree_tick_debug_delay", this->treeDebugDelay_, 100)) return false;
    if (!this->getNodeHandle()->param<bool>("tree_generate_feedback", this->treeGenFeedback_, false)) return false;
    if (!this->getNodeHandle()->param<std::string>("tree_graphml_path", this->treeGraphmlPath_, "")) return false; //read from launch file
    return true;
}

void BehaviorTreeExample::runBehaviorTree()
{
    //Empty string reference to pass for feedback of the tree
    std::string id = "";

    std::cout << "parsing tree .graphml ..." <<std::endl;
    this->rootPtr_ = sts_behavior_tree::BehaviorTree::Load(this->treeGraphmlPath_, this->getNodeHandle());

    std::cout << "executing tree ..." <<std::endl;
    try
    {
        //sts_behavior_tree::Execute(root, tickMs, id, nodeHanlePtr, nodeName, genFeedback, draw, debugTickMsDelay);
        sts_behavior_tree::BehaviorTree::Execute(this->rootPtr_, this->treeTickPeriod_, id, this->getNodeHandle(), this->getNodeName(), true, this->treeGenFeedback_, this->treeDebugDelay_);
    }
    catch (BT::BehaviorTreeException& Exception)
    {
       STS_ERROR(Exception.what());
    }

    return;
}


} /* namespace */
