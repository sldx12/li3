#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "types.h"
#include "giveIDs.h"

int giveID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(temp);
    return r;
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
    r=atoi(temp);
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
    r=atoi(temp);
    return r;
}
int giveReposID(char v[]){
    int r;
    char *buff,*buff1;
    char temp[15];
    buff=strdup(v);
    buff1=strdup(strsep(&buff,";"));
    strcpy(temp,buff1);
    r=atoi(temp);
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
    r=atoi(temp);
    return r;
}