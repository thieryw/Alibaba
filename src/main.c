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

    int i;

    for(i = 1 ; i <= 41 ; i++)
    {
        append_list(l_of_thieves,i);
    }

    remove_elem(&l_of_thieves, 0, get_length(l_of_thieves));

    printf("%d\n\n", l_of_thieves->prec->next->i);

    print_list(l_of_thieves);

    return (0);
}