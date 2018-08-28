#include <stdio.h>
#include <stdlib.h>
#include "struct.h"



void append_list(struct DLL *l, int n)
{
    int prec_index;
    struct DLL *temp = l->prec;
    if(l->next == NULL && l->prec == NULL)
    {
        l->i = n;
        l->index = 0;
        l->next = malloc(sizeof(struct DLL));
        l->prec = malloc(sizeof(struct DLL));
        l->next = l;
        l->prec = l;
    }
    else
    {
        prec_index = l->prec->index;
        l->prec = l->prec + sizeof(struct DLL);
        l->prec = malloc(sizeof(struct DLL));
        l->prec->next = l;
        l->prec->prec = temp;
        temp->next = l->prec;
        l->prec->i = n;
        l->prec->index = prec_index + 1;

        
        if(l->next->index == 0)
        {
            l->next = l->prec;
        }
    }
}

void print_list(struct DLL *l)
{
    printf("%d\n",l->i);
    if(l->next->index != 0)
    {
        print_list(l->next);
    }
}