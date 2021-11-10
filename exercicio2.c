#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "types.h"

//Função final dos commits
void exAeB(FILE *s,FILE *d,ABin *r,ABin *u){
	int max_len=2000,AuthorID,CommitterID,RepoID,rAID,rCID,rRID;
	char buff[max_len];
	while (fgets(buff,max_len,s)){
         char *buff1;
		 buff1=strdup(buff);
		 RepoID=giveReposID(buff1);
		 char *buff2;
		 buff2=strdup(buff);
		 AuthorID=giveAuthorID(buff2);
		 char *buff3;
		 buff3=strdup(buff);
		 CommitterID=giveCommitterID(buff3);
		 rCID=verificaNodo(procurabst(*u,CommitterID));
		 rAID=verificaNodo(procurabst(*u,AuthorID));
		 rRID=verificaNodo(procurabst(*r,RepoID)); 
        if (rCID==1 && rAID==1 && rRID==1){
			fprintf(d,"%s",buff);
		}
	}
}
void exCeD(FILE *s,FILE *d,ABin *u,ABin *c){
	int max_len=200000,ownerID,repoID,rOID,rRID;
	char buff[max_len];
    fgets(buff,max_len,s);
	while (fgets(buff,max_len,s)){
         char *buff1;
		 buff1=strdup(buff);
		 repoID=giveReposID(buff1);

         char *buff2;
		 buff2=strdup(buff);
		 ownerID=giveOwnerID(buff1);
         
		 rOID=verificaNodo(procurabst(*u,ownerID));
         rRID=verificaNodo(procurabst(*c,repoID));
        if (rOID==1 && rRID==1){
			fprintf(d,"%s",buff);
		}
	}
}