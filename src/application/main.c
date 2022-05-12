#define  _GNU_SOURCE

#define RECONOS_DEBUG


#define SETUP 2

#include "reconos.h"
#include "reconos_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "memory.h"
#include "axi_modelcar.h"

#include "main.h"



void init_msg(void)
{


	return;
}


static void exit_signal(int sig) 
{
	reconos_cleanup();
	printf("[ReconROS] aborted\n");
	exit(0);
}

int main(int argc, char **argv) 
{
	reconos_init();
	reconos_app_init();

	init_msg();

	


	signal(SIGINT, exit_signal);
	signal(SIGTERM, exit_signal);
	signal(SIGABRT, exit_signal);



	reconos_thread_create_swt_carcontrol(0,0);



	while(1)
	{
		sleep(100);
	}


	reconos_app_cleanup();
	reconos_cleanup();
	return 0;
}


