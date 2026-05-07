#pragma once

#include <behaviortree_cpp/action_node.h>
#include <string>
#include <iostream>
#include <string_view>
#include <algorithm>
#include <exception>

namespace DummyNodes
{
    struct Position2D
    {
        double x;
        double y;
    };

    class CalculateGoal : public BT::SyncActionNode
    {
        public:
            CalculateGoal(const std::string& name, const BT::NodeConfig& config)
            : BT::SyncActionNode(name, config)
            {}

            static BT::PortsList providedPorts()
            {
                return {BT::OutputPort<Position2D>("goal")};
            }

            BT::NodeStatus tick() override
            {
                Position2D mygoal={1.1, 2.3};
                setOutput<Position2D>("goal", mygoal);
                return BT::NodeStatus::SUCCESS;
            }
    };

    class PrintTarget : public BT::SyncActionNode
    {
        public:
            PrintTarget(const std::string& name, const BT::NodeConfig& config)
            : BT::SyncActionNode(name, config)
            {}

            static BT::PortsList providedPorts()
            {
                const char* description = "Simply prin the goal on console...";
                return {BT::InputPort<Position2D>("target", description)};
            }

            BT::NodeStatus tick() override
            {
                auto res = getInput<Position2D>("target");
                if(!res){
                    throw BT::RuntimeError("error reading port [target]:", res.error());
                }
                Position2D target = res.value();
                printf("Target position: [%lf, %lf]\n", target.x, target.y);
                return BT::NodeStatus::SUCCESS;
            }
    };
}

namespace BT
{
    template<> 
    inline DummyNodes::Position2D convertFromString(StringView str)
    {
        auto parts=splitString(str, ';');
        if(parts.size()!=2){
            throw RuntimeError("invalid input");
        }else{
            DummyNodes::Position2D output;
            output.x = convertFromString<double>(parts[0]);
            output.y = convertFromString<double>(parts[1]);
            return output;
        }
    }
}// end namespace BT