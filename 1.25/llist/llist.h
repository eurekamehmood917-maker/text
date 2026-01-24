#ifndef __LLIST_H
#define __LLIST_H

#define NAMESIZE 20

enum E{HEADINSERT,TAILINSERT};//使用设定头插法和尾插法
    
typedef struct llist_node//链表中每个节点的结构
{   
    int id;//数据域
    char name[NAMESIZE];//数据域
    int math;//数据域
    struct llist_node *next;//指针域(指向下一个节点)
}LLIST;//给结构体起个别名

LLIST *llist_create(void);
    
int llist_insert(LLIST *handler, const void *data, int mode);

void llist_display(LLIST *handler);

void llist_destroy(LLIST *handler);
    
LLIST *llist_find(LLIST *handler, const void *find_data);
    
int llist_delete(LLIST *handler, const void *find_data);

int llist_fetch(LLIST *handler, const void *find_data, void *save);
    
#endif

