#include "config.h"
#include "gettext.h"
#include "hello.h"
#include <stdlib.h>

void main (int argc, char * argv [])
{
    setlocale (LC_ALL, "");
    bindtextdomain (PACKAGE, LOCALEDIR);
    textdomain (PACKAGE);

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
    
    exit (EXIT_SUCCESS);
}
