#include "hello.h"
#include <stdio.h>

void greet (const char * name)
{
    if (name != NULL)
    {
        printf ("Hello, %s\n", name);
    }
    else
    {
        puts ("Hello, world!");
    }
}
