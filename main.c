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
#include "treesV2.h"

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
//Parte da main responsável pelo guião 2 
	FILE *commitsf3=fopen("commits-final.csv","r");
	FILE *usf3=fopen("users-final.csv","r");
	FILE *reposf3=fopen("repos-final.csv","r");
    BSTU abinUsers=NULL;
	BSTR abinRepos=NULL;
	BSTC abinCommits=NULL;
	int nBot;
	int nUser;
    int nOrg;
	int NumeroDeRepos;
	int NumeroDeUsers;
	int NumeroDeCommits;
	int QueryID4;
	fgets(buffs,max_len,usf3);
	printf("%s\n",buffs);
	NumeroDeUsers=readUsers(usf3,abinUsers,&nBot,&nUser,&nOrg);
	NumeroDeRepos=readRepos(reposf3,abinRepos);
	NumeroDeCommits=readCommits(commitsf3,abinCommits);
	QueryID4=NumeroDeCommits/NumeroDeUsers;
	printf("%d||",nBot);
	printf("%d||",nUser);
	printf("%d\n",nOrg);
	printf("%d||",NumeroDeCommits);
	printf("%d||",NumeroDeRepos);
	printf("%d\n",NumeroDeUsers);
	printf("%d\n",QueryID4);
	//Query id 1 -> Dar fprintf no ficheiro resultado das queries dos nBot,nUser,nOrg;     FEITA
	//Query id 2 -> Dar fprintf no ficheiro resultado das queries da divisão entre total de colaborados(users que são author_id e committer_id) e o NumeroDeRepos; POR FAZER
	//Query id 3 -> Dar fprintf no ficheiro resultado das queries com número de repositórios contendo bots como colaboradores; POR FAZER
	//Query id 4 -> Dar fprintf no ficheiro resultado das queries da divisão entre NumerodeCommits e o NumerodeUsers    FEITA
	return 0;
}
