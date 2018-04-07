#include "ourhdr.h"

int main(){
	char	*ptr;
	int		size;

	if(chdir("/usr/") < 0)
		err_sys("chdir failed");

	ptr = (char*)malloc(100);
	if( getcwd(ptr, 100) == NULL)
		err_sys("getcwd failed");

	printf("cwd = %s\n", ptr);
	exit(0);
}
