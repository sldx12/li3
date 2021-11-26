#ifndef TREESV2_H_
#define TREESV2_H_
typedef struct bstU *BSTU;
typedef struct bstR *BSTR;
typedef struct bstC *BSTC;
typedef struct repos *REPOS;
typedef struct users *USERS;
typedef struct commits *COMMITS;
void rotateRightU(BSTU *u);
void rotateRightR(BSTR *r);
void rotateRightC(BSTC *c);
void rotateLeftU(BSTU *u);
void rotateLeftR(BSTR *r);
void rotateLeftC(BSTC *c);
void insertUSERS(BSTU *users,USERS us);
void insertREPOS(BSTR *repos,REPOS rp);
void insertCOMMITS(BSTC *commits,COMMITS cmt);
int heightU(BSTU u);
int heightR(BSTR r);
int heightC(BSTC c);

#endif