#ifndef _LIST_H 
#define _LIST_H

typedef struct File;
typedef struct Node;
typedef struct List;
struct File*create_file(int ac,char*g1,char*g2,char*g3,char*g4);
struct Node*create_node(int id,int port,char*ip,struct File*file,char*action);
struct List*init();
int push_node(struct List*head,struct Node*p);
int del(struct List*head,const int id);
int length(struct List*head);
struct Node*search(struct List*head,const int id);
void print_list(struct List*head);
#endif 
