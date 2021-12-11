#ifndef QUERYID8_H_
#define QUERYID8_H_
#include "parsing.h"
typedef struct listaligResQ8 *llResQ8;
void aumentaNcommits(llResQ8 lRes,char language[],int inc);
int LingPertenceLista(llResQ8 lRes,char language[]);
llResQ8 acrescentaLista(llResQ8 lRes,char language[],int inc);
void linguagensMaisUtilizadas(aCommit aC,aRepos aR,llResQ8 lRes);
void printfLista(llResQ8 lRes);
#endif