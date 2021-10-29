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

/*
void print_user(GH_USER u) {
	printf("id: %s | id: %s\n", u->id, u->public_repos);
}
*/
/*
int parser(char* buff) {
	char *data;
	char line[1024];
	strcpy(line, data);
	/*while ((data = strsep(&buff, ";")) != NULL){
		 printf("%s ", data);
    }
	printf("\n");
	for (int n = 0; n < 3; n++) {
		data = strsep(&buff, ";");
		if (nonNegativeInt(data) == 0) return 0;
	}
	
		

	return 0;
}
*/
//Função final que recebe um documento,neste caso um users.c e devolve um ficheiro com as dados todos formatados por
void final_users(FILE *c){
    int colunas=1;
    int Bool=1;
    int max_len = 1024;
	char buff[max_len];
    while (fgets(buff,1024,c)!=NULL){
        char *buff1;
		buff1=strdup(buff);
		//Testa se cada linha da tabela é válida
		if(nonNegativeInt(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
		if(string_valida(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
		if(type_correct(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
		if(check_date(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
		if (atoi(strsep(&buff1,";"))==lista_valida(strsep(&buff1,";"))) colunas=colunas+2;
		else Bool=0;
		if (atoi(strsep(&buff1,";"))==lista_valida(strsep(&buff1,";"))) colunas=colunas+2;
		else Bool=0;
        if(nonNegativeInt(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
		if(nonNegativeInt(strsep(&buff1,";"))==1) colunas++;
		else Bool=0;
        //Testa se vai ou não copiar a linha para o ficheiro users-ok.csv"
		if (Bool==1 && colunas==10) {
			fprintf("users-ok.csv",&buff);
		}
		Bool=1;
		colunas=1;
	} 
}

int main(int argc, char const *argv[]) {
	FILE *us = fopen("users.csv", "r");
	//FILE *c = fopen("commits.csv", "r");
	//FILE *r = fopen("repos.csv", "r");
    FILE *usOK= fopen("users-ok.csv","w");
	int max_len = 1024;
	char buff[max_len];
	//char *buff2;
	// GH_USER array[101];
	//int n = 0;	

	if (us == NULL) return 1; // check if file is empty
	
	fgets(buff, 1024, us); // remove first line
	fprintf(usOK,buff);
    /*
	while (fgets(buff,1024, us) != NULL) {
		// array[n++] = build_user[buff];
		parser(buff);	
	}
	*/
    //
	/*for (int j = 0; j < n; j++) {
		print_user(array[j]);
	}*/
	final_users(us);
	fclose(us);
	//fclose(c);
	//fclose(r);
	return 0;
}

