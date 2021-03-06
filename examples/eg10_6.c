#include <signal.h>
#include <setjmp.h>
#include "ourhdr.h"

unsigned int	sleep2(unsigned int);
static void		sig_int(int);
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
	unsigned int	unslept;
	if(signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	unslept = sleep2(5);
	printf("sleep2 returned: %u\n", unslept);
	exit(0);
}

static void sig_int(int signo){
	int		i;
	volatile int j;
	printf("\nsig_int starting\n");
	for(int i = 0; i < 2000000; i++){
		j+= i * i;
	}
	printf("sig_int finished\n");
	return;
}
