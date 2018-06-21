#include "config.h"
#include "hello.h"
#include "gettext.h"
#include <stdio.h>
#define _(s) gettext(s)

void greet (const char * name)
{
    if (name != NULL)
    {
        printf (_("Hello, %s\n"), name);
    }
    else
    {
        puts (_("Hello, world!"));
    }
}
