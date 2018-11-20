## Overview
This is a simple ROS package modified with TurtleBot simulation. It implements a simple walker
algorithm to enable TurtleBot to move forward when ahead is clear, and rotate to change direction
when it is close to objects.

## Licence
- BSD 3-clause Liscense
```
Copyright <2018> <Chien-Te Lee>

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
 following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

## Dependencies
- Ubuntu 16.04
- CMake
- ROS kinetic
- TurtleBot

## How to build and compile
- create catkin workspace
- clone simple_walker_algorithm package into catkin workspace
- build catkin workspace
```
$ source /opt/ros/kinetic/setup.bash
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ git clone --recursive https://github.com/ChienTeLee/simple_walker_algorithm.git
$ cd ~/catkin_ws
$ catkin_make
```

## How to run simulation
- use launch file to run simulation
```
$ cd ~/catkin_ws
$ source ./devel/setup.bash
$ roslaunch simple_walker_algorithm simpleWalker.launch
```

## How to record bagfile
- use launch file to run simulation and enable rosbag
```
$ cd ~/catkin_ws
$ source ./devel/setup.bash
$ roslaunch simple_walker_algorithm simpleWalker.launch record:=true
```

## How to check rosbag file
```
$ cd ~/catkin_ws/src/simple_walker_algorithm/result
$ rosbag info walker_record.bag
```

## How to replay rosbag record
- run ros master on first terminal
```
$ roscore
```

- play rosbag on second terminal
```
$ cd ~/catkin_ws/src/simple_walker_algorithm/result
$ rosbag play walker_record.bag
```


