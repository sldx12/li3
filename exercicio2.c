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
    while (fgets(buff,max_len,s)!= NULL){
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

int arrayDinamicoC(FILE *s,COMMITS *arrayC){
    int i=0,max_len=400000;
    char buff[max_len];
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1= strdup(buff);
        if(nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
        arrayC[i]=build_commits(&buff);
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
int procuraBinariaU(USER *arrayU,int iI,int iF,int x){
    int r=0;
    int meio;
    while (iI<=iF){
        meio=(iI+iF)/2;
        if(arrayU[meio]->id==x) return 1;
        else if (iI==iF) return 0;
        else if (arrayU[meio]->id<x) iI=meio+1;
        else iF=meio;
    }
    return r;
}
int procuraBinariaR(REPOS *arrayR,int iI,int iF,int x){
    int r=0;
    int meio;
    while (iI<=iF){
        meio=(iI+iF)/2;
        if(arrayR[meio]->id==x) return 1;
        else if (iI==iF) return 0;
        else if (arrayR[meio]->id<x) iI=meio+1;
        else iF=meio;
    }
    return r;
}
int procuraBinariaC(COMMITS *arrayC,int iI,int iF,int x){
    int r=0;
    int meio;
    while (iI<=iF){
        meio=(iI+iF)/2;
        if(arrayC[meio]->repo_id==x) return 1;
        else if (iI==iF) return 0;
        else if (arrayC[meio]->repo_id<x) iI=meio+1;
        else iF=meio;
    }
    return r;
}
void quicksortR(REPOS *arrayR, int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while ((arrayR[i]->id) <= (arrayR[pivot]->id) && i < last) i++;
            while ((arrayR[j]->id) > (arrayR[pivot]->id)) j--;

        if (i < j) {
            temp = arrayR[i]->id;
            arrayR[i]->id = arrayR[j]->id;
            arrayR[j]->id = temp;
            }    
        }

    temp = arrayR[pivot]->id;
    arrayR[pivot]->id = arrayR[j]->id;
    arrayR[j]->id = temp;
    quicksortR(arrayR, first, j-1);
    quicksortR(arrayR, j+1, last);
    
    }
}
void quicksortU(USER *arrayU, int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while ((arrayU[i]->id) <= (arrayU[pivot]->id) && i < last) i++;
            while ((arrayU[j]->id) > (arrayU[pivot]->id)) j--;

        if (i < j) {
            temp = arrayU[i]->id;
            arrayU[i]->id = arrayU[j]->id;
            arrayU[j]->id = temp;
            }    
        }

    temp = arrayU[pivot]->id;
    arrayU[pivot]->id = arrayU[j]->id;
    arrayU[j]->id = temp;
    quicksortU(arrayU, first, j-1);
    quicksortU(arrayU, j+1, last);
    
    }
}
void quicksortC(COMMITS *arrayC, int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while ((arrayC[i]->repo_id) <= (arrayC[pivot]->repo_id) && i < last) i++;
            while ((arrayC[j]->repo_id) > (arrayC[pivot]->repo_id)) j--;

        if (i < j) {
            temp = arrayC[i]->repo_id;
            arrayC[i]->repo_id = arrayC[j]->repo_id;
            arrayC[j]->repo_id = temp;
            }    
        }

    temp = arrayC[pivot]->repo_id;
    arrayC[pivot]->repo_id = arrayC[j]->repo_id;
    arrayC[j]->repo_id = temp;
    quicksortC(arrayC, first, j-1);
    quicksortC(arrayC, j+1, last);
    
    }
}
/*
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
            r1=procuraBinariaU(arrayU,0,Nu-1,CID);
            r2=procuraBinariaU(arrayU,0,Nu-1,AID);
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
            r1=procuraBinariaR(arrayR,0,Nr-1,RID);
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
            r1=procuraBinariaU(arrayU,0,Nu-1,OWID);
            if (r1==1){
                fprintf(d,buff);
            }
        }
    }
}
*/
void exAeB(FILE *s, FILE *d,REPOS*arrayR,USER *arrayU,int Nu,int Nr){
    int max_len=400000;
    char buff[max_len];
    int CID, AID,RID,r1,r2,i=0,r3;
    while (fgets(buff,max_len,s) && i!=2){
        printf("%s\n",buff);
        char *buff1;
        buff1= strdup(buff);
        if (nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
            char *buffT0;
            buffT0 = strdup(buff);
            CID=giveCommitterID(buffT0);
            printf("%d\n",CID);
            char *buffT1;
            buffT1 = strdup(buff);
            AID=giveAuthorID(buffT1);
            printf("%d\n",AID);
            char *buffT2;
            buffT2 = strdup(buff);
            RID=giveReposID(buffT2);
            printf("%d\n",RID);
            r1=procuraBinariaU(arrayU,0,Nu-1,CID);
            r2=procuraBinariaU(arrayU,0,Nu-1,AID);
            r3=procuraBinariaR(arrayR,0,Nr-1,RID);
            printf("%d-%d-%d\n",r1,r2,r3);
            if (r1==1 && r2==1 && r3==1) {
                fprintf(d,buff);
            }
        }
        i++;
    }
}
void exCeD (FILE *s,FILE *d,USER *arrayU,COMMITS *arrayC,int Nu,int Nc){
    int max_len=400000;
    char buff[max_len];
    int OWID,RID,r1,r2;
    while (fgets(buff,max_len,s)){
        char *buff1;
        buff1=strdup(buff);
        if(nonNegativeInt(strdup(strsep(&buff1,";\n")))==1){
            char *buffT0;
            buffT0=strdup(buff);
            OWID=giveOwnerID(buffT0);
            printf("%d\n",OWID);
            char *buffT1;
            buffT1=strdup(buff);
            RID=giveReposID(buffT0);
            printf("%d\n",RID);
            r1=procuraBinariaU(arrayU,0,Nu-1,OWID);
            r2=procuraBinariaC(arrayC,0,Nc-1,RID);
            printf("%d-%d\n",r1,r2);
            if (r1==1 && r2==1){
                fprintf(d,buff);
            }
        }
    }
}