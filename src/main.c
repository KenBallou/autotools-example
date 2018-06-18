#include "hello.h"
#include <stdlib.h>

void main (int argc, char * argv [])
{
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
