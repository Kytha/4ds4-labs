#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/log.h>
#include <uORB/topics/rc_channels.h>

extern "C" __EXPORT int hello_world_main(int argc, char *argv[]);

int hello_world_main(int argc, char *argv[])
{	
	int rc_channels_handle;
	rc_channels_s rc_data;
	
	rc_channels_handle = orb_subscribe(ORB_ID(rc_channels));
	orb_set_interval(rc_channels_handle, 200);
	
	while(1)
	{
		orb_copy(ORB_ID(rc_channels), rc_channels_handle, &rc_data);
		PX4_INFO("Channel 0 = %f, Channel 1 = %f, Channel 2 = %f", (double)rc_data.channels[0], (double)rc_data.channels[1], (double)rc_data.channels[2]);
		px4_usleep(200000);
	}
	
	return 0;
}
