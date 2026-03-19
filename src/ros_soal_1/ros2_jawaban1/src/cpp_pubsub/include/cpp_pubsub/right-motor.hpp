#ifndef CPP_PUBSUB_RIGHT_MOTOR_HPP
#define CPP_PUBSUB_RIGHT_MOTOR_HPP

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/char.hpp"

// Node untuk mengontrol motor kanan
namespace cpp_pubsub {
    class RightMotorNode : public rclcpp::Node {
        public:
            RightMotorNode();

        private:
            void commandCallback(const std_msgs::msg::Char::SharedPtr msg) const;
            bool isRightMotorActive(char command) const;

            rclcpp::Subscription<std_msgs::msg::Char>::SharedPtr subscription_;
    };
} 

#endif 
