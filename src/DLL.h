#ifndef DLL_H
#define DLL_H

struct DLL 
{
    __uint32_t n;
    struct DLL *next;
    struct DLL *prec;
};

void append_DLL(struct DLL **pl, __uint32_t n);
void free_DLL(struct DLL **pl);
void del_elem_DLL(struct DLL **pl, struct DLL *e);

/** 
 * return a string representing the list.
 * Need to be feed!
 */
char *dll_to_string(struct DLL *l);

void print_list(struct DLL *l);

#endif
