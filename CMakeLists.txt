cmake_minimum_required(VERSION 2.8.3)
project(simple_walker_algorithm)

add_compile_options(-std=c++11)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs)

## Declare a catkin package
catkin_package()

## Build walker
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(simpleWalker src/main.cpp src/walker.cpp)
#add_executable(simpleWalker src/main.cpp)
target_link_libraries(simpleWalker ${catkin_LIBRARIES})

