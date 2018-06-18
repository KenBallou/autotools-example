#include <stdlib.h>

void main ()
{
    extern void greet (void);

    greet ();
    exit (EXIT_SUCCESS);
}
