#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "parsing.h"
#include "QueryID8.h"

struct listaligResQ8{
    char *LANGUAGE;
    int NumeroDeCommits;
    struct listaligResQ8 *prox;
};
int LingPertenceLista(llResQ8 lRes,char language[]){
    if (lRes==NULL) return 0;
    else if (strcmp(lRes->LANGUAGE,language)==0) return 1;
    else  return LingPertenceLista(lRes->prox,language);
}
llResQ8 acrescentaLista(llResQ8 lRes,char language[],int inc){
    if (lRes==NULL){
        lRes=malloc(sizeof(struct listaligResQ8));
        lRes->LANGUAGE=language;
        lRes->NumeroDeCommits=inc;
        return lRes;
    }
    else {
        llResQ8 nova=malloc(sizeof(struct listaligResQ8));
        nova->LANGUAGE=language;
        nova->NumeroDeCommits=inc;
        nova->prox=lRes;
        return nova;
    }
}
void aumentaNcommits(llResQ8 lRes,char language[],int inc){
    llResQ8 aux=lRes;
    while(strcmp(aux->LANGUAGE,language)!=0){
        aux=aux->prox;
    }
    aux->NumeroDeCommits+=inc;
}
void linguagensMaisUtilizadas(aCommit aC,aRepos aR,llResQ8 lRes){
    int indexC;
    for (indexC=0;indexC<celulasOcupC(aC);indexC++){
       int rps_id=getRpsID(giveCommit(aC,indexC));
       int ind=binarySearchR(aR,0,celulasOcupR(aR)-1,rps_id);
       //printf("%d\n",LingPertenceLista(lRes,getLangR(aR,ind)));
       if (LingPertenceLista(lRes,getLangR(aR,ind))==1){
           aumentaNcommits(lRes,getLangR(aR,ind),1);
           //printf("Já pertence á lista:%s\n",getLangR(aR,ind));
       }
       else {
            lRes=acrescentaLista(lRes,getLangR(aR,ind),1);
           // printf("Está a acrescentar á lista:%s\n",getLangR(aR,ind));
       }
    }
}

void printfLista(llResQ8 lRes){
    while (lRes!=NULL){
        printf("%s\n",lRes->LANGUAGE);
        lRes=lRes->prox;
    }
}