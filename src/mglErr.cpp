#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "mglErr.h"

/*Display all current openGL errors; clears error list.
Return 1 if errors found, else return 0*/
int mglErr()
{
    GLenum errorCode = glGetError();

    if(!errorCode)
    {
        return 0;
    }

    while(errorCode)
    {
        printf("[ OpenGL Error %d ]\n", errorCode);
        errorCode = glGetError();
    }

    return 1;
}

void mglErr_wrap()
{
    if(mglErr())
    {
        showCallStack(2, 100);
        glfwTerminate();
        exit(-1);
    }
}

extern "C"
{
#include <stdio.h>
#include <execinfo.h>

    void __cyg_profile_func_enter(void *, void *) __attribute__((no_instrument_function));
    void __cyg_profile_func_exit(void *, void *) __attribute__((no_instrument_function));

    void __cyg_profile_func_enter(void *this_fn, void *call_site)
    {
        mglErr_wrap();
    }

    void __cyg_profile_func_exit(void *this_fn, void *call_site)
    {
        mglErr_wrap();
    }
}

void showCallStack(unsigned int startDepth, unsigned int maxDepth)
{
    int i, j, callCount;
    void* buffer[maxDepth];
    char **strings;
    callpair pairs[maxDepth];

    callCount = backtrace(buffer, maxDepth);
    strings = backtrace_symbols(buffer, callCount);
    if(strings == NULL)
    {
        printf("backtrace error\n");
        return;
    }

    printf("-CALLSTACK-\n");

    for(i = startDepth; i < callCount; i++)
    {
        pairs[i].file = &strings[i][0];

        for(j = 0; j < 200; j++)
        {
            if(strings[i][j] == '(')
            {
                strings[i][j] = '\0';
                pairs[i].func = &strings[i][j + 1];
            }
            if(strings[i][j] == '+')
            {
                strings[i][j] = '\0';
                break;
            }
        }
        printf("%30s | %s\n", pairs[i].func, pairs[i].file);
    }

    printf("-END-\n");


    free(strings);
}
