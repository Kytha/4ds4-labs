#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/log.h>
#include <drivers/drv_hrt.h>
#include <uORB/Publication.hpp>
#include <uORB/topics/test_motor.h>


#define DC_MOTOR	0

extern "C" __EXPORT int hello_world_main(int argc, char *argv[]);

int hello_world_main(int argc, char *argv[])
{
	test_motor_s test_motor;
	double motor_value = 0; // a number between 0 to 1
	uORB::Publication<test_motor_s> test_motor_pub(ORB_ID(test_motor));
	
	while(1)
	{
		PX4_INFO("Enter speed value (0 to 1). If you enter a value outside the range, the motor will be stopped and the application will be terminated.");
		scanf("%lf", &motor_value);
		
		if(motor_value > 1.0 || motor_value < 0)
		break;

		PX4_INFO("Motor speed is %f", motor_value);
		test_motor.timestamp = hrt_absolute_time();
		test_motor.motor_number = DC_MOTOR;
		test_motor.value = (float)motor_value;
		test_motor.action = test_motor_s::ACTION_RUN;
		test_motor.driver_instance = 0;
		test_motor.timeout_ms = 0;
		test_motor_pub.publish(test_motor);
	}

	PX4_INFO("The motor will be stopped");
	test_motor.timestamp = hrt_absolute_time();
	test_motor.motor_number = DC_MOTOR;
	test_motor.action = test_motor_s::ACTION_STOP;
	test_motor.driver_instance = 0;
	test_motor.timeout_ms = 0;
	
	test_motor_pub.publish(test_motor);

	return 0;
}
