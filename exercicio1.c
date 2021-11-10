#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "types.h"

void final_repos(FILE *s,FILE *d){
    int Bool =1, max_len = 400000;
    char buff[max_len];
    while (fgets(buff, max_len, s)){
        char *buff1, *buff2;
        buff1=strdup(buff);
        buff2=(strsep(&buff1,";"));

        if(nonNegativeInt(buff2)==1); else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(string_valida(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(string_valida(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(bool_correct(strdup(strsep(&buff1,";")))==1); else Bool=0;

        strsep(&buff1,";");

        if(string_valida(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(string_valida(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(check_date(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(check_date(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1); else Bool=0;

        char *c;
        c=strdup(buff1);
        char *aux = strdup(strsep(&buff1,";\r\n"));
        int x3=nonNegativeInt(aux);
        if(x3==1); else Bool=0;
        if(Bool==1) fprintf(d,"%s",buff);
        Bool=1;
    }
}

void final_commits(FILE *s, FILE *d) {
    int colunas=1, Bool=1, max_len=400000, i=0;
    char buff[max_len];
    while (fgets(buff, max_len, s) != NULL){
        char *buff1;
        char *buff2;
        char *temp;
        buff1=strdup(buff);
        buff2=(strsep(&buff1,";"));
        if(nonNegativeInt(buff2)==1);
        else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1);
        else Bool=0;
        if(nonNegativeInt(strdup(strsep(&buff1,";")))==1);
        else Bool=0;
        if(check_date(strdup(strsep(&buff1,";")))==1);
        else Bool=0;
        temp=(strdup(strsep(&buff1,"\n")));

        if (Bool==1) {
            fprintf(d,"%s",buff);
        }
        colunas=1;
        Bool=1;
        
    }
}

void final_users(FILE *s, FILE *d) {
    int Bool =1,i=0,max_len=400000;
    char buff[max_len];
    while (fgets(buff, max_len, s) != NULL){
        char *buff1, *buff2;
        buff1=strdup(buff);
        buff2=(strsep(&buff1,";"));
        if(nonNegativeInt(buff2)==1); else Bool=0;
        if(string_valida(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(type_correct(strdup(strsep(&buff1,";")))==1); else Bool=0;
        if(check_date(strdup(strsep(&buff1,";")))==1); else Bool=0;
        int x=atoi(strdup(strsep(&buff1,";")));
        if (x==lista_valida(strdup(strsep(&buff1,";")))); else Bool=0;
        int x1=atoi(strdup(strsep(&buff1,";")));
        if (x1==lista_valida(strdup(strsep(&buff1,";")))); else Bool=0;
        
        char *aux = strdup(strsep(&buff1,";\n\r"));
        if(nonNegativeInt(aux)==1); else Bool=0;

        if (Bool==1) fprintf(d,"%s",buff);
        Bool=1;
    }
}