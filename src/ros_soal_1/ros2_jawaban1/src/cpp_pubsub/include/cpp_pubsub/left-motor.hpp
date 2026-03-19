#ifndef CPP_PUBSUB_LEFT_MOTOR_HPP
#define CPP_PUBSUB_LEFT_MOTOR_HPP

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/char.hpp"

// Node untuk mengontrol motor kiri
namespace cpp_pubsub {
    class LeftMotorNode : public rclcpp::Node {
        public:
            LeftMotorNode();

        private:
            void commandCallback(const std_msgs::msg::Char::SharedPtr msg) const;
            bool isLeftMotorActive(char command) const;

            rclcpp::Subscription<std_msgs::msg::Char>::SharedPtr subscription_;
    };
}  

#endif  