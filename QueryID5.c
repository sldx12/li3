#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "parsing.h"
#include "QueryID5.h"
struct listaligRes{
    int ID;
    char *LOGIN;
    int Ncommits;
    struct listaligRes *prox;
};

// retorna 1 sempre que a primeira data seja mais recente do que a segunda
int compare_dates(char *d1, char *d2){  
    struct tm tm1;
    struct tm tm2;

    memset(&tm1, 0, sizeof(tm1));
    strptime(d1, "%Y-%m-%d %H:%M:%S", &tm1);
    memset(&tm2, 0, sizeof(tm2));
    strptime(d2,"%Y-%m-%d %H:%M:%S", &tm2);    

    int year1 = tm1.tm_year + 1900;
    int mon1 = tm1.tm_mon + 1;
    int day1 = tm1.tm_mday;

    int year2 = tm2.tm_year + 1900;
    int mon2 = tm2.tm_mon + 1;
    int day2 = tm2.tm_mday;
    
    if (year1 > year2) return 1;
    if (year1 == year2 && mon1 > mon2) return 1;
    if (year1 == year2 && mon1 == mon2 && day1 > day2) return 1;

    else return 0;
}
llRes newNode(int id, char login[], int nC){
    llRes new_node = malloc(sizeof(struct listaligRes));
    new_node->ID = id;
    new_node->LOGIN = login;
    new_node->Ncommits = nC;
    new_node->prox = NULL;
    return new_node;
}
llRes sortedInsert(llRes head_ref,llRes new_node){
    llRes current;
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
void utilizadoresAtivos(aUsers aU,aCommit aC,char dateIN[],char dateFIM[],llRes lRes,int N){
    int indexU,indexC;
    int Ncommits;
    int countN=0;
    llRes new;
    for (indexU=0;indexU<celulasOcupU(aU);indexU++){
        indexC=0;
        Ncommits=0;
        int id=getUserID(giveUser(aU,indexU));
        while(getCommitterID(giveCommit(aC,indexC))!=id && indexC!=celulasOcupC(aC)-1){
            indexC++;
        }
        if(celulasOcupC(aC)-1==indexC);
        else{
            while(getCommitterID(giveCommit(aC,indexC))==id && compare_dates(getCommit_at(giveCommit(aC,indexC)),dateIN)==1 && compare_dates(getCommit_at(giveCommit(aC,indexC)),dateFIM)==0){
                indexC++;
                Ncommits++;
            }
            new=newNode(id,giveLogin(giveUser(aU,indexU)),Ncommits);
            lRes=sortedInsert(lRes,new);
            //printf("ID:%d\nLogin:%s\nNúmero de Commits:%d\n\n",lRes->ID,lRes->LOGIN,lRes->Ncommits);
        }
    }
}
void printListaQ5(llRes lRes,int N){
     int i=0;
    while (i!=N){
        printf("ID:%d",lRes->ID);
        printf("Login:%s\n",lRes->LOGIN);
        printf("Numero de Commits:%d\n",lRes->Ncommits);
        lRes=lRes->prox;
        i++;
    }
}