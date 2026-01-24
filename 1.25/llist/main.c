#include <stdio.h>
#include "llist.h"

int main(void)
{   
    LLIST *handler = NULL;//handler指针指向链表的头节点
    LLIST data;//data变量存储录入的数据
    LLIST save;//save变量存储取出节点的数据
    LLIST *find = NULL;//find指针指向查找到的节点
    int find_id = 100;//存储要查找的ID号
    char *find_name = "stu4";//存储要查找的姓名
    int i = 0;//循环变量
    int ret = 0;//用来存储返回值
    
    handler = llist_create();//创建头节点
    if(handler == NULL)//判断创建头节点是否失败
    {   
        fprintf(stderr, "llist_create() Is Failed!\n");//打印错误信息
        return -1;//由于创建头节点失败,结束程序,并且返回-1
    }
    
    for(i = 0; i < 100; i++)
    {   
        data.id = 100 + i;//录入数据
        sprintf(data.name, "stu%d", i);//录入数据
        data.math = 100 - i;//录入数据
        data.next = NULL;//指针指向NULL
        llist_insert(handler, &data, TAILINSERT);//插入数据节点
    }

    llist_display(handler);//遍历链表
    
    printf("-------------------------------\n");

    find = llist_find(handler, "stu88");//查找数据节点
    if(find == NULL)//判断是否没有找到要查找的节点
        printf("Not Find It!\n");
    else
        printf("Find It! %d  %s  %d\n", find->id, find->name, find->math);

#if 0
    ret = llist_delete(handler, "stu9");//删除数据节点
    if(ret != 0)//判断删除数据节点是否失败
        printf("Delete It Is Failed!\n");
    else
        printf("Delete It!\n");
#else
    ret = llist_fetch(handler, &find_id, &save);//取出节点的数据
    if(ret != 0)//判断取出节点的数据是否失败
        printf("Fetch It Is Failed!\n");
    else
        printf("Fetch It! %d  %s  %d\n", save.id, save.name, save.math);
#endif
    
    printf("-------------------------------\n");

    llist_display(handler);//遍历链表
    
    llist_destroy(handler);//销毁链表
    
    return 0;
}
