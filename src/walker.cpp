/**
 * BSD 3 clauses Liscense
 *
 * Copyright <2018> <Chien-Te Lee>
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions 
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in 
 * the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from 
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @file walker.cpp
 *  @brief implementation of walker class
 *  @copyright (c) 2018 Chien-Te Lee
 *  @author Chien-Te Lee
 *  @date   11/20/2018
 *
 *  This program implements fucntions of walker class.
 *  
 */

#include <walker.h>

/**
 *  @brief constructor of walker class
 *  @param none
 *  @return none
 */
walker::walker() {
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;
    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;
    veloclity_pub = n.advertise<geometry_msgs::Twist>
                      ("/mobile_base/commands/velocity", 10);
    laserScan_sub = n.subscribe<sensor_msgs::LaserScan>
                      ("/scan", 10, &walker::laserScanCallBack, this);
}


/**
 *  @brief This function checks wheter the robot needs to turn based on laserscan data
 *  @param scan is the received laserscan data
 *  @return none
 */
void walker::laserScanCallBack(const sensor_msgs::LaserScan::ConstPtr& scan) {
    int ranges = scan->ranges.size();
    bool turn = false;

    // checks wheter the distance to wall is less than 0.8
    for (int i = 0; i < ranges; ++i) {
        if (scan->ranges[i] < 0.8)
            turn = true;
    }

    // if too close, start turning, else go straight
    if (turn) {
        msg.linear.x = 0.0;
        msg.angular.z = 0.5;
    } else {
        msg.linear.x = 0.3;
        msg.angular.z = 0.0;
    }

    // publish the velocity immediately
    veloclity_pub.publish(msg);
}

