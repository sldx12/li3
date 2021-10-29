#ifndef TYPES_H_
#define TYPES_H_

struct gh_user {
	char *public_repos;
	char *id;
	char *followers;
	char *follower_list;
	char *type;
	char *following_list;
	char *public_gists;
	char *created_at;
	char *following;
	char *login;
};

typedef struct gh_user* GH_USER;

typedef struct lligada {
 GH_USER u;
 struct lligada *prox;
} *LUser;
#endif
