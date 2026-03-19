#include "cpp_pubsub/right-motor.hpp"

namespace cpp_pubsub {
    RightMotorNode::RightMotorNode() : Node("right_motor_node") {
        subscription_ = this->create_subscription<std_msgs::msg::Char>(
            "microcontroller/buttons", 10,
            std::bind(&RightMotorNode::commandCallback, this, std::placeholders::_1)
        );
    }

    void RightMotorNode::commandCallback(const std_msgs::msg::Char::SharedPtr msg) const {
        const bool active = isRightMotorActive(msg->data);
        RCLCPP_INFO(this->get_logger(), "[RIGHT MOTOR] %s", active ? "ACTIVATED" : "DEACTIVATED");
    }

    bool RightMotorNode::isRightMotorActive(char command) const {
        return command == 'w' || command == 's' || command == 'a';
    }
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<cpp_pubsub::RightMotorNode>());
    rclcpp::shutdown();
    return 0;
}
