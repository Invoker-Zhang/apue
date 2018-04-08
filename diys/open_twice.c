#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ourhdr.h"

int main(){
	int fd1, fd2;
	if( (fd1 = open("test.test", O_WRONLY)) < 0)
		err_sys("fail to open file once");
	if( (fd2 = open("test.test", O_WRONLY)) < 0)
		err_sys("fail to open file at second time");
	exit(0);
}
