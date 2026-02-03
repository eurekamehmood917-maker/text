#include <stdio.h>
#include <string.h>
#include "llist.h"

#define NAMESIZE 20

struct stu//客户数据的结构
{
	int id;
	char name[NAMESIZE];
	int math;
	int tel;
};

void print(const void *data)
{
	const struct stu *p = data;//转换指针
	printf("%d  %s  %d  %d\n", p->id, p->name, p->math, p->tel);
}

int id_cmp(const void *data, const void *key)//data是数据域的数据 key是要找的数据
{
	const struct stu *p = data;//转换指针
	const int *k = key;//转换指针

	return !(p->id - *k);
}

int tel_cmp(const void *data, const void *key)//data是数据域的数据 key是要找的数据
{
	const struct stu *p = data;//转换指针
	const int *k = key;//转换指针

	return !(p->tel - *k);
}

int name_cmp(const void *data, const void *key)//data是数据域的数据 key是要找的数据
{
	const struct stu *p = data;//转换指针
	const char *k = key;//转换指针

	return !strcmp(p->name, k);
}

/*

功能：基于学生ID的哈希函数，计算应该存入的索引值
参数：data指向学生结构体的指针
	capacity 哈希表的容量
返回值：计算哈希索引
*/
unsigned int id_hash(const void *data,int capacity)
{
	const struct stu*p=data;//转换指针
	return p->id % capacity;//计算哈希索引
}

unsigned int name_hash(const void*data ,int capacity)
{
	const char *name=(const struct stu*)(data)->name;
	unsigned int hash =0; //存储哈希索引值

	while(*name)
	{
		hash =hash*31+*name++;//字符串哈希函数 hash *31+字符ASCII值
	}
	return hash %capacity;
	

}



int main(void)
{
	HTABLE *ht=NULL;
	struct stu data;
	int i=0;
	
	ht=htable_create(sizeof(struct stu),8);
	if(ht==NULL)
	{
		fprintf(stderr,"htable_create is failed!\n");
		return -1;
	}
	
	for(i=0;i<10;i++)
	{
		data.id=100+i;
		sprintf(data.name,"stu%d",i);
		data.math=100-i;
		data.tel=10010+i;
	
		
		htable_insert(ht,&data,id_hash,id_cmp,HTABLE_INSERT_REPLACE);//插入数据，插入的数据，哈希函数，对比函数，插入模式
	}

	htale_display(ht,print);//遍历哈希表

	httable_destory(ht);



	return 0;
}
