#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "parsing.h"
#include "QueryID5.h"
#include "QueryID7.h"
struct listaligResQ7{
    int REPO_ID;
    char *DESCRIPTION;
    struct listaligResQ7 *prox;
};

llResQ7 newNodeQ7(int repo_id,char description[]){
    llResQ7 new_node = malloc(sizeof(struct listaligResQ7));
    new_node->REPO_ID = repo_id;
    new_node->DESCRIPTION = description;
    new_node->prox = NULL;
    return new_node;
}
llResQ7 InsertQ7(llResQ7 head_ref,llResQ7 new_node){
    if (head_ref==NULL){
      head_ref=new_node;
      head_ref->prox=NULL;
      return head_ref;
    }
    else {
        new_node->prox=head_ref;
        head_ref=new_node;
        return head_ref;
    }
}
int pertenceLista(llResQ7 lRes, int x){
    if (lRes==NULL) return 0;
    else{
        if(lRes->REPO_ID==x) return 1;
        else return pertenceLista(lRes->prox,x);
    }
}

void reposInativos(aCommit aC,aRepos aR, char date[],llResQ7 lRes){
    int indexC;
    for (indexC=0; indexC<celulasOcupC(aC);indexC++){
        int rps_id=getRpsID(giveCommit(aC,indexC));
        if (compare_dates(getDataCommit(giveCommit(aC,indexC)),date)==0 && pertenceLista(lRes,rps_id)==1) indexC++;
        else if (compare_dates(getDataCommit(giveCommit(aC,indexC)),date)==0 && pertenceLista(lRes,rps_id)==0){
                int ind=binarySearchR(aR,0,celulasOcupR(aR)-1,rps_id);
                llResQ7 new;
                new=newNodeQ7(rps_id,getDescR(aR,ind));
                printf("REPO_ID:%d\nDescription:%s\n",new->REPO_ID,new->DESCRIPTION);
                lRes=InsertQ7(lRes,new);
                indexC++;
        }
        else indexC++;
    }
}