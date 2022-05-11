/********************************************************************          
* rt_carcontrol.cpp      -- dummy hardware thread                   *
*                                                                   *
*                                                                   * 
*																	* 
* Author(s):  Christian Lienen                                      *   
*                                                                   *   
********************************************************************/

#include "reconos_thread.h"
#include "reconos_calls.h"

#include <ackermann_msgs/msg/ackermann_drive.h>

THREAD_ENTRY()
{
    THREAD_INIT();
	uint64_t pInitData = GET_INIT_DATA();


	while (1)
	{
		uint64_t ram[10];
		uint64_t pMessage;
        

		pMessage= ROS_SUBSCRIBE_TAKE(rcarcontrol_subdrivecmd, rcarcontrol_drive_cmd);
		MEM_READ(pMessage, ram, sizeof(ackermann_msgs__msg__AckermannDrive));

		MEM_WRITE(ram, pInitData, 4);

		
	}

}
