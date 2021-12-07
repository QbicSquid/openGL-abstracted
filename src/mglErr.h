/*Allows openGL error detection using function instrumentation in GCC compiler.
set -finstrument-functions and -rdynamic flags to enable*/
#ifndef MGLERR_H
#define MGLERR_H

struct callpair
{
    char *func;
    char *file;
};

int mglErr() __attribute__((no_instrument_function));
void showCallStack(unsigned int startDepth,
        unsigned int maxdepth) __attribute__((no_instrument_function));
void mglErr_wrap()
    __attribute__((no_instrument_function));

#endif

