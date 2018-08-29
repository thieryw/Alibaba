#ifndef FUNCTION_H
#define FUNCTION_H


#include "struct.h"

void append_list(struct DLL *l, int n);
int get_length(struct DLL *l);
void remove_elem(struct DLL **l,int n,int length);
void print_list(struct DLL *l);

#endif
