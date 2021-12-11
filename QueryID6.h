#ifndef QUERYID6_H_
#define QUERYID6_H_
#include "parsing.h"
typedef struct listaligResQ6 *llResQ6;
llResQ6 newNodeQ6(int id, char login[], int nC);
llResQ6 sortedInsertQ6(llResQ6 head_ref,llResQ6 new_node);
void CommitsDadosPorLinguagem(aUsers aU,aCommit aC,aRepos aR,llResQ6 lRes,char language[]);
void printListaQ6(llResQ6 lRes,int N);
#endif