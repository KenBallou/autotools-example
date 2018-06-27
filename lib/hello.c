#include "config.h"
#include "hello.h"
#include "gettext.h"
#include <stdio.h>

#if ENABLE_NLS && HAVE_GETTEXT
#define _(s) gettext(s)
#else
#define _(s) s
#endif

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
