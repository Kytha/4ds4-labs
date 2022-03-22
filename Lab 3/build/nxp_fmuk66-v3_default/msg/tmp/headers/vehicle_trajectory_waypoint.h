/****************************************************************************
 *
 *   Copyright (C) 2013-2021 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/* Auto-generated by genmsg_cpp from file /home/ds/Documents/23/PX4-Autopilot/msg/vehicle_trajectory_waypoint.msg */


#pragma once


#include <uORB/uORB.h>

#include <uORB/topics/trajectory_waypoint.h>

#ifndef __cplusplus
#define VEHICLE_TRAJECTORY_WAYPOINT_MAV_TRAJECTORY_REPRESENTATION_WAYPOINTS 0
#define VEHICLE_TRAJECTORY_WAYPOINT_POINT_0 0
#define VEHICLE_TRAJECTORY_WAYPOINT_POINT_1 1
#define VEHICLE_TRAJECTORY_WAYPOINT_POINT_2 2
#define VEHICLE_TRAJECTORY_WAYPOINT_POINT_3 3
#define VEHICLE_TRAJECTORY_WAYPOINT_POINT_4 4
#define VEHICLE_TRAJECTORY_WAYPOINT_NUMBER_POINTS 5

#endif


#ifdef __cplusplus
struct __EXPORT vehicle_trajectory_waypoint_s {
#else
struct vehicle_trajectory_waypoint_s {
#endif
	uint64_t timestamp;
	uint8_t type;
	uint8_t _padding0[7]; // required for logger
	struct trajectory_waypoint_s waypoints[5];


#ifdef __cplusplus
	static constexpr uint8_t MAV_TRAJECTORY_REPRESENTATION_WAYPOINTS = 0;
	static constexpr uint8_t POINT_0 = 0;
	static constexpr uint8_t POINT_1 = 1;
	static constexpr uint8_t POINT_2 = 2;
	static constexpr uint8_t POINT_3 = 3;
	static constexpr uint8_t POINT_4 = 4;
	static constexpr uint8_t NUMBER_POINTS = 5;

#endif
};

/* register this as object request broker structure */
ORB_DECLARE(vehicle_trajectory_waypoint);
ORB_DECLARE(vehicle_trajectory_waypoint_desired);


#ifdef __cplusplus
void print_message(const orb_metadata *meta, const vehicle_trajectory_waypoint_s& message);
#endif
