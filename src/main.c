#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "functions.h"





int main(void)
{
    struct DLL *l_of_thieves;
    l_of_thieves = malloc(sizeof(struct DLL));

    l_of_thieves->next = NULL;
    l_of_thieves->prec = NULL;

    struct DLL *l_of_out_thieves;
    l_of_out_thieves = malloc(sizeof(struct DLL));

    l_of_out_thieves->next = NULL;
    l_of_out_thieves->prec = NULL;

    int i;

    for(i = 1 ; i <= 41 ; i++)
    {
        append_list(l_of_thieves,i);
    }

    transfer_from_list_to_new_list(l_of_thieves,l_of_out_thieves,37);

    print_list(l_of_thieves);
    printf("\n\n\n");
    print_list(l_of_out_thieves);


    return (0);
}