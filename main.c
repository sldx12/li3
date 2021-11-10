#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoesAux.c"
#include "types.h"
#include "trees.c"
#include "exercicio1.c"
#include "exercicio2.c"

//Função principal do programa 
int main() {
	FILE *us = fopen("users.csv", "r");
	FILE *usOK = fopen("users-ok.csv", "w");
	FILE *repos=fopen("repos.csv", "r");
	FILE *reposOK=fopen("repos-ok.csv", "w");
    FILE *commits=fopen("commits.csv", "r");
	FILE *commitsOK=fopen("commits-ok.csv", "w");
   
	int max_len = 400000;
	char buff[max_len];
    
	if (us == NULL) return 1;
	fgets(buff, max_len, us);
	fprintf(usOK,"%s", buff);
	if (repos==NULL) return 1;
	fgets(buff,max_len,repos);
	fprintf(reposOK,"%s", buff);
	if (commits==NULL) return 1;
	fgets(buff,max_len,commits);
	fprintf(commitsOK,"%s",buff);
	final_repos(repos,reposOK);
	final_users(us, usOK);
	final_commits(commits,commitsOK);

	fclose(us);
	fclose(usOK);
	fclose(repos);
	fclose(reposOK);
	fclose(commits);
	fclose(commitsOK);
	
	FILE *usok1=fopen("users-ok.csv","r");
	FILE *usf=fopen("users-final.csv","w");
	FILE *reposok1=fopen("repos-ok.csv","r");
	FILE *reposf=fopen("repos-final.csv","w");
	FILE *commitsok1=fopen("commits-ok.csv","r");
	FILE *commitsf=fopen("commits-final.csv","w");
	if (usok1==NULL) return 1;
	fgets(buff, max_len, usok1);
	fprintf(usf,"%s", buff);
	if (reposok1==NULL) return 1;
	fgets(buff, max_len, reposok1);
	fprintf(reposf,"%s",buff);
	if (commitsok1==NULL) return 1;
	fgets(buff, max_len, commitsok1);
	fprintf(commitsf,"%s", buff); 

	ABin ABinU=NULL; // arvore binaria que nos dá os ids de todos os users
	ABin ABinR=NULL; // arvore binaria que nos dá os ids de todos os repos
	ABin ABinC=NULL;
	/*
	int arrayR_size=10;
	REPOS *arrayR=malloc(sizeof(REPOS)*arrayR_size);
	int i=0;
	while(fgets(buff,max_len,reposok1)){
		if (i==arrayR_size) {
			arrayR_size*=2;
			arrayR=realloc(arrayR,sizeof(REPOS)*arrayR_size);
		}
		arrayR[i].id=giveReposID(buff);
		insert(&ABinR,arrayR[i].id);
		arrayR[i].owner_id=giveOwnerID(buff);
		arrayR[i++].valido=0;
	}
	*/
	ids(usok1,&ABinU);
	rps(reposok1,&ABinR);
	cmt(commitsok1,&ABinC);
	fclose(reposOK);
	fopen("repos-ok.csv", "r");
    exAeB(commitsok1,commitsf,&ABinR,&ABinU);
	exCeD(reposok1,reposf,&ABinU,&ABinC);
	return 0;
}
