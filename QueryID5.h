#ifndef QUERYID5_H_
#define QUERYID5_H_
#include "parsing.h"
typedef struct listaligRes *llRes;
llRes sortedInsert(llRes head_ref,llRes new_node);
llRes newNode(int id, char login[], int nC);
int compare_dates(char *d1, char *d2);
void utilizadoresAtivos(aUsers aU,aCommit aC,char dateIN[],char dateFIM[],llRes lRes,int N);
void printListaQ5(llRes lRes,int N);
#endif