#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"

char	*env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(){
	pid_t	pid;

	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0){
		if (execle("/home/invoker/bin/echoall",
					"echoall", "arg1", "Arg2", (char*)0,
					env_init) < 0)
			err_sys("execle error");
	}
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("waitpid error");

	if( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0){
		if (execlp("echoall",
					"echoall", "only 1 arg", (char*)0) < 0)
			err_sys("execlp error");
	}
	exit(0);

}
