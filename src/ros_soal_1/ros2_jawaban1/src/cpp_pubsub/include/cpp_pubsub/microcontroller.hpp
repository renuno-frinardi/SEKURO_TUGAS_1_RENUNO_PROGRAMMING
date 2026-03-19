#ifndef CPP_PUBSUB_MICROCONTROLLER_HPP
#define CPP_PUBSUB_MICROCONTROLLER_HPP

#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/char.hpp"

// Node untuk menerima input dari pengguna
namespace cpp_pubsub {
    class MicrocontrollerNode : public rclcpp::Node {
        public:
            MicrocontrollerNode();
            void inputLoop();

        private:
            bool isValidCommand(char input) const;

            rclcpp::Publisher<std_msgs::msg::Char>::SharedPtr publisher_;
    };
} 

#endif  
