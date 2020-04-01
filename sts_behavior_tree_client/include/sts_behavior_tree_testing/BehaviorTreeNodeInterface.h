#pragma once

// STD Includes
#include <string>

// ROS
#include <ros/ros.h>

// Others
//#include <Eigen/Dense>

// internal includes
#include "sts_behavior_tree_testing/BehaviorTreeNode.h"

// sts includes
#include <sts_behavior_tree_interface/StsBehaviorTreeIf/StsBehaviorTreeIf.h>
#include <thread>
#include <chrono>

namespace sts_behavior_tree_testing {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class BehaviorTreeNodeInterface : public virtual sts_core::sts_interfaces::StsBehaviorTreeInterface
{
 public:

/// **************************
///       Constructors
/// **************************

    /*!
    * Constructor.
    * @param nodeHandle the ROS node handle.
    */
    BehaviorTreeNodeInterface(ros::NodeHandle* nodeHandlePtr);

    bool getCurrentResult(){return this->currentResult_;}

    void setCurrentResult(bool b){this->currentResult_ = b;}

/// **************************
///       Destructor
/// **************************

    /*!
    * Destructor.
    */
    virtual ~BehaviorTreeNodeInterface();


/// **************************
///    Public Methods
/// **************************


 private:

/// **************************
///      Private Attributes
/// **************************

    //! ROS topic name to subscribe to.
    std::string subscriberTopic_;
    bool currentResult_;


/// **************************
///      Private Methods
/// **************************

    /*!
    * Reads and verifies the ROS parameters.
    * @return true if successful.
    */
    bool readParameters();

    void publishCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr);

    void serviceCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr);

    void actionCallback(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr);

    void actionCallback2(sts_behavior_tree_if_types::StsBehaviorTreeParam* resultPtr);

public:
    void resetConditionResult();

};

} /* namespace */
