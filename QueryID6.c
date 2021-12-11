#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "parsing.h"
#include "funcoesAux.h"
#include "QueryID6.h"
struct listaligResQ6{
    int ID;
    char *LOGIN;
    int Ncommits;
    struct listaligResQ6 *prox;
};


llResQ6 newNodeQ6(int id, char login[], int nC){
    llResQ6 new_node = malloc(sizeof(struct listaligResQ6));
    new_node->ID = id;
    new_node->LOGIN = login;
    new_node->Ncommits = nC;
    new_node->prox = NULL;
    return new_node;
}
llResQ6 sortedInsertQ6(llResQ6 head_ref,llResQ6 new_node){
    llResQ6 current;
    if (head_ref == NULL || head_ref->Ncommits < new_node->Ncommits) {
        new_node->prox = head_ref;
        head_ref = new_node;
    }
    else {
        current = head_ref;
        while(current->prox && current->prox->Ncommits > new_node->Ncommits){
            current = current->prox;
        }
        new_node->prox = current->prox;
        current->prox = new_node;
    }
    return head_ref;
}

void CommitsDadosPorLinguagem(aUsers aU,aCommit aC,aRepos aR,llResQ6 lRes,char language[]){
    int indexU,indexC;
    int Ncommits;
    llResQ6 new;
    for (indexU=0;indexU<celulasOcupU(aU);indexU++){
        indexC=0;
        Ncommits=0;
        int id=getUserID(giveUser(aU,indexU));
        while(getCommitterID(giveCommit(aC,indexC))!=id && indexC!=celulasOcupC(aC)-1){
            indexC++;
        }
        if(celulasOcupC(aC)-1==indexC);
        else{
            while(getCommitterID(giveCommit(aC,indexC))==id){
                int rpsID=getRpsID(giveCommit(aC,indexC));
                int ind=binarySearchR(aR,0,celulasOcupR(aR)-1,rpsID);
                if (strcmp(language,getLangR(aR,ind))==0){
                    Ncommits++;
                    indexC++; 
                }
                else indexC++; 
            }
            new=newNodeQ6(id,giveLogin(giveUser(aU,indexU)),Ncommits);
            printf("ID:%d\nLogin:%s\nNúmero de Commits:%d\n\n",new->ID,new->LOGIN,new->Ncommits);
            lRes=sortedInsertQ6(lRes,new);
        }
    }
}

void printListaQ6(llResQ6 lRes,int N){
     int i=0;
    while (i!=N){
        printf("ID:%d",lRes->ID);
        printf("Login:%s\n",lRes->LOGIN);
        printf("Numero de Commits:%d\n",lRes->Ncommits);
        lRes=lRes->prox;
        i++;
    }
}