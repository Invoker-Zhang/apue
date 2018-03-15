#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"

static void err_doit(int, const char*, va_list);

char* pname = NULL;		/* caller can set this from argv[0] */

/* Nonfatal error related to a system call
 * Print a message and return. */

void err_ret(const char* fmt, ...){
	
}
