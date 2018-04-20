#include "ourhdr.h"
#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo){
	return;		/* nothing to do, just return to wake up the pause */
}

static int sleep1(int secs){
	if(signal(SIGALRM, sig_alrm) == SIG_ERR){
		return (secs);
	}
	alarm(secs);
	pause();
	return (alarm(0));
}

int main(){
	sleep1(5);
	return 0;
}
