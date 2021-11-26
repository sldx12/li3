#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "parsing.h"
#include "treesV2.h"
struct bstU{
    USERS u;
    struct bstU *left;
    struct bstU *right;
};

struct bstR{
    REPOS r;
    struct bstR *left;
    struct bstR *right;
};

struct bstC{
    COMMITS c;
    struct bstC *left;
    struct bstC *right;
};

void rotateRightU(BSTU *u){
	BSTU b = (*u)->left;
	(*u)->left = b->right;
	b->right = *u;
	*u = b;
}
void rotateRightR(BSTR *r){
	BSTR b = (*r)->left;
	(*r)->left = b->right;
	b->right = *r;
	*r = b;
}
void rotateRightC(BSTC *c){
	BSTC b = (*c)->left;
	(*c)->left = b->right;
	b->right = *c;
	*c = b;
}
void rotateLeftU(BSTU *u){
    BSTU b = (*u)->right;
    (*u)->right = b->left;
    b->left = *u;
    *u=b;
}
void rotateLeftR(BSTR *r){
    BSTR b = (*r)->right;
    (*r)->right = b->left;
    b->left = *r;
    *r=b;
}
void rotateLeftC(BSTC *c){
    BSTC b = (*c)->right;
    (*c)->right = b->left;
    b->left = *c;
    *c=b;
}
void insertUSERS(BSTU *users,USERS us){
   if(!(*users)){
       BSTU new=malloc(sizeof(struct bstU));
       new->u=us;
       new->left=NULL;
       new->right=NULL;
       (*users)=new;
   }
   else if ((*users)->u->id>us->id){// A arvore vai estar ordenada consoante o valor do id do user(primeiro parametro da struct users)
       insertUSERS(&((*users)->left),us);
       rotateRightU(users);
   }
   else{
       insertUSERS(&((*users)->right),us);
       rotateLeftU(users);
   }
}

void insertREPOS(BSTR *repos,REPOS rp){
   if(!(*repos)){
       BSTR new=malloc(sizeof(struct bstR));
       new->r=rp;
       new->left=NULL;
       new->right=NULL;
       (*repos)=new;
   }
   else if ((*repos)->r->id>rp->id){// A arvore vai estar ordenada consoante o valor do id do repositório(primeiro parametro da struct repos)
       insertREPOS(&((*repos)->left),rp);
       rotateRightR(repos);
   }
   else{
       insertREPOS(&((*repos)->right),rp);
       rotateLeftR(repos);
   }
}
void insertCOMMITS(BSTC *commits,COMMITS cmt){
       if(!(*commits)){
       BSTC new=malloc(sizeof(struct bstC));
       new->c=cmt;
       new->left=NULL;
       new->right=NULL;
       (*commits)=new;
   }
   else if ((*commits)->c->repo_id>cmt->repo_id){// A arvore vai estar ordenada consoante o valor do repo_id(primeiro parametro da struct commits)
       insertCOMMITS(&((*commits)->left),cmt);
       rotateRightC(commits);
   }
   else{
       insertCOMMITS(&((*commits)->right),cmt);
       rotateLeftC(commits);
   }
}
int heightU(BSTU u){
    if(u == NULL) return 0;
    return 1 + max(heightU(u->left), heightU(u->right));
}

int heightR(BSTR r){
    if(r == NULL) return 0;
    return 1 + max(heightR(r->left), heightR(r->right));
}
int heightC(BSTC c){
    if(c == NULL) return 0;
    return 1 + max(heightC(c->left), heightC(c->right));
}
/*
Falta uma função de travessia da árvore,pode ser inorder,posorder,preorder.Tem de ser da seguinte forma 
void inorderUsers(por exemplo)(BSTU *u,int p,int *rI,char *rC)
O int p é o prametro que queremos aceder da struct users, se p==1 então queremos aceder ao id 
                                                          se p==2 então queremos aceder ao login
O pointer para int e pointer para char é para podermos dar return de duas coisas com tipos diferentes 
Repetir esta função para as 2 árvores restantes, alterando o necessário 
*/