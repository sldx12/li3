#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "giveIDs.h"
#include "trees.h"
#include "parsing.h"
struct node{
    int val;
    struct node *left;
    struct node *right;
};

// rotate binary search tree to the Left
void rotateLeft(ABin *a){
	ABin b = (*a)->right;
	(*a)->right = b->left;
	b->left = *a;
	*a = b;
}


// rotate binary search tree to the Right
void rotateRight(ABin *a){
	ABin b = (*a)->left;
	(*a)->left = b->right;
	b->right = *a;
	*a = b;
}

// gives the max of 2 ints
int max(int a, int b){
    return (a > b)? a : b;
}
// gives height of the binary search tree
int height(ABin a){
    if(a == NULL) return 0;
    return 1 + max(height(a->left), height(a->right));
}

// insert a new element in a binary search tree
void insert(ABin *a, int x){
    if(!(*a)){
        ABin new = malloc(sizeof(struct node));
        new->val = x;
        new->left = NULL;
        new->right = NULL;
        (*a)=new;
    }
    else if((*a)->val>x){
        insert (&((*a)->left),x);
        rotateRight(a);
    }
    else{
        insert (&((*a)->right),x);
        rotateLeft(a);
    }  
}
//Search for a number in a binary search tree 
ABin procurabst(ABin a, int x){
    while (a != NULL){
        if (a->val == x) return a;
        if (a->val > x) a = a->left;
        else a = a->right;
    }
    return NULL;
}

int verificaNodo(ABin a){
	if (a==NULL) return 0;
	else return 1;
}
void ids (FILE *usok1, ABin *a) {
    char buff[200000];
    while (fgets(buff, 200000, usok1)) {
        insert(a, giveID(buff)); 
    }
}
void rps(FILE *reposok1,ABin *r){
    char buff[200000];
    while (fgets(buff, 200000, reposok1)) {
        insert(r, giveReposID(buff)); 
    }
}
void cmt(FILE *commitsok1,ABin *c){
    char buff[200000];
    while (fgets(buff,200000,commitsok1)){
        insert(c,giveReposID(buff));
    }
}

