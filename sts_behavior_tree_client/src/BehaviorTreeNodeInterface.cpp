#include "sts_behavior_tree_testing/BehaviorTreeNodeInterface.h"


namespace sts_behavior_tree_testing {

/// **************************
///         Constructors
/// **************************
BehaviorTreeNodeInterface::BehaviorTreeNodeInterface(ros::NodeHandle* nodeHandlePtr) : sts_core::sts_interfaces::StsBehaviorTreeInterface(nodeHandlePtr)
{
    //this->currentResult_ = false;

	//declare com if with callback
    //this->createBtIfCom("bt_topic", sts_bt_types::TOPIC, false, std::bind(&BehaviorTreeNodeInterface::publishCallback, this, std::placeholders::_1));
    this->createBtIfCom("topic1", sts_behavior_tree_if_types::FLAG, false);

    this->createBtIfCom("service1", sts_behavior_tree_if_types::SERVICE, false, std::bind(&BehaviorTreeNodeInterface::serviceCallback, this, std::placeholders::_1));
    this->createBtIfCom("action1", sts_behavior_tree_if_types::ACTION, false, std::bind(&BehaviorTreeNodeInterface::actionCallback, this, std::placeholders::_1));
    this->createBtIfCom("action2", sts_behavior_tree_if_types::ACTION, false, std::bind(&BehaviorTreeNodeInterface::actionCallback2, this, std::placeholders::_1));

    if(this->isOk())
        this->PRINT_NOTIFY("Node launched Successfully");
    else
        this->PRINT_ERROR("Node initialization failed");

    /// do other important things
}

/// **************************
///         Destructor
/// **************************
BehaviorTreeNodeInterface::~BehaviorTreeNodeInterface()
{
}

/// **************************
///         Methods
/// **************************

bool BehaviorTreeNodeInterface::readParameters()
{
    if (!this->getNodeHandle()->getParam("subscriber_topic", subscriberTopic_)) return false;
    return true;
}

void BehaviorTreeNodeInterface::publishCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr)
{
    std::cout << "conditionCallback1, updating to " << this->getCurrentResult() << std::endl;
    resultPtr->getResultObj()->setResult(this->getCurrentResult());
    return;
}

void BehaviorTreeNodeInterface::serviceCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr)
{
    std::cout << "serviceCallback" << std::endl;
    resultPtr->getResultObj()->setResult(true);
    return;
}

void BehaviorTreeNodeInterface::actionCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr)
{
    std::cout << "actionCallback1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    if (resultPtr->getArgsObj()->getPreemptRequestReference() == false)
    {
       //this->setCurrentResult(true);
       this->sendAsync("topic1", true);

       /// do a little sleep before returning from teh action , just for the lolz
       std::this_thread::sleep_for(std::chrono::seconds(1));

       resultPtr->getResultObj()->setResult(true);
       std::cout << "actionCallback1 returned POSITIVE" << std::endl;
    }
    else
    {
        resultPtr->getResultObj()->setResult(false);
        std::cout << "actionCallback1 PREEMPTED" << std::endl;
    }

    return;
}

void BehaviorTreeNodeInterface::actionCallback2(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr)
{
    std::cout << "actionCallback2" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    if (resultPtr->getArgsObj()->getPreemptRequestReference() == false)
    {
        //this->setCurrentResult(false);
        this->sendAsync("topic1", false);

        /// do a little sleep before returning from teh action , just for the lolz
        std::this_thread::sleep_for(std::chrono::seconds(1));

        resultPtr->getResultObj()->setResult(true);
        std::cout << "actionCallback2 returned POSITIVE" << std::endl;
    }
    else
    {
        resultPtr->getResultObj()->setResult(false);
        std::cout << "actionCallback2 PREEMPTED" << std::endl;
    }

    return;
}

//Showcase method
void BehaviorTreeNodeInterface::resetConditionResult()
{
    std::string tmp;
    while (true)
    {
        std::cin >> tmp;
        if(tmp[0] == '1')
        {
            std::cout << "Set condition result(1)" << std::endl;
            //this->setCurrentResult(true);
            this->sendAsync("topic1", true);
        }
        else if(tmp[0] == '0')
        {
            std::cout << "Reset condition result(0)" << std::endl;
            //this->setCurrentResult(false);
            this->sendAsync("topic1", false);
        }
        else
        {
        }
    }
}

} /* namespace */
