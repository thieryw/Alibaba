#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLL.h"

void append_DLL(struct DLL **pl, __uint32_t n)
{
    struct DLL *e = malloc(sizeof(struct DLL));

    if (*pl == NULL)
    {

        *e = (struct DLL){.next = e, .prec = e, .n = n};

        *pl = e;

    }
    else
    {

        *e = (struct DLL){.next = *pl, .prec = (*pl)->prec, .n = n};

        (*pl)->prec->next = e;

        (*pl)->prec = e;
    }
}

void free_DLL(struct DLL **pl)
{

    while ((*pl) != NULL)
    {

        del_elem_DLL(pl, *pl);
    }
}

void del_elem_DLL(struct DLL **pl, struct DLL *e)
{

    if (e == *pl)
    {

        if ((*pl)->next == *pl)
        {
            *pl = NULL;
        }
        else
        {
            *pl = (*pl)->next;
        }
    }

    e->prec->next = e->next;
    e->next->prec = e->prec;

    free(e);
}

char *dll_to_string(struct DLL *l)
{

    char *str;

    if (l == NULL)
    {

        char message[] = "List is empty!\n";

        str = malloc(strlen(message) + 1);

        sprintf(str, "%s", message);

        return str;
    }

    str = malloc(sizeof(char) * 1);

    str[0] = '\0';

    for (struct DLL *e = l; 1; e = e->next)
    {

        char *new_str = malloc(sizeof(char) * (strlen(str) + 12));

        sprintf(new_str, "%s%d ", str, e->n);

        free(str);

        str = new_str;

        if (e->next == l)
        {
            break;
        }
    }

    return str;
}

void print_list(struct DLL *l)
{

    char *str = dll_to_string(l);

    printf("%s\n", str);

    free(str);
}
