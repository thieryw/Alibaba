#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DLL.h"


static void launch_tests();

void create_and_print_list_of_thieves(struct DLL **pl_thieves)
{
    for (int i = 1; i <= 41; i++)
    {
        append_DLL(pl_thieves, i);
    }
    printf("List of participating thieves : ");
    print_list(*pl_thieves);
    printf("\n\n");
}

void eliminate_thieves(struct DLL **pl_thieves, struct DLL **pl_elim_thieves)
{
    int i = 1;
    struct DLL *e = *pl_thieves;
    while ((*pl_thieves)->next->next != *pl_thieves)
    {
        if (i % 3 == 0)
        {
            append_DLL(pl_elim_thieves, e->n);
            e = e->prec;
            del_elem_DLL(pl_thieves, e->next);
        }
        e = e->next;
        i++;
    }

}

void print_game_results(struct DLL *l_thieves, struct DLL *l_elim_thieves)
{

    printf("List of losers by order of elimination : ");
    print_list(l_elim_thieves);
    printf("\n\nList of winners : ");
    print_list(l_thieves);
}

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        struct DLL *l_thieves = NULL;
        struct DLL *l_elim_thieves = NULL;

        create_and_print_list_of_thieves(&l_thieves);
        eliminate_thieves(&l_thieves, &l_elim_thieves);
        print_game_results(l_thieves, l_elim_thieves);

        free_DLL(&l_thieves);
        free_DLL(&l_elim_thieves);
    }
    else
    {

        launch_tests();
    }

    return (0);
}

void test1()
{

    struct DLL *l = NULL;

    append_DLL(&l, 12);
    append_DLL(&l, 13);
    append_DLL(&l, 14);

    del_elem_DLL(&l, l->next);

    char *out = dll_to_string(l);

    //printf("'%s'", out);

    char expected[] = "12 14 ";

    assert(!strcmp(expected, out));

    printf("PASS\n");

    free(out);
    free_DLL(&l);
}

void test2()
{

    struct DLL *l = NULL;

    append_DLL(&l, 12);

    del_elem_DLL(&l, l->next);

    char *out = dll_to_string(l);

    //printf("'%s'", out);

    char expected[] = "List is empty!\n";

    assert(!strcmp(expected, out));

    printf("PASS\n");

    free(out);
    free_DLL(&l);
}

void test3()
{
    struct DLL *l = NULL;
    for (int i = 1; i <= 4; i++)
    {
        append_DLL(&l, i);
    }
    del_elem_DLL(&l, l->prec);
    char *out = dll_to_string(l);
    char expected[] = "1 2 3 ";
    assert(!strcmp(expected, out));
    printf("PASS\n");
    free(out);
    free_DLL(&l);
}

static void launch_tests()
{

    printf("Launching tests...\n");

    test1();
    test2();
    test3();
}
