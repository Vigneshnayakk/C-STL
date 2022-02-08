//testing set
#ifndef MYLIB199811235
#define MYLIB199811235
#include<stdio.h>
#include"marray.h"
#define stack(a) darray(a)
#define push(a,v) dinsert(a,v)
#define pop(a) pop_val(&a)
#define top(a) top_val(&a)

int top_val(d_intarray *t){
    if((t->count) == 0)
        return -1;
    else{
        return t->p[t->count-1];
    }
}
void pop_val(d_intarray *t){
    if(t->count > 0){
        t->count-=1;
        t->p[t->count] = 0;
    }
}

#endif