#pragma once

#include <behaviortree_cpp/action_node.h>
#include <iostream>
#include <string>

namespace DummyNodes
{
class ApproachObject : public BT::SyncActionNode
{
public:
    ApproachObject(const std::string& name) :
        BT::SyncActionNode(name, {})
    {}

    BT::NodeStatus tick() override
    {
        std::cout << "ApproachObject: " << this->name() << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

BT::NodeStatus CheckBattery()
{
    std::cout << "[ Battery: OK ]" << std::endl;
    return BT::NodeStatus::SUCCESS;
}

class GripperInterface
{
public:
    GripperInterface(): _open(true) {}

    BT::NodeStatus open()
    {
        _open = true;
        std::cout<<"GripperInterface::open" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus close()
    {
        std::cout << "GripperInterface::close" << std::endl;
        _open = false;
        return BT::NodeStatus::SUCCESS;
    }
private:
    bool _open;
};
}