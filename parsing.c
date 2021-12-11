#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "parsing.h"
#include "funcoesAux.h"
struct commits{
    char* repo_id;
    char* author_id;
    char* committer_id;
    char* commit_at;
    char* message;
};

struct user{
    char* id;
    char* login;
    char* type;
    char* created_at;
    char* follower_list; 
    char* following_list;
    long unsigned int NumeroDeCommitsDados;
};

struct repo{
    char* id;
    char* owner_id;
    char* description;
    char* language;
    char* created_at;
    char* updated_at;
};

struct arrayU{
    USER *us;
    int celulasOcup;
    int celulasTotais;
};
struct arrayR{
    REPO *rps;
    int celulasOcup;
    int celulasTotais;
};
struct arrayC{
    COMMIT *cmt;
    int celulasOcup;
    int celulasTotais;
};
//id;login;type;created_at;followers;follower_list;following;following_list;public_gists;public_repos
USER build_user(char line[]){
    USER u = malloc(sizeof(struct user));
    char *buff = line;
    u->id = strdup(strsep(&buff, ";\n"));
    u->login = strdup(strsep(&buff, ";\n"));
    u->type = strdup(strsep(&buff, ";\n"));
    u->created_at = strdup(strsep(&buff, ";\n"));
    char *temp=strdup(strsep(&buff, ";\n"));
    u->follower_list = strdup(strsep(&buff, ";\n"));
    char *temp1=strdup(strsep(&buff, ";\n"));
    u->following_list = strdup(strsep(&buff, ";\n"));
    return u;
}
//id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size
REPO build_repo(char line[]){
    REPO r = malloc(sizeof(struct repo));
    char *buff = line;
    r->id = strdup(strsep(&buff, ";\n"));
    r->owner_id = strdup(strsep(&buff, ";\n"));
    char *temp=strdup(strsep(&buff, ";\n"));
    char *temp1=strdup(strsep(&buff, ";\n"));
    char *temp2=strdup(strsep(&buff, ";\n"));
    r->description = strdup(strsep(&buff, ";\n"));
    r->language = strdup(strsep(&buff, ";\n"));
    char *temp3=strdup(strsep(&buff, ";\n"));
    r->created_at = strdup(strsep(&buff, ";\n"));
    r->updated_at = strdup(strsep(&buff, ";\n"));
    return r;
}
//repo_id;author_id;committer_id;commit_at;message
COMMIT build_commit(char line[]){
    COMMIT c = malloc(sizeof(struct commits));
    char *buff = line;
    c->repo_id = strdup(strsep(&buff, ";\n"));
    c->author_id = strdup(strsep(&buff, ";\n"));
    c->committer_id = strdup(strsep(&buff, ";\n"));
    c->commit_at= strdup(strsep(&buff, ";\n"));
    c->message = strdup(strsep(&buff, ";\n"));
    return c;
}
aUsers initializeArrayU(aUsers aU){
    aU->us=(USER*) malloc(200*sizeof(USER));
    aU->celulasOcup=0;
    aU->celulasTotais=200;
    return aU;
}
void insertArrayU(aUsers aU,USER u){
    if(aU->celulasOcup!=aU->celulasTotais){
        aU->us[aU->celulasOcup]=u;
        aU->celulasOcup=(aU->celulasOcup)+1;
    }
    else {
        aU->us=realloc(aU->us,(2*aU->celulasTotais)*(sizeof(USER)));
        aU->us[aU->celulasOcup]=u;
        aU->celulasOcup=(aU->celulasOcup)+1;
        aU->celulasTotais=2*(aU->celulasTotais);
    }
}
aRepos initializeArrayR(aRepos aR){
    aR->rps=malloc(200*sizeof(REPO));
    aR->celulasOcup=0;
    aR->celulasTotais=200;
    return aR;
}
void insertArrayR(aRepos aR,REPO r){
    if(aR->celulasOcup!=aR->celulasTotais){
        aR->rps[aR->celulasOcup]=r;
        aR->celulasOcup=(aR->celulasOcup)+1;
    }
    else {
        aR->rps=realloc(aR->rps,(2*aR->celulasTotais)*(sizeof(REPO)));
        aR->rps[aR->celulasOcup]=r;
        aR->celulasOcup=(aR->celulasOcup)+1;
        aR->celulasTotais=2*(aR->celulasTotais);
    }
}
aCommit initializeArrayC(aCommit aC){
    aC->cmt=malloc(200*sizeof(COMMIT));
    aC->celulasOcup=0;
    aC->celulasTotais=200;
    return aC;
}
void insertArrayC(aCommit aC,COMMIT c){
    if(aC->celulasOcup!=aC->celulasTotais){
        aC->cmt[aC->celulasOcup]=c;
        aC->celulasOcup=(aC->celulasOcup)+1;
    }
    else {
        aC->cmt=realloc(aC->cmt,(2*aC->celulasTotais)*(sizeof(COMMIT)));
        aC->cmt[aC->celulasOcup]=c;
        aC->celulasOcup=(aC->celulasOcup)+1;
        aC->celulasTotais=2*(aC->celulasTotais);
    }
}
float RUsers(FILE *s,aUsers aU,aCommit aC, int *nBot,int *nUser,int *nOrg,float *nColab){
   int i=0;
   aU=initializeArrayU(aU);
   int max_len=500000;
   char line[max_len];
   float NumeroDeUsers=0;// Query de id=4;
   (*nColab)=0;//Query de id=2;
   (*nBot)=0;// Query de id=1;
   (*nUser)=0;// Query de id=1;
   (*nOrg)=0;// Query de id=1;
   while(fgets(line, max_len, s)!=NULL){
      USER user;
      user=build_user(line);
      if(mystrcompare("User",user->type)==1)(*nUser)++;
      else if (mystrcompare("Bot",user->type)==1)(*nBot)++; 
      else(*nOrg)++;
      if (binarySearchC(aC,0,aC->celulasOcup,atoi(user->id))==1)(*nColab)++;
      insertArrayU(aU,user);
      NumeroDeUsers++;
    }
    return NumeroDeUsers;
}
float RRepos(FILE *s,aRepos aR){
    aR=initializeArrayR(aR);
    int max_len=250000;
    char line[max_len];
    float NumeroDeRepos=0;// Query de id=2;
    while(fgets(line,max_len,s)!=NULL){
        REPO repo;
        repo=build_repo(line);
        insertArrayR(aR,repo);
        NumeroDeRepos++;
    }
    return NumeroDeRepos;
}
float RCommit(FILE *s,aCommit aC){
    aC=initializeArrayC(aC);
    int max_len=150000;
    char line[max_len];
    float NumeroDeCommits=0;//Query de id=4;
    while(fgets(line,max_len,s)!=NULL){
        COMMIT commit;
        commit=build_commit(line);
        insertArrayC(aC,commit);
        NumeroDeCommits++;
    }
    return NumeroDeCommits;
}

void freeaUsers(aUsers aU){
    if (aU!=NULL){
        free(aU);
    }
}
void freeaRepos(aRepos aR){
    if(aR!=NULL){
        free(aR);
    }
}
void freeaCommit(aCommit aC){
    if(aC!=NULL){
        free(aC);
    }
}
//Colaborador é um user que dá um commit, pode ser author_id ou committer_id
int binarySearchC(aCommit aC, int fstP, int lastP, int ID){
    if (lastP > fstP) {
        int mid = fstP + (lastP - fstP) / 2;
        if (atoi(aC->cmt[mid]->author_id)== ID || atoi(aC->cmt[mid]->committer_id)== ID)
            return 1;
        else if (atoi(aC->cmt[mid]->author_id)> ID)
        return binarySearchC(aC,fstP, mid - 1, ID);
        else return binarySearchC(aC, mid + 1,lastP, ID);
    }
    return 0;
}
int binarySearchU(aUsers aU, int fstP, int lastP, int ID){
    if (lastP > fstP) {
        int mid = fstP + (lastP - fstP) / 2;
        if (atoi(aU->us[mid]->id)==ID){
            if (mystrcompare("Bot",aU->us[mid]->type)==1) return 1;
            else return 0;
        }
        else if (atoi(aU->us[mid]->id)> ID)
        return binarySearchU(aU,fstP, mid - 1, ID);
        else return binarySearchU(aU, mid + 1,lastP, ID);
    }
}
int partitionC(aCommit aC, int i, int uP) {
  COMMIT tmp;
  int pivot = atoi(aC->cmt[uP]->author_id);
  int n = (i-1);
  for (int j = i; j < uP; j++) {
        if (atoi(aC->cmt[j]->author_id) <= pivot) {
        n++;
        tmp=aC->cmt[n];
        aC->cmt[n]= aC->cmt[j];
        aC->cmt[j]=tmp;                                       
        }
    }
    tmp=aC->cmt[n+1];
    aC->cmt[n+1]=aC->cmt[uP];
    aC->cmt[uP]=tmp;                                                    
  return (n+1);
}
int partitionU(aUsers aU, int i, int uP) {
  USER tmp;
  int pivot = atoi(aU->us[uP]->id);
  int n = (i-1);
  for (int j = i; j < uP; j++) {
        if (atoi(aU->us[j]->id) <= pivot) {
        n++;
        tmp=aU->us[n];
        aU->us[n]= aU->us[j];
        aU->us[j]=tmp;                                       
        }
    }
    tmp=aU->us[n+1];
    aU->us[n+1]=aU->us[uP];
    aU->us[uP]=tmp;                                                    
  return (n+1);
}
void quickSortC(aCommit aC, int i, int uP) {
  if (i<uP) {
    int pi = partitionC(aC, i, uP);
    quickSortC(aC, i, pi-1);
    quickSortC(aC, pi+1, uP);
  }
}

void quickSortU(aUsers aU, int i, int uP) {
  if (i<uP) {
    int pi = partitionU(aU, i, uP);
    quickSortU(aU, i, pi-1);
    quickSortU(aU, pi+1, uP);
  }
}
int celulasOcupU(aUsers aU){
    return aU->celulasOcup;
}

int getsizeofC(aCommit aC){
    return sizeof(struct arrayC);
}
int getsizeofR(aRepos aR){
    return sizeof(struct arrayR);
}
int getsizeofU(aUsers aU){
    return sizeof(struct arrayU);
}

int celulasOcupC(aCommit aC){
    return aC->celulasOcup;
}
int giveAutID(aCommit aC,int i){
    return atoi(aC->cmt[i]->author_id);
}
int giveComtID(aCommit aC,int i){
    return atoi(aC->cmt[i]->committer_id);
}
COMMIT giveCommit(aCommit aC,int ind){
    return (aC->cmt[ind]);
}
USER giveUser(aUsers aU,int ind){
    return (aU->us[ind]);
}
int getAuthorID(COMMIT cmt){
    return atoi(cmt->author_id);
}
int getCommitterID(COMMIT cmt){
    return atoi(cmt->committer_id);
}
char *getUserType(USER us){
    return us->type;
}
int getUserID(USER us){
    return atoi(us->id);
}
int getRepoID(COMMIT cmt){
    return atoi(cmt->repo_id);
}
char *getLoginU(USER us){
    return (us->login);
}
char *getCommit_at(COMMIT cmt){
    return (cmt->commit_at);
}
char * giveLogin(USER us){
    return (us->login);
}
int celulasOcupR(aRepos aR){
    return (aR->celulasOcup);
}
int getIDR(aRepos aR,int ind){
    return atoi(aR->rps[ind]->id);
}
int getRpsID(COMMIT cmt){
    return atoi(cmt->repo_id);
}
char *getLangR(aRepos aR,int ind){
    return aR->rps[ind]->language;
}
char *getDescR(aRepos aR,int ind){
    return aR->rps[ind]->description;
}
int binarySearchR(aRepos aR, int fstP, int lastP, int ID){
    if (lastP > fstP) {
        int mid = fstP + (lastP - fstP) / 2;
        if (atoi(aR->rps[mid]->id)==ID) return  mid;
        else if (atoi(aR->rps[mid]->id)> ID)
        return binarySearchR(aR,fstP, mid - 1, ID);
        else return binarySearchR(aR, mid + 1,lastP, ID);
    }
}
//Função que ordena o array dos repositórios pelo repo_id
int partitionR(aRepos aR, int i, int uP) {
  REPO tmp;
  int pivot = atoi(aR->rps[uP]->id);
  int n = (i-1);
  for (int j = i; j < uP; j++) {
        if (atoi(aR->rps[j]->id) <= pivot) {
        n++;
        tmp=aR->rps[n];
        aR->rps[n]= aR->rps[j];
        aR->rps[j]=tmp;                                       
        }
    }
    tmp=aR->rps[n+1];
    aR->rps[n+1]=aR->rps[uP];
    aR->rps[uP]=tmp;                                                    
  return (n+1);
}
void quickSortR(aRepos aR, int i, int uP) {
  if (i<uP) {
    int pi = partitionR(aR, i, uP);
    quickSortR(aR, i, pi-1);
    quickSortR(aR, pi+1, uP);
  }
}
char *getDataCommit(COMMIT cmt){
    return cmt->commit_at;
}

