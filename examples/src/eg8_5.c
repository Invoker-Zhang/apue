#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"

int main(){
	pid_t pid;
	
	printf("pid = %d\n", getpid());
	if( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0){
		if ( (pid = fork()) < 0)
			err_sys("fork error");
		else if(pid > 0){
			printf("first child pid: %d\n", getpid());
			exit(0);
		}
		sleep(2);
		printf("second child, ppid = %d\n", getppid());
		exit(0);
	}

	if( waitpid(pid, NULL, 0) != pid)
		err_sys("waitpid error");
	return 0;
}
