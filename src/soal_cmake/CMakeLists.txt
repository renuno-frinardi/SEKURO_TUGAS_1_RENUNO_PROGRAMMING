cmake_minimum_required(VERSION 3.8)
project(mcu_controller)

# Atur standar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output executable ke folder bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Ambil semua source file
add_executable(${PROJECT_NAME} 
    src/mcu.cpp
    src/mcu_cam_controller.cpp
    src/mcu_walker.cpp
    src/main.cpp
)

# Include directory
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Simpan executable ke folder bin
install(TARGETS
    ${PROJECT_NAME}
    DESTINATION bin
)