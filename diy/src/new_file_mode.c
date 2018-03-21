#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "ourhdr.h"

int main(int argc, char **argv){
	if( argc != 2 )  
		err_quit("usage: ./a.out filename");
	int fd;
	if( (fd = open(argv[1], O_WRONLY | O_CREAT)) < 0)
		err_sys("create error");
	printf("euid = %d\n",geteuid());

	return 0;
}
