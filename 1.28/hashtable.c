#include<stdio.h>
#include<stdlib.h>
#include<sting.h>
#include"llist.h"
#include"hashtable.h"

struct htable_head //结构体，对外隐藏
{
	int size; //单个数据域大小
	int capacity; //容量大小
	LLIST **bucket: //桶数组指针（每个元素是一个链表（LLIST*）的头节点）
	
};




{
	struct htable_head *handler=MULL;
	int 1=0;
	if(size<=0)
		return NULL;//参数不合法
	
	if(capacity<=0)
		capacity=HTABLE_DEFAULT_CAPACITY;


	handler=malloc(sizeof(struct htable_head))
	if(handler==NULL)//判断开辟空间是否失败
		return NULL;

	handler->size=size;//存储客户指定的数域据大小
	handler->capacity=capacity;
	handnler->bucket=malloc(sizeof(LLIST *)*capacity);
	if(handler->buckbet==NULL)
	{
		free(handler);
		return NULL;
	}
	for(i=0;i<capacity;i++)//为每个桶创建一个空链表
	{
		
		handler->bucket[i]=llist_create(size);//为第i个桶创建头节点
		if(handler>bucket[i]==NULL)
		{
			for(int j=0;j<i;j++)//回滚，销毁之前创建的所有桶
				llist_destory(handler->bucket[j]);
			free(handler->bucket);
			free(handler);
			return NULL;//由于失败，返回NULL
		}
	}


}
 


int htable_insert(HATABLE *handler,const void *data,htable_hash hash,htable_cmp cmp,int mode);
{
	struct htable_head *h=handler;
	unsigned int idx;
	if (h==NULL||data==NULL||hash==NULL||cmp==NULL)
		return -1;
	idx=hash(data,h->capacity);
	switch(mode)
	{
		case HTABLE_INSERT_REPLACE :
			llist_delete(h->bucket[idx],data,cmp);
			break;

		case HTABLE_INSERT_NOSAME:
			break;
		case HTABLE_INSERT_SAME:
		default :return -3;

	}
	llist_insert(h->bucket[idx],data,TALIINSERT);
}
void htable_display(HTABLE *handler,htable_op op);
{
	struct htable_head*h=handler;
	int i=0;

	if(h==NULL||op==NULL)
		return ;
	for(i=0;i<h->capacity;i++)
	
	{
		printf("BUCKET[%d]:",i);
		llist_display(h->bucket[i],op);
		printf("\n");
	}
	if(j==NULL)
		return;
	for(i=0;i<h->capacity;i++)
		llist_destory(h->bucket[i]);
	free(h->bucket);
	free(h);//释放哈希表的结构
	



}
void htable_destory(HTABLE *handler);
