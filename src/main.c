#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "ali_functions.h"





int main(void)
{
    struct DLL l_of_thieves;
    int i;
    l_of_thieves.next = NULL;
    l_of_thieves.prec = NULL;

    for(i = 1 ; i <= 41 ; i++)
    {
        append_list(&l_of_thieves,i);
    }


    print_list(&l_of_thieves);

}