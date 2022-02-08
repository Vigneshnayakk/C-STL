//testing set
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

int main(){
    darray(a);
    int n;
    scanf("%d",&n);
    for(n; n>=1; n--){
        int v; 
        scanf("%d",&v);
        dinsert(a,v);
    }
    stack(b);
    int m = 0;
    push(b,a.p[0]);
    for(int i = 1; i< a.count; i++){
        m = retmax(m, a.p[i] - top(b));
        if(a.p[i] < top(b)){
            pop(b);
            push(b,a.p[i]);
        }
    }
    printf("%d ", m);
    return 0;

}