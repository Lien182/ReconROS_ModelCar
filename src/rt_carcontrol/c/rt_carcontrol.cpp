extern "C" {
#include "reconos_thread.h"
#include "reconos_calls.h"
}

#define DEBUG_LANE_CONTROL 0


extern "C" THREAD_ENTRY(); // this is required because of the mixture of c and c++

THREAD_ENTRY() {
	
        #warning TODO
        double MAX_VEL = 1.0;

        while(1)
        {
            ROS_SUBSCRIBE_TAKE(rcarcontrol_subdrivecmd, rcarcontrol_drive_cmd);
            if(DEBUG_LANE_CONTROL)
                printf("[Car Control] subscribe done: %f\n", rcarcontrol_drive_cmd->speed);
 

        }
        

    	return;
}
