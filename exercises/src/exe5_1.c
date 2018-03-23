#include <stdio.h>

/* Use setvbuf to realise function setbuf */

void mysetbuf(FILE* stream, char* buf){
	if(!buf)
		setvbuf(stream, NULL,_IONBF, 0);
	else if(stream == stdin || stream == stdout || stream == stderr)
		setvbuf(stream, buf, _IOLBF, BUFSIZ);
	else 
		setvbuf(stream, buf, _IOFBF, BUFSIZ);
	return ;
}
