cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

# mengatur compiler untuk C++
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# menemukan dependencies untuk project ROS2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# membuat executable untuk microcontroller_node, left_motor_node, dan right_motor_node
add_executable(microcontroller_node src/microcontroller.cpp)
ament_target_dependencies(microcontroller_node rclcpp std_msgs)
target_include_directories(microcontroller_node PRIVATE include)

add_executable(left_motor_node src/left-motor.cpp)
ament_target_dependencies(left_motor_node rclcpp std_msgs)
target_include_directories(left_motor_node PRIVATE include)

add_executable(right_motor_node src/right-motor.cpp)
ament_target_dependencies(right_motor_node rclcpp std_msgs)
target_include_directories(right_motor_node PRIVATE include)

# menginstal executable ke dalam direktori lib/${PROJECT_NAME}
install(TARGETS
  microcontroller_node
  left_motor_node
  right_motor_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
