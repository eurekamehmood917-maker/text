#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#define HTABLE_DEFAULT_CAPACITY 10//默认容量
#define HTABLE_REPLACE 0  //覆盖已经存在数据的标识
#define HTABLE_INSERT_NOSAME 1  //不允许重复数据的标识
#define HTABLE_INSERT_SAME 2	//允许存在重复数据的标识

typedef void (*htable_op)(const void *);//定义函
*/



int htable_insert(HATABLE *handler,const void *data,htable_hash hash,htable_cmp cmp,int mode);

void htable_display(HTABLE *handler,htable_op op);

void htable_destory(HTABLE *handler);










#endif
