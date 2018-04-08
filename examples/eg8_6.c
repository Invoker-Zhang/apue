#include <sys/types.h>
#include "ourhdr.h"

static void charatatime(char *);

int main(){
	pid_t pid;

	TELL_WAIT();

	if ( (pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0){
		WAIT_PARENT();
		charatatime("output from child");
	} else {
		charatatime("output from parent");
		TELL_CHILD(pid);
	}
	exit(0);
}

static void charatatime(char* msg){
	char * ptr;
	int c;

	setbuf(stdout, NULL);
	for(ptr = msg; c = *ptr++; )
		putc(c, stdout);
}
