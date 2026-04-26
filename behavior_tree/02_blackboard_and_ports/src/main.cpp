#include "behaviortree_cpp/bt_factory.h"
#include "dummpy_nodes.h"

using namespace DummyNodes;

int main()
{
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<SaySomething>("SaySomething");
    factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

    auto tree = factory.createTreeFromFile("../xml/my_tree.xml");
    tree.tickWhileRunning();

    return 0;
}

