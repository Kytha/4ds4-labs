/****************************************************************************
 *
 *   Copyright (C) 2021 PX4 Development Team. All rights reserved.
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


#pragma once

#include <stddef.h>

#include <uORB/uORB.h>

static constexpr size_t ORB_TOPICS_COUNT{198};
static constexpr size_t orb_topics_count() { return ORB_TOPICS_COUNT; }

/*
 * Returns array of topics metadata
 */
extern const struct orb_metadata *const *orb_get_topics() __EXPORT;

enum class ORB_ID : uint8_t {
	action_request = 0,
	actuator_armed = 1,
	actuator_controls = 2,
	actuator_controls_0 = 3,
	actuator_controls_1 = 4,
	actuator_controls_2 = 5,
	actuator_controls_3 = 6,
	actuator_controls_status = 7,
	actuator_controls_status_0 = 8,
	actuator_controls_status_1 = 9,
	actuator_controls_virtual_fw = 10,
	actuator_controls_virtual_mc = 11,
	actuator_motors = 12,
	actuator_outputs = 13,
	actuator_outputs_sim = 14,
	actuator_servos = 15,
	actuator_servos_trim = 16,
	actuator_test = 17,
	adc_report = 18,
	airspeed = 19,
	airspeed_validated = 20,
	airspeed_wind = 21,
	autotune_attitude_control_status = 22,
	battery_status = 23,
	camera_capture = 24,
	camera_status = 25,
	camera_trigger = 26,
	cellular_status = 27,
	collision_constraints = 28,
	collision_report = 29,
	commander_state = 30,
	control_allocator_status = 31,
	cpuload = 32,
	debug_array = 33,
	debug_key_value = 34,
	debug_value = 35,
	debug_vect = 36,
	differential_pressure = 37,
	distance_sensor = 38,
	ekf2_timestamps = 39,
	esc_report = 40,
	esc_status = 41,
	estimator_attitude = 42,
	estimator_baro_bias = 43,
	estimator_event_flags = 44,
	estimator_global_position = 45,
	estimator_gps_status = 46,
	estimator_innovation_test_ratios = 47,
	estimator_innovation_variances = 48,
	estimator_innovations = 49,
	estimator_local_position = 50,
	estimator_odometry = 51,
	estimator_optical_flow_vel = 52,
	estimator_selector_status = 53,
	estimator_sensor_bias = 54,
	estimator_states = 55,
	estimator_status = 56,
	estimator_status_flags = 57,
	estimator_visual_odometry_aligned = 58,
	estimator_wind = 59,
	event = 60,
	failure_detector_status = 61,
	follow_target = 62,
	fw_virtual_attitude_setpoint = 63,
	generator_status = 64,
	geofence_result = 65,
	gimbal_device_attitude_status = 66,
	gimbal_device_information = 67,
	gimbal_device_set_attitude = 68,
	gimbal_manager_information = 69,
	gimbal_manager_set_attitude = 70,
	gimbal_manager_set_manual_control = 71,
	gimbal_manager_status = 72,
	gimbal_v1_command = 73,
	gps_dump = 74,
	gps_inject_data = 75,
	heater_status = 76,
	home_position = 77,
	hover_thrust_estimate = 78,
	input_rc = 79,
	internal_combustion_engine_status = 80,
	iridiumsbd_status = 81,
	irlock_report = 82,
	landing_gear = 83,
	landing_target_innovations = 84,
	landing_target_pose = 85,
	led_control = 86,
	log_message = 87,
	logger_status = 88,
	mag_worker_data = 89,
	magnetometer_bias_estimate = 90,
	manual_control_input = 91,
	manual_control_setpoint = 92,
	manual_control_switches = 93,
	mavlink_log = 94,
	mavlink_tunnel = 95,
	mc_virtual_attitude_setpoint = 96,
	mission = 97,
	mission_result = 98,
	mount_orientation = 99,
	navigator_mission_item = 100,
	npfg_status = 101,
	obstacle_distance = 102,
	obstacle_distance_fused = 103,
	offboard_control_mode = 104,
	onboard_computer_status = 105,
	optical_flow = 106,
	orbit_status = 107,
	parameter_update = 108,
	ping = 109,
	position_controller_landing_status = 110,
	position_controller_status = 111,
	position_setpoint = 112,
	position_setpoint_triplet = 113,
	power_button_state = 114,
	power_monitor = 115,
	pps_capture = 116,
	pwm_input = 117,
	px4io_status = 118,
	radio_status = 119,
	rate_ctrl_status = 120,
	rc_channels = 121,
	rc_parameter_map = 122,
	rpm = 123,
	rtl_time_estimate = 124,
	safety = 125,
	satellite_info = 126,
	sensor_accel = 127,
	sensor_accel_fifo = 128,
	sensor_baro = 129,
	sensor_combined = 130,
	sensor_correction = 131,
	sensor_gps = 132,
	sensor_gyro = 133,
	sensor_gyro_fft = 134,
	sensor_gyro_fifo = 135,
	sensor_hygrometer = 136,
	sensor_mag = 137,
	sensor_preflight_mag = 138,
	sensor_selection = 139,
	sensors_status_imu = 140,
	system_power = 141,
	takeoff_status = 142,
	task_stack_info = 143,
	tecs_status = 144,
	telemetry_status = 145,
	test_motor = 146,
	timesync = 147,
	timesync_status = 148,
	trajectory_bezier = 149,
	trajectory_setpoint = 150,
	trajectory_waypoint = 151,
	transponder_report = 152,
	tune_control = 153,
	uavcan_parameter_request = 154,
	uavcan_parameter_value = 155,
	ulog_stream = 156,
	ulog_stream_ack = 157,
	vehicle_acceleration = 158,
	vehicle_air_data = 159,
	vehicle_angular_acceleration = 160,
	vehicle_angular_acceleration_setpoint = 161,
	vehicle_angular_velocity = 162,
	vehicle_angular_velocity_groundtruth = 163,
	vehicle_attitude = 164,
	vehicle_attitude_groundtruth = 165,
	vehicle_attitude_setpoint = 166,
	vehicle_command = 167,
	vehicle_command_ack = 168,
	vehicle_constraints = 169,
	vehicle_control_mode = 170,
	vehicle_global_position = 171,
	vehicle_global_position_groundtruth = 172,
	vehicle_gps_position = 173,
	vehicle_imu = 174,
	vehicle_imu_status = 175,
	vehicle_land_detected = 176,
	vehicle_local_position = 177,
	vehicle_local_position_groundtruth = 178,
	vehicle_local_position_setpoint = 179,
	vehicle_magnetometer = 180,
	vehicle_mocap_odometry = 181,
	vehicle_odometry = 182,
	vehicle_rates_setpoint = 183,
	vehicle_roi = 184,
	vehicle_status = 185,
	vehicle_status_flags = 186,
	vehicle_thrust_setpoint = 187,
	vehicle_torque_setpoint = 188,
	vehicle_trajectory_bezier = 189,
	vehicle_trajectory_waypoint = 190,
	vehicle_trajectory_waypoint_desired = 191,
	vehicle_vision_attitude = 192,
	vehicle_visual_odometry = 193,
	vtol_vehicle_status = 194,
	wheel_encoders = 195,
	wind = 196,
	yaw_estimator_status = 197,

	INVALID
};

const struct orb_metadata *get_orb_meta(ORB_ID id);
