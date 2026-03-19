#include "cpp_pubsub/left-motor.hpp"

namespace cpp_pubsub {
    LeftMotorNode::LeftMotorNode() : Node("left_motor_node") {
        subscription_ = this->create_subscription<std_msgs::msg::Char>(
            "microcontroller/buttons", 10,
            std::bind(&LeftMotorNode::commandCallback, this, std::placeholders::_1)
        );
    }

    void LeftMotorNode::commandCallback(const std_msgs::msg::Char::SharedPtr msg) const {
        const bool active = isLeftMotorActive(msg->data);
        RCLCPP_INFO(this->get_logger(), "[LEFT MOTOR] %s", active ? "ACTIVATED" : "DEACTIVATED");
    }

    bool LeftMotorNode::isLeftMotorActive(char command) const {
        return command == 'w' || command == 's' || command == 'd';
    }
} 

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<cpp_pubsub::LeftMotorNode>());
    rclcpp::shutdown();
    return 0;
}
