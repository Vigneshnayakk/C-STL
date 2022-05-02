#ifndef MYLIBMYLIST
#define MYLIBMYLIST
#include<stdio.h>
#include<stdlib.h>
#define list(a) head* a = linkedlist_init()
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} linkedlist;

typedef struct headnode{
    //linkedlist* temp;
    linkedlist* h;
    linkedlist* t;
    int length;
} head;

head* linkedlist_init(){
    head* new = (head*) malloc(sizeof(head));
    new->h = NULL;
    new->t = NULL;
    new->t = NULL;
    new->length = 0;
    return new;
}
void push_back(head* a, int k){
    linkedlist* new = (linkedlist*) malloc(sizeof(linkedlist));
    new->data = k;
    new->next = NULL;
    if((a->h) == NULL){
        new->prev = NULL;
        (a->h) = new;
        (a->t) = new;
        a->length++;
    }else{ 
        linkedlist* p = (a->t);
        p->next = new;
        new->prev = p;
        a->t = new;
        a->length++;
    }
}


void pop_back(head* a){
    linkedlist* temp = a->t;
    a->t = temp->prev;
    (a->t)->next = NULL;
    a->length--;
    free(temp);
}

void pop_front(head* a){
    linkedlist* temp = a->h;
    a->h = temp->next;
    a->length--;
    free(temp);
}

void pop_value(head* a, int indx){
    if(a->length == 0 || indx > a->length)
        return;
    linkedlist* p = a->h;
    if(indx == 0){
        pop_front(a);
        return;
    }
    if(indx == a->length - 1){
        pop_back(a);
        return;
    }
    for(int i=0; i<indx; i++)
        p = p->next;
    linkedlist* temp = p->prev;
    temp->next = p->next;
    (p->next)->prev = temp;
    a->length--;
    free(p);
}

void push_front(head *a, int k){
    if((a->h) == NULL){
        push_back(a,k);
        return;
    }
    linkedlist* new = (linkedlist*) malloc(sizeof(linkedlist));
    new->data = k;
    new->next = a->h;
    new->prev = NULL;
    (a->h)->prev = new;
    a->h = new;
    a->length++;   
}
void linkedlist_insert(head* a, int indx, int k){
    if((a->h) == NULL || indx >= a->length){
        push_back(a,k);
        return;
    }
    if(indx == 0){
        push_front(a,k);
        return;
    }
    linkedlist* p = (a->h);
    linkedlist* new = (linkedlist*) malloc(sizeof(linkedlist));
    new->data = k;
    for(int i=0 ; i< indx; i++)
        p = p->next;
    linkedlist* temp = p->prev;
    p->prev = new;
    new->next = p;
    temp->next = new;
    new->prev = temp;  
}
void display(head* a){
    linkedlist* p = (a->h);
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    putchar('\n');
}


void rdisplay(head* a){
    linkedlist* p = (a->t);
    while(p != NULL){
        printf("%d ", p->data);
        p = p->prev;
    }
    putchar('\n');
}
void destructor(head* a){
    while(a->h != NULL){
        linkedlist* tmp = a->h;
        (a->h)  = (a->h)->next;
        free(tmp);
    }
    free(a);
}
#endif

