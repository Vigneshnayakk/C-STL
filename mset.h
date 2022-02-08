#ifndef MYLIB199811236
#define MYLIB199811236
#include<stdlib.h>
#include"mylib.h"
#define n 8
#define rt root
#define set(a) struct node * a
#define setinsert(a,v) a = insert(a,v); fixup(rt,a)

struct node {
    int val;
    int c;
    struct node* p;
    struct node * l;
    struct node * r;
};

struct node * root = NULL;
struct node * createNode(int k){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->val = k;
    temp->c = 1;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

struct node * insert(struct node* node,int k){
    if(root == NULL){
        root = createNode(k);
        return root;
    }else{
        if(node == NULL) {
            return createNode(k);
            }
        if(node->val < k){
            node->r = insert(node->r,k);
            node->r->p = node;
        }
        else if(node->val > k){
            node->l = insert(node->l,k);
            node->l->p = node;
        }
    }
    return node;
}


void rightrotate(struct node* temp)
{
	struct node* left = temp->l;
	temp->l = left->r;
	if (temp->l)
		temp->l->p = temp;
	left->p = temp->p;
	if (!temp->p)
		root = left;
	else if (temp == temp->p->l)
		temp->p->l = left;
	else
		temp->p->r = left;
	left->r = temp;
	temp->p = left;
}

// Function performing left rotation
// of the passed node
void leftrotate(struct node* temp)
{
	struct node* right = temp->r;
	temp->r = right->l;
	if (temp->r)
		temp->r->p = temp;
	right->p = temp->p;
	if (!temp->p)
		root = right;
	else if (temp == temp->p->l)
		temp->p->l = right;
	else
		temp->p->r = right;
	right->l = temp;
	temp->p = right;
}


void fixup(struct node* root,struct node* pt)
{
	struct node* parent_pt = NULL;
	struct node* grand_parent_pt = NULL;

	while ((pt != root) && (pt->c != 0)
		&& (pt->p->c == 1))
	{
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;

	
		if (parent_pt == grand_parent_pt->l)
		{

			struct node* uncle_pt = grand_parent_pt->r;

			
			if (uncle_pt != NULL && uncle_pt->c == 1)
			{
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}

			else {

				
				if (pt == parent_pt->r) {
					leftrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}

				
				rightrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}

	
		else {
			struct node* uncle_pt = grand_parent_pt->l;

			
			if ((uncle_pt != NULL) && (uncle_pt->c == 1))
			{
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}
			else {
				
				if (pt == parent_pt->l) {
					rightrotate(parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}

				
				leftrotate(grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
	}

	root->c = 0;
}
#endif