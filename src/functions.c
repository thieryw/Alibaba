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
int get_length(struct DLL *l)
{
    return(l->prec->index);
}

void remove_elem(struct DLL **l,int n,int length)
{
    struct DLL *temp = *l;
    
    if(n < 0 || n > length)
    {
        printf("Out of range!\n");
        return;
    }
    if(temp->index != n)
    {
        remove_elem(&temp->prec, n, length);
    }
    else
    {
        temp->prec->next = temp->next;
        temp->next->prec = temp->prec;
        free(temp);
    }
    if (temp->index != 0)
    {
        temp->index = temp->index - 1;
    }
}

void print_list(struct DLL *l)
{
    printf("%d %d\n", l->i, l->index);
    if (l->next->index != 0)
    {
        print_list(l->next);
    }
}
