#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "functions.h"





int main(void)
{
    struct DLL *l_of_thieves;
    l_of_thieves = malloc(sizeof(struct DLL));

    int i;
    
    l_of_thieves->next = NULL;
    l_of_thieves->prec = NULL;

    for(i = 1 ; i <= 41 ; i++)
    {
        append_list(l_of_thieves,i);
    }

    remove_elem(&l_of_thieves,9,get_length(l_of_thieves));


    print_list(l_of_thieves);

    return (0);
}