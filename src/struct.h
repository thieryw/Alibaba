#ifndef STRUCT_H
#define STRUCT_H


struct DLL 
{
    int i;
    struct DLL *next;
    struct DLL *prec;
    int index;
};

#endif