#pragma once

// STD Includes
#include <string>

// ROS
#include <ros/ros.h>

// Others

// internal includes

// sts includes
#include <sts_core_utils/sts_core/sts_base/sts_core_node.h>
#include <sts_bt_library/behavior_tree.h>

// sts interfaces

namespace BehaviorTreeExample {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
///base node derivative
class BehaviorTreeExample : public virtual sts_core::sts_base::StsCoreNode
{
 public:
/// **************************
///    Public Attributes
/// **************************

/// **************************
///       Constructors
/// **************************

    /*!
    * Constructor.
    * @param nodeHandle the ROS node handle.
    */
    BehaviorTreeExample(ros::NodeHandle* nodeHandlePtr);

/// **************************
///       Destructor
/// **************************

    /*!
    * Destructor.
    */
    virtual ~BehaviorTreeExample();


/// **************************
///    Public Methods
/// **************************
    void runBehaviorTree();

private:

/// **************************
///      Private Attributes
/// **************************
    BT::TreeNode* rootPtr_;
    int treeTickPeriod_;     //ms
    int treeDebugDelay_;     //ms

    bool treeDraw_;
    bool treeGenFeedback_;
    std::string treeGraphmlPath_;


/// **************************
///      Private Methods
/// **************************

    /*!
    * Reads and verifies the ROS parameters.
    * @return true if successful.
    */
    bool readParameters();
};

} /* namespace */

