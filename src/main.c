#include "config.h"
#include "gettext.h"
#include "hello.h"
#include <stdlib.h>
#if ENABLE_NLS && HAVE_GETTEXT
#include <locale.h>
#endif

int main (int argc, char * argv [])
{
#if ENABLE_NLS && HAVE_GETTEXT
    setlocale (LC_ALL, "");
    bindtextdomain (PACKAGE, LOCALEDIR);
    textdomain (PACKAGE);
#endif
    
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++ i)
        {
            greet (argv [i]);
        }
    }
    else
    {
        greet (NULL);
    }
    
    return EXIT_SUCCESS;
}
