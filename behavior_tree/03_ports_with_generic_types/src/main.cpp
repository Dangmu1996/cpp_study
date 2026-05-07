#include "behaviortree_cpp/bt_factory.h"
#include "dummy_nodes.h"

using namespace std;
using namespace DummyNodes;

int main()
{
    BT::BehaviorTreeFactory factory;
    factory.registerNodeType<CalculateGoal>("CalculateGoal");
    factory.registerNodeType<PrintTarget>("PrintTarget");
    auto tree = factory.createTreeFromFile("../xml/my_tree.xml");
    tree.tickWhileRunning();
    return 0;
}