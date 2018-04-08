#include <fcntl.h>
#include "ourhdr.h"

void set_fl(int fd, int flags){
	int val;

	if( (val = fcntl(fd, F_GETFL,0)) <0)
		err_sys("fcntl F_GETFL error");
	val |= flags;
	if( fcntl(fd, F_GETFL,val) <0)
		err_sys("fcntl F_GETFL error");

}