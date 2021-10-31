#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "funcoesAux.c"
#include "types.h"
GH_USER build_user(char *line) {
	GH_USER u = malloc(sizeof(struct gh_user));
	u->public_repos = strdup(strsep(&line, ";\n"));
	u->id = strdup(strsep(&line, ";\n"));
	u->followers =strdup(strsep(&line, ";\n"));
	u->follower_list =strdup(strsep(&line, ";\n"));
	u->type=strdup(strsep(&line, ";\n"));
	u->following_list=strdup(strsep(&line, ";\n"));
	u->public_gists=strdup(strsep(&line, ";\n"));
	u->created_at=strdup(strsep(&line, ";\n"));
	u->following=strdup(strsep(&line, ";\n"));
	u->login=strdup(strsep(&line, ";\n"));
	return u;
}
//Função que engloba as funções auxiliares e formata o ficheiro users.csv

void final_users(FILE *s, FILE *d) {
	int colunas = 1;
	int max_len = 400000;
	char buff[max_len];
	while (fgets(buff, max_len, s) != NULL ){
		char *buff1;
		char *buff2;
        buff1=strdup(buff);
		buff2=(strsep(&buff1,";"));
		if(nonNegativeInt(buff2)==1) colunas++;
		else colunas=9+colunas;
		//printf("%%d\n",colunas);
		//printf("%s\n",buff2);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else colunas=9+colunas;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(type_correct(strdup(strsep(&buff1,";")))==1) colunas++;
		else colunas=9+colunas;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(check_date(strdup(strsep(&buff1,";")))==1) colunas++;
		else colunas=9+colunas;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		
		int x=atoi(strdup(strsep(&buff1,";")));
		//printf("%d\n",x);
        
		if (x==lista_valida(strdup(strsep(&buff1,";")))) colunas=colunas+2;
		else colunas=9+colunas;
		//printf("%s\n",buff1);
		//printf("%d%d\n",Bool,colunas);
		int x1=atoi(strdup(strsep(&buff1,";")));
		
		if (x1==lista_valida(strdup(strsep(&buff1,";")))) colunas=colunas+2;
		else colunas=9+colunas;
		//printf("%s\n",buff1);
		//printf("%d%d\n",Bool,colunas);
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else colunas=9+colunas;
		//printf("%s\n",buff1);
		//printf("%d\n",colunas);
		if(nonNegativeInt(strdup(strsep(&buff1,"\n")))==1) colunas++;
		//printf("%d\n",nonNegativeInt(strdup(strsep(&buff1,"\n"))));
		//printf("%d\n",colunas);
        //printf("%s\n",buff);
		if (colunas==10) {
			fprintf(d,buff);
		}
		colunas=1;
		
	}
}

void final_repos(FILE *s, FILE *d) {
	int colunas = 1;
	int Bool = 1;
	int max_len = 400000;
	char buff[max_len];
	int i=0;
	while (fgets(buff, max_len, s) != NULL){
		char *buff1;
		char *buff2;
        buff1=strdup(buff);
		buff2=(strsep(&buff1,";"));
		if(nonNegativeInt(buff2)==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff2);
		if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
        //printf("%s\n",buff1);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
        if(bool_correct(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
        if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(check_date(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(check_date(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%s\n",buff1);
		//printf("%d%d\n",Bool,colunas);
		if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
        //printf("%s\n",buff1);
		if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
        //printf("%s\n",buff1);
		if(nonNegativeInt(strdup(strsep(&buff1,"\n")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		if (colunas==15) {
			//printf("%s\n\n",buff);
			//printf("%d\n",i);
			fprintf(d,buff);
		}
		colunas=1;
		Bool=1;
	}
}

void final_commits(FILE *s, FILE *d) {
	int colunas = 1;
	int Bool = 1;
	int max_len = 400000;
	char buff[max_len];
	int i=0;
	while (fgets(buff, max_len, s) != NULL){
		char *buff1;
		char *buff2;
        buff1=strdup(buff);
		buff2=(strsep(&buff1,";"));
		if(nonNegativeInt(buff2)==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff2);
		if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
        //printf("%s\n",buff1);
		if(nonNegativeInt(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
	    //printf("%s\n",buff1);
		//printf("%d%d\n",Bool,colunas);
		if(check_date(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);
		//printf("%s\n",buff1);
		if(string_valida(strdup(strsep(&buff1,";")))==1) colunas++;
		else Bool=0;
		//printf("%d%d\n",Bool,colunas);

		if (colunas==6) {
			//printf("%s\n\n",buff);
			//printf("%d\n",i);
			fprintf(d,buff);
		}
		colunas=1;
		Bool=1;
		
	}
}
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
	final_users(us, usOK);
	final_repos(repos,reposOK);
	final_commits(commits,commitsOK);
	fclose(us);
	fclose(usOK);
	fclose(repos);
	fclose(reposOK);
	fclose(commits);
	fclose(commitsOK);
	return 0;
}
