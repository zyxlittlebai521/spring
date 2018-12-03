#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

 struct File
{
	int _agc;
	char* _argv1;
	char* _argv2;
	char* _argv3;
	char* _argv4;
};
struct Node
{
	int _id;
	int _port;
	char _ip[16];
	struct File*_file;
	char*_action;
	struct Node*_next;
};
struct List
{
	int _len;
	struct Node*_head;
};


struct File* create_file(int ac,char*agv1,char*agv2,char*agv3,char*agv4)
{
	struct File*s;
	s = (struct File*)malloc(sizeof(struct File));
	if(NULL == s)
	{
		perror("malloc error");
		return NULL;
	}
	memset(s,0,sizeof(struct File));
	s->_agc = ac;
	s->_argv1 =agv1;
	s->_argv2 = agv2;
	s->_argv3 = agv3;
	s->_argv4 = agv4;
	return s;
}

struct Node*create_node(int id,int port,char*ip, struct File*file,char*action)
{
	struct Node*s;
	s = (struct Node*)malloc(sizeof(struct Node));
	if(NULL == s)
	{
		perror("malloc error");
		return NULL;
	}
	memset(s,0,sizeof(struct Node));
	s->_id = id;
	s->_port = port;
	s->_file = file;	
	memcpy(s->_ip,ip,strlen(ip)+1);
	s->_action = action;
	s->_next = NULL;
	return s;
}

struct List* init()
{
	struct List*s;
	s = (struct  List*)malloc(sizeof(struct List));
	if(NULL == s)
	{
		perror("malloc error");
		return NULL;
	}

	memset(s,0,sizeof(struct List));
	s->_head = NULL;
	s->_len = 0;
	return s;
}

int push_node(struct List*head,struct Node*node)
{
	if(head == NULL || node == NULL)return -1;
	
	node->_next = head->_head;
	head->_head = node;
	head->_len +=1;

	return 1;
}


struct Node*search(struct List*head, const int id)
{
	struct Node*s;
	if(head == NULL || id < 0)return NULL;
	s = head->_head;
	while( NULL != s)
	{
		if(s->_id == id)
		{
			return s;
		}
		s = s->_next;
	}
	return NULL;
}

void free_node(struct Node*p)
{
	free(p);
	p = NULL;
	return ;
}
int length(struct List*head)
{
	if(NULL == head)return -1;
	return head->_len;
}

int del(struct List*head,const int id)
{
	struct  Node*s,*p;
	if(NULL == head ||head->_head == NULL ||  id < 0)return -1;
	s= head->_head;
	p = s->_next;

	if(id == s->_id)
	{
		head->_head = s->_next;
		free_node(s);
		return 1;
	}
	while( p)
	{
		if(id == p->_id)
		{
			s->_next = p->_next;
			free(p);
			head->_len -=1;
			return 1;
		}

		s = p;
		p = p->_next;
	}
	return -1;
}

void print_list(struct List*head)
{
	struct Node*s ;

	if(NULL == head || NULL == head->_head)return ;
	s = head->_head;
	while(s)
	{
		printf("id = %d  port = %d",s->_id,s->_port);
		printf("    ip = %s    action = %s\n",s->_ip,s->_action);
	//	printf("argc = %d ",s->_file->_agc);
	//	printf("agv1 = %s  aegv2 = %s  argv3 = %s  argv4 = %s\n",
		//	s->_file->_argv1,s->_file->_argv2,s->_file->_argv3,s->_file->_argv4);
		s= s->_next;
	}
	return ;
}




























































