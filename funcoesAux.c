#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "funcoesAux.h"
//FUNÇÕES AUXILIARES DO EXERCÍCIO 1 GUIÃO 1
// função que confirma se uma dada string contém apenas um número válido
int nonNegativeInt(char v[]){
    int i = 0, result = 0;
    //printf("-%s-\n",v);
    while(i < strlen(v)){
        if (isdigit(v[i]) == 0) return result;
        i++;
    }
    result = 1;
    return result;
}
// função que analisa se uma string é igual a outra 
int mystrcompare(char v[],char t[]) {
    int i = 0;
    int r = 0;
    if (strlen(v) != strlen(t)) return 0;
	else {
    	while(v[i] != '\0' && t[i] != '\0') {
            if (v[i] == t[i]) {
                r = 1;
                i++;
            }
            else return 0;
       	}
    }
    return r;
}
// Função que vê se o type está correto (Só pode ser Bot,Organization,User)
int type_correct(char v[]){
    int resultado=0;
    if (mystrcompare("Bot",v)==1||mystrcompare("Organization",v)==1||mystrcompare("User",v)==1) resultado=1;
    else return 0;
    return resultado;
}
// função que vê se o has_wiki está correto (Só pode ser True,False)
int bool_correct(char v[]) {
    int resultado = 0;
    if (mystrcompare("True",v) == 1 || mystrcompare("False",v) == 1) resultado = 1;
    else return 0;
    return resultado;
}

// função que confirma se uma data é válida
int check_date(char *d) { // 07-04-2005 <= d <= current_time
    time_t rawtime;

    struct tm tm;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    memset(&tm, 0, sizeof(tm));
    strptime(d,"%Y-%m-%d %H:%M:%S", &tm);
    int year = tm.tm_year + 1900;
    int mon = tm.tm_mon + 1;
    int day = tm.tm_mday;
    int hour = tm.tm_hour;
    int min = tm.tm_min;
    int sec= tm.tm_sec;
    int c_year = timeinfo->tm_year + 1900;
    int c_mon = timeinfo->tm_mon + 1;
    int c_day = timeinfo->tm_mday;
    int c_hour = timeinfo->tm_hour;
    int c_min = timeinfo->tm_min;
    int c_sec = timeinfo->tm_sec;
    
    if (year > 2005 && year < c_year && mon <= 12 && ((mon == 1 && day>0 && day < 32) || (mon == 2 && day>0 && day < 29) || (mon == 3 && day>0 && day < 32) || (mon == 4 && day>0 && day < 31) || (mon == 5 && day>0 && day < 32) || (mon == 6 && day>0 && day < 31) || (mon == 7 && day>0 && day < 32) || (mon == 8 && day>0 && day < 32) || (mon == 9 && day>0 && day < 31) || (mon == 10 && day>0 && day < 32) || (mon == 11 && day>0 && day < 31) || (mon == 12 && day>0 && day < 32))&& hour>=0 && hour < 24 && min>=0 && min < 60 && sec>=0 && sec <60)  return 1;
    if (year == 2005 && mon <= 12 && ((mon == 4 && day>=7 && day < 31) || (mon == 5 && day>0 && day < 32) || (mon == 6 && day>0 && day < 31) || (mon == 7 && day>0 && day < 32) || (mon == 8 && day>0 && day < 32) || (mon == 9 && day>0 && day < 31) || (mon == 10 && day>0 && day < 32) || (mon == 11  && day>0 && day < 31) || (mon == 12  && day>0 && day < 32)) && hour >=0 && hour < 24 && min>=0 && min < 60 && sec>=0 && sec < 60) return 1;
    if (year == c_year && mon < c_mon && (mon == 1 && day>0 && day < 32) && (mon == 2 && day>0 && day < 29) && (mon == 3 && day>0 && day < 32) && (mon == 4 && day>0 && day < 31) && (mon == 5 && day>0 && day < 32) && (mon == 6 && day>0 && day < 31) && (mon == 7 && day>0 && day < 32) && (mon == 8 && day>0 && day < 32) && (mon == 9 && day>0 && day < 31) && (mon == 10 && day>0 && day < 32) && (mon == 11 && day>0 && day < 31) && (mon == 12 && day>0 && day < 32) && hour>=0 && hour < 24 && min >=0 && min < 60 && sec>=0 && sec < 60) return 1;
    if (year == c_year && mon == c_mon && day < c_day && hour >=0 && hour < 24 && min >=0 && min < 60  && sec>=0 && sec < 60) return 1;
    if (year == c_year && mon == c_mon && day == c_day && hour < c_hour && min >=0 && min < 60  && sec>=0 && sec< 60) return 1;
    if (year == c_year && mon == c_mon && day == c_day && hour == c_hour && min < c_min  && sec>=0 && sec< 60) return 1;
    if (year == c_year && mon == c_mon && day == c_day && hour == c_hour && min < c_min  && sec<c_sec) return 1;
    return 0;
}
//Função que vê se uma string é valida
int string_valida(char v[]){
    if (v[0]=='\0') return 0;
    else return 1;
}

//Função que testa se uma lista é valida.Caso seja dá o seu comprimento, caso não seja dá -1 (inacaba)
int lista_valida(char v[]){
    v=v+1;// Para retirar o '[';
    int c=0; // Para calcular o comprimento
    char *temp;
    char *temp1;
    temp=strdup(v);
    temp1=temp;
    if (v[0]==']') return 0;
    else{
      while ((temp1=strsep(&temp,","))!=NULL){
        //printf("%s\n",temp1);
        //printf("%d\n",atoi(temp1));
          if (atoi(temp1)>0) {
            c++;
          }
          else return -1;
      }
    }
    return c;
}
