#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "parsing.h"
#include "funcoesAux.h"

USERS build_user(char line []){
    USERS u= malloc(sizeof(struct users));
    u->id=atoi(strdup(strsep(&line,";\n")));
    u->login=atoi(strdup(strsep(&line,";\n")));
    u->type=strdup(strsep(&line,";\n"));
    u->created_at=strdup(strsep(&line,";\n"));
    u->followers=atoi(strdup(strsep(&line,";\n")));
    u->follower_list=strdup(strsep(&line,";\n"));
    u->following=atoi(strdup(strsep(&line,";\n")));
    u->following_list=strdup(strsep(&line,";\n"));
    u->public_gists=atoi(strdup(strsep(&line,";\n")));
    u->public_repos=atoi(strdup(strsep(&line,";\n")));
    return u;
}
void build_repos(char line[],REPOS r){
    r->id=atoi(strdup(strsep(&line,";\n")));
    r->owner_id=atoi(strdup(strsep(&line,";\n")));
    r->full_name=strdup(strsep(&line,";\n"));
    r->license=strdup(strsep(&line,";\n"));
    r->has_wiki=strdup(strsep(&line,";\n"));
    r->description=strdup(strsep(&line,";\n"));
    r->language=strdup(strsep(&line,";\n"));
    r->default_branch=strdup(strsep(&line,";\n"));
    r->created_at=strdup(strsep(&line,";\n"));
    r->updated_at=strdup(strsep(&line,";\n"));
    r->forks_count=atoi(strdup(strsep(&line,";\n")));
    r->open_issues=atoi(strdup(strsep(&line,";\n")));
    r->stargazers_count=atoi(strdup(strsep(&line,";\n")));
    r->size=atoi(strdup(strsep(&line,";\n")));
}
void build_commits(char line [],COMMITS c){
    c->repo_id=atoi(strdup(strsep(&line,";\n")));
    c->author_id=atoi(strdup(strsep(&line,";\n")));
    c->committer_id=atoi(strdup(strsep(&line,";\n")));
    c->commit_at=strdup(strsep(&line,";\n"));
    c->message=strdup(strsep(&line,";\n"));
}

int readUsers(FILE *s,BSTU u,int *nBot,int *nUser,int *nOrg){
   int max_len=150000;
   char line[max_len];
   int NumeroDeUsers=0;// Query de id=4;
   (*nBot)=0;// Query de id=1;
   (*nUser)=0;// Query de id=1;
   (*nOrg)=0;// Query de id=1;
   while(fgets(line, max_len, s)!=NULL){
      USERS user;
      user=build_user(line);
      printf("teste\n");
      printf("%d\n",user->id);
      if (mystrcompare("User",user->type)==1) (*nUser)++;// Query de id=1;
      else if (mystrcompare("Bot",user->type)==1) (*nBot)++;// Query de id=1;
      else (*nOrg)++;// Query de id=1;
      insertUSERS(u,user);
      NumeroDeUsers++;
    }
    return NumeroDeUsers;
}
int readRepos(FILE *s,BSTR r){
    int max_len=250000;
    char line[max_len];
    int NumeroDeRepos=0;// Query de id=2;
    while(fgets(line,max_len,s)!=NULL){
        REPOS repo=malloc(sizeof(struct repos));
        build_repos(line,repo);
        insertREPOS(r,repo);
        NumeroDeRepos++;
    }
    return NumeroDeRepos;
}

int readCommits(FILE *s,BSTC c){
    int max_len=150000;
    char line[max_len];
    int NumeroDeCommits=0;//Query de id=4;
    while(fgets(line,max_len,s)!=NULL){
        COMMITS commit=malloc(sizeof(struct commits));
        build_commits(line,commit);
        insertCOMMITS(c,commit);
        NumeroDeCommits++;
    }
    return NumeroDeCommits;
}
