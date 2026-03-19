#include "cpp_pubsub/microcontroller.hpp"

#include <cctype>
#include <iostream>

namespace cpp_pubsub {
    MicrocontrollerNode::MicrocontrollerNode() : Node("microcontroller_node") {
        publisher_ = this->create_publisher<std_msgs::msg::Char>("microcontroller/buttons", 10);
    }

    void MicrocontrollerNode::inputLoop() {
        RCLCPP_INFO(this->get_logger(), "Type command: w/a/s/d then Enter. Press q then Enter to quit.");

        char input;
        while (rclcpp::ok() && std::scanf(" %c", &input)) {
            if (input == 'q') {
                RCLCPP_INFO(this->get_logger(), "Stopping microcontroller input loop.");
                break;
            }

            if (!isValidCommand(input)) {
                RCLCPP_WARN(this->get_logger(), "Invalid input '%c'. Use only w/a/s/d.", input);
                continue;
            }

            std_msgs::msg::Char msg;
            msg.data = input;
            publisher_->publish(msg);
            RCLCPP_INFO(this->get_logger(), "[INPUT] '%c'", msg.data);
        }
    }

    bool MicrocontrollerNode::isValidCommand(char input) const {
        return input == 'w' || input == 'a' || input == 's' || input == 'd';
    }
} 

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<cpp_pubsub::MicrocontrollerNode>();
    node->inputLoop();

    rclcpp::shutdown();
    return 0;
}
