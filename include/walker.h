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

/** @file walker.h
 *  @brief definition of walker class
 *  @copyright (c) 2018 Chien-Te Lee
 *  @author Chien-Te Lee
 *  @date   11/20/2018
 *
 *  This program contains definition of walker class.
 *  
 */


#ifndef INCLUDE_WALKER_H_
#define INCLUDE_WALKER_H_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>

/**
 *  @brief definition of walker class
 *  @param none
 *  @return none
 */
class walker{
public:
    /**
     *  @brief constructor of walker class
     *  @param none
     *  @return none
     */
    walker();

private:
    ///< geometry twist message of velocity to be pulished
    geometry_msgs::Twist msg;

    ///< handle ros node
    ros::NodeHandle n;

    ///< ros publisher to publish velocity
    ros::Publisher veloclity_pub;

    ///< ros subscriber to read laserscan data
    ros::Subscriber laserScan_sub;

    /**
     *  @brief This function checks wheter the robot needs to turn
     *  @param scan is the received laserscan data
     *  @return none
     */
    void laserScanCallBack(const sensor_msgs::LaserScan::ConstPtr& scan);
};


#endif    // INCLUDE_WALKER_H_


