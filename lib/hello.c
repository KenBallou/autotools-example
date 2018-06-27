#include "config.h"
#include "hello.h"
#include "gettext.h"
#include <stdio.h>

#if ENABLE_NLS && HAVE_GETTEXT
#define HELLOPACKAGE "hello"
#define _(s) dgettext(HELLOPACKAGE, s)
#else
#define _(s) s
#endif

void greet (const char * name)
{
#if ENABLE_NLS && HAVE_GETTEXT
    bindtextdomain (HELLOPACKAGE, LOCALEDIR);
#endif
    
    if (name != NULL)
    {
        printf (_("Hello, %s\n"), name);
    }
    else
    {
        puts (_("Hello, world!"));
    }
}
