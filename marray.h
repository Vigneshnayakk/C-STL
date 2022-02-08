#ifndef MYLIB199811232
#define MYLIB199811232
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mutility.h"

//DYNAMIC ARRAY MACROS
//#define dinsertc(a,v) d_charinsert(&a,v)
#define dinsert(a,v) d_intinsert(&a,v)
//#define darrayc(a,...) d_chararray a = d_charinit((5,##__VA_ARGS__))
#define darray(a,...) d_intarray a = d_intinit((5,##__VA_ARGS__))

// PQ MACROS
#define ford(n,j) for(int i=n-1; i>=j; i--)
#define fori(j,n) for(int i=j; i<n; i++)
#define max(a) (a.p[0])
#define prt(...) printf(__VA_ARGS__)
#define size(a) (a.count)
#define DESC -1
#define pqueue(a,...) d_intarray a = pq_intinit((1,##__VA_ARGS__))
#define pqinsert(a,v) p_intinsert(&a,v)

//PQ GLOBAL 
int __heap_order__ = 1;

//DYNAMIC ARRAY TYPEDEF
typedef void (*heaptype)(int *,int,int);
/* typedef struct{
    char *p;
    int count;
    int size;
    char *type;
} d_chararray; */

typedef struct{
    int *p;
    int count;
    int size;
    char *type;
} d_intarray;

//PQ TYPEDEF
typedef void (*heaptype)(int *,int,int);

//DYNAMIC ARRAY FUNCTIONS
/* d_chararray d_charinit(int s){
    d_chararray new;
    new.count = 0;
    new.size = s;
    new.type = "char";
    new.p = (char*) malloc(s * sizeof(char));
    memcpy(new.p,"x",s * sizeof(char));
    return new;
}  */

d_intarray d_intinit(int s){
    d_intarray new;
    new.count = 0;
    new.size = s;
    new.type = "int";
    new.p = (int*) malloc(s * sizeof(int));
    memset(new.p,0,s * sizeof(int));
    return new;
} 

/* void d_charinsert(d_chararray *t,char v){
    if(t->count < t->size){
        t->p[t->count] = v;
        t->count++;
    }else{
       char * z = (char *) malloc(2 * t->size  * sizeof(char));
       memmove(z,t->p,t->size * sizeof(char));
       t->p = z;
       t->size = 2 * t->size;
       t->p[t->count] = v;
       t->count++;
    } 

} */

void d_intinsert(d_intarray *t,int v){
    if(t->count < t->size){
        t->p[t->count] = v;
        t->count++;
    }else{
       int * z = (int *) malloc(2 * t->size  * sizeof(int));
       memcpy(z,t->p,t->size * sizeof(int));
       t->p = z;
       t->size = 2 * t->size;
       t->p[t->count] = v;
       t->count++;
    } 

}

/* void d_select_insert(d_chararray *temp, char value){
    if(!strcmp(temp->type,"char")){
        d_charinsert(temp,value);
    }
        
} */


//PQ FUNCTIONS
void heapifymax(int *a, int i, int n){
    int maximum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] < a[maximum])
        maximum = left;
    if(right < n && a[right] < a[maximum])
        maximum = right;
    if(maximum != i){
        swap(a[i],a[maximum]);
        heapifymax(a,maximum,n);
    }
}

void heapifymin(int *a, int i, int n){
    int minimum = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && a[left] > a[minimum])
        minimum = left;
    if(right < n && a[right] > a[minimum])
        minimum = right;
    if(minimum != i){
        swap(a[i],a[minimum]);
        heapifymin(a,minimum,n);
    }
}

void priorityQueue(int *a, int n){
    heaptype type;
    if (__heap_order__ == 1) type = &heapifymin;
    else type = &heapifymax;

    ford(n/2,0){
        type(a,i,n);
    }
    ford(n,1){
        swap(a[0],a[i]);
        type(a,0,i);
    }
}

void p_intinsert(d_intarray *t,int v){
    if(t->count < t->size){
        t->p[t->count] = v;  
    }else{
       int * z = (int *) malloc(2 * t->size  * sizeof(int));
       memmove(z,t->p,t->size * sizeof(int));
       t->p = z;
       t->size = 2 * t->size;
       t->p[t->count] = v;
    }
    int i = (t->count);
    priorityQueue(t->p,i+1);
    t->count++;
}

d_intarray pq_intinit(int val){
    darray(a);
    if(val == -1)
        __heap_order__ = -1;
    else
        __heap_order__ = 1;
    return a;
}

void printit(int *a, int n){
    fori(0,n)
        printf("%d ",a[i]);
    putchar('\n');
}

#endif