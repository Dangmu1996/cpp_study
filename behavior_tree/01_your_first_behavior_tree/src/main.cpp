#include "behaviortree_cpp/bt_factory.h"

#include "dummy_nodes.h"
using namespace BT;
using namespace DummyNodes;

int main()
{
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<ApproachObject>("ApproachObject");
    factory.registerSimpleCondition("CheckBattery", [&](TreeNode&){ return CheckBattery();});
    GripperInterface gripper;
    factory.registerSimpleAction("OpenGripper", [&](TreeNode&){ return gripper.open(); });
    factory.registerSimpleAction("CloseGripper", [&](TreeNode&){ return gripper.close(); });
    auto tree = factory.createTreeFromFile("../xml/my_tree.xml");
    tree.tickWhileRunning();
    return 0;
}