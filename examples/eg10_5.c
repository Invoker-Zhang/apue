#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include "ourhdr.h"

static jmp_buf	env_alrm;

static void sig_alrm(int signo){
	longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int nsecs){
	if(signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal error");
	if(setjmp(env_alrm) == 0){
		alarm(nsecs);
		pause();
	}
	return (alarm(0));
}
 
int main(){
	sleep2(5);
	return 0;
}
