#include <stdio.h>
#include <stdarg.h>
#include "assert.h"

int my_assert(int condition, const char *message, ...)
{
    if(!condition){
        va_list args;
        va_start(args, message);
        vfprintf(stderr, message, args);
        va_end(args);
        return 1;
    }

    return 0;
}


