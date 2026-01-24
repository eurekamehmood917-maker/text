#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

LLIST *llist_create(void)
{
    LLIST *handler = NULL;//handler指针指向开辟的空间

    handler = malloc(sizeof(LLIST));//开辟头节点的空间
    if(handler == NULL)//判断头节点的空间是否开辟失败
        return NULL;//由于头节点空间开辟失败,结束函数,并且返回NULL
    handler->next = NULL;//让头节点的next指针指向NULL

    return handler;//返回开辟空间的首地址
}

int llist_insert(LLIST *handler, const void *data, int mode)
{
    LLIST *p = handler;//使用指针p代替handler指针做操作
    LLIST *newnode = NULL;//newnode指针指向新开辟的节点

    newnode = malloc(sizeof(LLIST));//开辟新的数据节点的空间
    if(newnode == NULL)//判断开辟新的数据节点的空间是否失败
        return -1;//由于开辟新的节点的空间失败,结束函数,并且返回-1

    memcpy(newnode, data, sizeof(LLIST));//把数据拷贝到新的数据节点中

    switch(mode)
    {
        case HEADINSERT : break;
        case TAILINSERT : while(p->next != NULL) p = p->next; break;
        default : free(newnode); return -2;
        //由于插入模式选择失败,释放开辟的新的节点空间,结束函数,并且返回-2
    }
    newnode->next = p->next;
    p->next = newnode;

    return 0;
}

void llist_display(LLIST *handler)
{
    LLIST *cur = NULL;//cur指针将来指向每一个数据节点

    for(cur = handler->next; cur != NULL; cur = cur->next)
        printf("%d  %s  %d\n", cur->id, cur->name, cur->math);
}

void llist_destroy(LLIST *handler)
{
    LLIST *back = handler;//前指针
    LLIST *cur = handler->next;//当前要释放的节点

    while(cur != NULL)//循环释放所有的数据节点
    {
        back->next = cur->next;
        free(cur);
        cur = back->next;
    }
    free(back);//释放头节点
}

static LLIST *_find(LLIST *handler, const void *find_data)
{
    LLIST *cur = NULL;//cur指针指向每个数据节点

    for(cur = handler->next; cur != NULL; cur = cur->next)
        if(cur->id == *(int *)find_data || !strcmp(cur->name, find_data))
            return cur;
    return NULL;
}

LLIST *llist_find(LLIST *handler, const void *find_data)
{
    return _find(handler, find_data);
}

int llist_delete(LLIST *handler, const void *find_data)
{
    LLIST *back = handler;//前指针
    LLIST *cur = NULL;//cur指针指向要删除的节点

    cur = _find(handler, find_data);//查找要删除的节点
    if(cur == NULL)//判断是否没有找到要删除的节点
        return -1;//由于没有找到要删除的节点,结束函数,并且返回-1

    while(back->next != cur)//找到要删除节点的前一个位置
        back = back->next;

    back->next = cur->next;//把要删除的节点从链表中摘除
    free(cur);//释放要删除的节点

    return 0;
}

int llist_fetch(LLIST *handler, const void *find_data, void *save)
{
    LLIST *back = handler;//前指针
    LLIST *cur = NULL;//cur指针指向要取出数据的节点

    cur = _find(handler, find_data);//查找要取出数据的节点
    if(cur == NULL)//判断是否没有找到要取出数据的节点
        return -1;//由于没有找到要取出数据的节点,结束函数,并且返回-1

    while(back->next != cur)//找到要取出数据的节点的前一个位置
        back = back->next;

    back->next = cur->next;//把要取出数据的节点从链表中摘除
    memcpy(save, cur, sizeof(LLIST));//把要取出数据节点的数据拷贝出来
    free(cur);

    return 0;
}
