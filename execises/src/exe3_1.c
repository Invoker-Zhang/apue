#include <sys/types.h>
#include "ourhdr.h"

/* test if offset of stdin can be seeked */

int main(){
	if( lseek(STDIN_FILENO, 0, SEEK_CUR) < 0)
		printf("can't seek\n");
	else
		printf("seek OK\n");
	return 0;
}
