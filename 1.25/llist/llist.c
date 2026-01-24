#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"llist.h"
LLSIT*llist_create(void)
{
	LLIST*handler=NULL;
	handler=malloc(sizeof(LLIST));

	if(handler==NULL)
		return NULL;

	 handler->next=NULL;
	 return handler;
 	
}

int llist_insert(LLIST*handler,const void*data,int mode)
{
	LLIST*p=handler;
	LLIST*newnode=NULL;
	newnode=memcpy(sizeof(LLIST));
	
	if(newnode==NULL)
		return -1;
	switch(mode)
	{
		case HEADINSERT :break;
		case TAILINSERT :while(p->next!=NULL)p=p->next;
		default :free(newnode);return -2;
	}
	newnode->next=p->next;
	p->next=newnode;
	
	return 0;
}

void llist_display(LLIST*handler)
{
	LLIST*cur=NULL;
	for(cur=handler->next;cur!=NULL;cur=cur->next)
		printf("%d %s %d\n"cur->id,cur->name,cur->math);
}

void llsit_destory(LLIST*handler)
{
	LLIST*back=handler;
	LLIST*cur=handler->next;

	while(cur!=NULL)
		{
			back->next=cur->next;
			free(cur);
			cur=cur->next;
		}
	free(back);

}

static LLIST*_find(LLIST*handler,const void*find_data)
{
	LLIST*cur=NULL;
	for(cur=handler->next;cur!=NULL;cur=cur->next)
		if((cur->id==*(int*)find_data)||(strcmp(cur->name,find_data)))
			return cur;
		return NULL;
}

LLIST*_find(LLSIT*handler,const void*find_data)
{
	return _find(handler,find_data);
}



int llist_delete(LLIST*handler,const void*find_data)
{
	LLIST*back=handler;
	LLIST*cur=NULL;
	cur=_find(handler,find_data);
	
	if(cur==NULL)
		return -1;
	
	while(back->next!=cur)
	{
		back=back->next;
	}
	back->next=cur->next;
	free(cur);
	return 0;
}

int list_fetch(LLIST*handler, const void*find_data,void* save)
{
	LLIST*back=handler;
	LLIST*cur=NULL;
	cur=_find(handler,find_data);
	if(cur==NULL)
		return -1;
	while(back->next!=cur)
		back=back->next;
	back->next=cur->next;
	memcpy(cur,save,sizeof(LLIST));
	free(cur);
	return 0;
}
