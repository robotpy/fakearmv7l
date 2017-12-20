#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <stdlib.h>     /* for EXIT_FAILURE */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/utsname.h>
#include <limits.h>
#include <errno.h>
 
#ifndef RTLD_NEXT
  #define RTLD_NEXT      ((void *) -1l)
#endif
 
typedef int (*uname_t) (struct utsname * buf);
static void *getLibFunc(const char *funcname)
{
    void *func;
    char *error = NULL;
 
    func = dlsym(RTLD_NEXT, funcname);
 
    if ( func == NULL ) {
        error = dlerror();
        fprintf(stderr, "I can't locate lib function `%s' error: %s",
                funcname, error);
        exit(EXIT_FAILURE);
    }
    return func;
}
 
int uname(struct utsname *buf)
{
    int ret;
    uname_t real_uname = (uname_t) getLibFunc("uname");

    ret = real_uname((struct utsname *) buf);

    memset(buf->machine, 0, sizeof(buf->machine));
    strncpy(buf->machine, "armv7l", sizeof(buf->machine)-1);

    return ret;
}