#ifndef QUERYID7_H_
#define QUERYID7_H_
#include "parsing.h"
typedef struct listaligResQ7 *llResQ7;
void reposInativos(aCommit aC,aRepos aR, char date[],llResQ7 lRes);
int pertenceLista(llResQ7 lRes, int x);
llResQ7 InsertQ7(llResQ7 head_ref,llResQ7 new_node);
llResQ7 newNodeQ7(int repo_id,char description[]);
#endif