#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoesAux.c"
#include "types.h"
#include "exercicio2.c"
#include "exercicio1.c"


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
	fprintf(usOK, buff);
	if (repos==NULL) return 1;
	fgets(buff,max_len,repos);
	fprintf(reposOK, buff);
	if (commits==NULL) return 1;
	fgets(buff,max_len,commits);
	fprintf(commitsOK,buff);
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
    FILE *commitsint=fopen("commits-int.csv","w");
	if (usok1==NULL) return 1;
	fgets(buff, max_len, usok1);
	fprintf(usf, buff);
	if (reposok1==NULL) return 1;
	fgets(buff, max_len, reposok1);
	fprintf(reposf, buff);
	if (commitsok1==NULL) return 1;
	fgets(buff, max_len, commitsok1);
	fprintf(commitsf, buff); 

    USER *arrayU;
	REPOS *arrayR;
	int max_len1=400000,Nu,Nr;
	arrayU=malloc(max_len1*sizeof(struct user));
	arrayR=malloc(max_len1*sizeof(struct repos));
	Nu=arrayDinamicoU(usok1,arrayU);
	exA(commitsok1,commitsint,arrayU,Nu);
	fclose(commitsint);
	FILE *commitsint2=fopen("commits-int.csv","r");
	Nr=arrayDinamicoR(reposok1,arrayR);
	exB(commitsint2,commitsf,arrayR,Nr);
	return 0;
}
