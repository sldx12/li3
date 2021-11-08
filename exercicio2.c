#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "types.h"
//construção de um user
USER build_user(char *line) {
	USER u = malloc(sizeof(struct user));
	u->id = atoi(strdup(strsep(&line, ";\n")));
	return u;
}
//Construção de um repos 
REPOS build_repos(char *line){
	REPOS r=malloc(sizeof(struct repos));
	r->id=atoi(strdup(strsep(&line, ";\n")));
	r->owner_id=atoi(strdup(strsep(&line, ";\n")));
	return r;
} 
//Construção de um commit
COMMITS build_commits(char *line){
	COMMITS c=malloc(sizeof(struct commits));
	c->repo_id=atoi(strdup(strsep(&line, ";\n")));
	c->author_id=atoi(strdup(strsep(&line, ";\n")));
    c->committer_id=atoi(strdup(strsep(&line, ";\n")));
	return c;
} 
//Alinea A e B:->arrayCM[0]->author_id e arrayCM[0]->committer_id == arrayUS[?]->id e arrayCM[0]->repos_id== arrayRE[?]->id
//arrayDinamicoU("users-ok.csv",arrayDianmico)
int arrayDinamicoU(FILE *s,USER *arrayU){
    int i=0,max_len=400000;
    char buff[max_len];
    while (fgets(buff,max_len,s)){
        arrayU[i]=build_user(&buff);
        i++;
    }
    return i;
}

int arrayDinamicoR(FILE *s,REPOS *arrayR){
    int i=0,max_len=400000;
    char buff[max_len];
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1= strdup(buff);
        if(nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
        arrayR[i]=build_repos(&buff);
        i++;
        }
    }
    return i;
}

int giveCommitterID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(&temp);
    return r;
}
int giveAuthorID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(&temp);
    return r;
}
int giveReposID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(&temp);
    return r;
}
int giveOwnerID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(&temp);
    return r;
}
int verificaIDU(USER *arrayU,int x,int N){
    int i=0;
    while (arrayU[i]->id!=x && i<N-1){
       i++;
    }
    if (arrayU[i]->id==x) return 1;
    if (i==N-1) return 0;
}
int verificaIDR(REPOS *arrayR,int x,int N){
    int i=0;
    while (arrayR[i]->id!=x && i<N-1){
        i++;
    }
    if (arrayR[i]->id==x) return 1;
    if (i==N-1) return 0;
}

void exA(FILE *s, FILE *d,USER *arrayU,int Nu){
    int max_len=400000;
    char buff[max_len];
    int CID, AID,r1,r2,i=0;
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1= strdup(buff);
        if (nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
            printf("teste\n");
            char *buffT0;
            buffT0 = strdup(buff);
            CID=giveCommitterID(buffT0);
            printf("%d\n",CID);
            char *buffT1;
            buffT1 = strdup(buff);
            AID=giveAuthorID(buffT1);
            printf("%d\n",AID);
            r1=verificaIDU(arrayU,CID,Nu);
            r2=verificaIDU(arrayU,AID,Nu);
            printf("%d-%d\n",r1,r2);
            if (r1==1 && r2==1) {
                fprintf(d,buff);
            }
        }
    }
}

void exB(FILE *s,FILE *d,REPOS *arrayR,int Nr){
    int max_len=400000;
    char buff[max_len];
    int RID,r1;
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1=strdup(buff);
        if (nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
            char *buffT0;
            buffT0=strdup(buff);
            RID=giveReposID(buffT0);
            r1=verificaIDR(arrayR,RID,Nr);
            if (r1==1){
                fprintf(d,buff);
            }
        }
    }
}
void exC (FILE *s,FILE *d,USER *arrayU,int Nu){
    int max_len=400000;
    char buff[max_len];
    int OWID,r1;
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1=strdup(buff);
        if(nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
            char *buffT0;
            buffT0=strdup(buff);
            OWID=giveOwnerID(buffT0);
            r1=verificaIDU(arrayU,Nu,OWID);
            if (r1==1){
                fprintf(d,buff);
            }
        }
    }
}
//Temos de pensar na alinea d) e numa maneira de ordenar o array para melhorar o tempo de execução que esta excessivamente grande 