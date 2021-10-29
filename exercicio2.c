#include <stdio.h>
#include <string.h>
#include "types.h"
//FUNÇÕES AUXILIARES DO EXERCÍCIO 2 GUIÃO 1
/*Função que dado um user o armazena utilizando para isso uma lista
Utilzando a função build_user, que constroi uma struct com as informações do user, 
podemos criar uma lista de users para facilitar as procuras existentes no exercicio 2.
*/
LUser lista_users(GH_USER user,LUser l_Users){
     LUser nova=malloc(sizeof(struct lligada));
     nova->u=user;
     nova->prox =l_Users;
     l_Users=nova;
     
    return l_Users;
}

// necessitamos de ler o ficheiro "users-ok.csv" e criar a lista de users 
LUser build_LUser(FILE *op){
	int max_len = 1024;
	char buff[max_len];
	fgets(buff, max_len, op); // remove first line
	GH_USER novo;
	LUser u=NULL;
	LUser r;
	char *linha;
	linha=fgets(buff, max_len, op);
	while((linha)!=NULL){
        novo=build_user(linha);
        r=lista_users(novo,u);
		linha=fgets(buff, max_len, op);
	}
	return r;
}
