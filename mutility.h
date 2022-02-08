#ifndef MYLIB199811234
#define MYLIB199811234
#include<stdio.h>

#define swap(a,b) swapValue(&a,&b,sizeof(a))
#define retmax(a,b) (a > b) ? a : b
#define printnArray(a,n,...) pArray(a,n,('\n',##__VA_ARGS__))

void pArray(int a[], int n, char delimit){
    for(int i=0; i<n; i++)
        printf("%d%c",a[i],delimit);
    (delimit != '\n')? putchar('\n') : putchar(0);
}

void swapValue(void *a, void *b, size_t len){
    unsigned char * p = a, *q = b;
    for(size_t i = 0; i < len; i++){
        p[i] ^= q[i] ^= p[i] ^= q[i];
    }
}

#endif