#ifndef TREES_H_
#define TREES_H_
void rotateLeft(ABin *a);
void rotateRight(ABin *a);
int max(int a, int b);
int height(ABin a);
void insert(ABin *a, int x);
ABin procurabst(ABin a, int x);
int verificaNodo(ABin a);
void ids(FILE *usok1, ABin *a);
void rps(FILE *reposok1,ABin *r);
void cmt(FILE *commitsok1,ABin *c);
#endif