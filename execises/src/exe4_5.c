#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ourhdr.h"

int main(){
	if( open("file.temp",O_RDWR) < 0)
		err_sys("open error");
	if( unlink("file.temp") < 0)
		err_sys("unlink error");

	printf("file unlinked\n");
	sleep(15);
	printf("done\n");

	exit(0);
}

