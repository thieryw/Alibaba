#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DLL.h"


static void launch_tests();

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        struct DLL *l_of_thieves = NULL;
        for(int i = 1 ; i <= 41 ; i++)
        {
            append_DLL(&l_of_thieves,i);
        }
        print_list(l_of_thieves);


        
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
