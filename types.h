#ifndef TYPES_H_
#define TYPES_H_

struct user {
	int *id;
};

typedef struct user* USER;

struct repos{
	int  *id;
	int  *owner_id;
};
typedef struct repos* REPOS;
struct commits{
	int repo_id;
	int author_id;
	int committer_id;
};
typedef struct commits* COMMITS;

#endif
