#pragma once

#include <behaviortree_cpp/action_node.h>
#include <string>
#include <iostream>

namespace DummyNodes
{
class SaySomething : public BT::SyncActionNode
{
public:
    SaySomething(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config)
    {}

    static BT::PortsList providedPorts()
    {
        return {BT::InputPort<std::string>("message")};
    }

    BT::NodeStatus tick() override
    {
        BT::Expected<std::string> msg = getInput<std::string>("message");
        if(!msg)
        {
            throw BT::RuntimeError("missing required input [message]: ", msg.error());
        }

        std::cout << "Robot says: " <<msg.value() << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
};

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
    ThinkWhatToSay(const std::string& name, const BT::NodeConfig& config)
    : BT::SyncActionNode(name, config)
    {}

    static BT::PortsList providedPorts()
    {
        return { BT::OutputPort<std::string>("text") };
    }

    BT::NodeStatus tick() override
    {
        setOutput("text", "The answer is 42");
        return BT::NodeStatus::SUCCESS;
    }
};
}