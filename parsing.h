#ifndef PARSING_H_
#define PARSING_H_
typedef struct repos{
	int  id;
	int  owner_id;
    char *full_name;
    char *license;
    char *has_wiki;
    char *description;
    char *language;
    char *default_branch;
    char *created_at;
    char *updated_at;
    int forks_count;
    int open_issues;
    int stargazers_count;
    int size;
}*REPOS;
typedef struct commits{
	int repo_id;
	int author_id;
	int committer_id;
    char *commit_at;
    char *message;
}*COMMITS;
typedef struct users{
    int id;
    int login;
    char *type;
    char *created_at;
    int followers;
    char *follower_list;
    int following;
    char *following_list;
    int public_gists;
    int public_repos;
}*USERS;
void build_user(char line [],USERS u);
void build_repos(char line[],REPOS r);
void build_commits(char line [],COMMITS c);
int readUsers(FILE *s,BSTU u,int *nBot,int *nUser,int *nOrg);
int readRepos(FILE *s,BSTR r);
int readCommits(FILE *s,BSTC c);
#endif