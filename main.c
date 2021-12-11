#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoesAux.h"
#include "giveIDs.h"
#include "types.h"
#include "trees.h"
#include "exercicio1.h"
#include "exercicio2.h"
#include "parsing.h"
#include "QueryID3.h"
#include "QueryID5.h"
#include "QueryID6.h"
#include "QueryID7.h"
#include "QueryID8.h"
//Função principal do programa 
int main() {
	/*
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
	
	ids(usok1,&ABinU);
	rps(reposok1,&ABinR);
	cmt(commitsok1,&ABinC);

	fclose(reposOK);
	fopen("repos-ok.csv", "r");
	fclose(commitsOK);
	FILE *commitsok2=fopen("commits-ok.csv", "r");
	fclose(commitsf);	
	FILE *commitsf2=fopen("commits-final.csv","w");
	FILE *usok2=fopen("users-ok.csv","r");
	fclose(usf);
	FILE *usf2=fopen("users-final.csv","w");
	char buffs[max_len];
	while (fgets(buffs,max_len,usok2)) {
		fprintf(usf2,"%s",buffs);
	}

    exAeB(commitsok2,commitsf2,&ABinR,&ABinU);
	exCeD(reposok1,reposf,&ABinU,&ABinC);
	fclose(commitsok2);
	fclose(commitsf2);
	fclose(usok2);
	fclose(usf2);
	fclose(reposok1);
	fclose(reposf);
*/
///////////////////////////Guião Parte 2 
    FILE *readUser=fopen("users-final2.csv","r");
	FILE *readRepos=fopen("repos-final2.csv","r");
	FILE *readCommits=fopen("commits-final2.csv","r");
    //FILE *readCommands=fopen("commands.txt","r");
	int max_len=500000;
	char buff[max_len];
	if (readUser==NULL) return 1;
	fgets(buff, max_len,readUser);
	if (readRepos==NULL) return 1;
	fgets(buff, max_len, readRepos);
	if (readCommits==NULL) return 1;
	fgets(buff, max_len, readCommits);
   
	aUsers aU=malloc(getsizeofU(aU));
	aRepos aR=malloc(getsizeofR(aR));
	aCommit aC=malloc(getsizeofC(aC));
    int nBot;
	int nUser;
	int nOrg;
	float nColab;
    float NdeUs,NdeRep,NdeCom;
	float QueryId4;
	float QueryId2;
	int QueryId3;

	NdeCom=RCommit(readCommits,aC);
	quickSortC(aC,0,celulasOcupC(aC)-1);
	NdeUs=RUsers(readUser,aU,aC,&nBot,&nUser,&nOrg,&nColab);
	quickSortU(aU,0,celulasOcupU(aU)-1);
	NdeRep=RRepos(readRepos,aR);
	quickSortR(aR,0,celulasOcupR(aR)-1);
	QueryId4=NdeCom/NdeUs;
    QueryId2=nColab/NdeRep; 
	QueryId3=NdeReposComBot(aC,aU);

    //Query Estatisiticas
	printf("Numero Total de users:%.0f\nNumero Total de Repos:%.0f\nNumero Total de committs:%.0f\n\n",NdeUs,NdeRep,NdeCom);
	//Query ID 1
	printf("Query ID 1:\nBot:%d\nOrganization:%d\nUser:%d\n\n",nBot,nOrg,nUser);
	//Query ID 2
	printf("Query ID 2:\n%.2f\n\n",QueryId2);
	//Query ID 3
	printf("Query ID 3:\n%d\n\n",QueryId3);
	//Query ID 4 
	printf("Query ID 4:\n%.2f\n\n",QueryId4);

    //Queries Parametrizáveis 
	printf("Query ID 5:\n");  //Query id 5 está feita falta ver o problema dos prints 
    llRes listaResultadosQ5=NULL;
	char dateI[11]="2005-08-17";
	char dateF[11]="2018-08-19";
	int N=4;
	utilizadoresAtivos(aU,aC,dateI,dateF,listaResultadosQ5,N);
	//printListaQ5(listaResultadosQ5,N);
	printf("Query ID 6:\n");
    llResQ6 listaResultadosQ6=NULL;
    char language[3]="C#";
	CommitsDadosPorLinguagem(aU,aC,aR,listaResultadosQ6,language);
    //printListaQ6(listaResultadosQ6,N);
	printf("Query ID 7:\n");
	llResQ7 listaResultadosQ7=NULL;
	char date[11]="2021-12-23";
	reposInativos(aC,aR,date,listaResultadosQ7);
	printf("Query ID 8:\n");
	llResQ8 listaResultadosQ8=NULL;
    linguagensMaisUtilizadas(aC,aR,listaResultadosQ8);
	printfLista(listaResultadosQ8);
	freeaUsers(aU);
	freeaRepos(aR);
	freeaCommit(aC);

	return 0;
}
