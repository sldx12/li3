#ifndef TYPES_H_
#define TYPES_H_

typedef struct repos{
	int  id;
	int  owner_id;
    int  valido;
}REPOS;

 typedef struct commits{
	int repo_id;
	int author_id;
	int committer_id;
}COMMITS;
typedef struct nodeR{
    REPOS *val;
    struct nodeR *left;
    struct nodeR *right;
} *ABinR;
typedef struct node{
    int val;
    struct node *left;
    struct node *right;
} *ABin;
#endif
