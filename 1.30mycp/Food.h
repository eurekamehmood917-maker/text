#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMESIZE 256

struct MENU
{
    float price;
    char name[NAMESIZE];
};
struct llist_node//数据节点的结构
{   
    struct llist_node *next;//后继指针
    char data[0];//用来标记数据域的首地址
};

typedef struct llist_head//头节点的结构
{   
    int size;//用来存储菜品的大小
    struct llist_node head;//表示头节点
}LLIST;

LLIST* menu_crate(int);

void print(const void *);

int menu_insert(LLIST* ,const void *);

void menu_display(LLIST *handler);

void cai_insert(LLIST *handler,struct MENU* data);

void menu_destroy(LLIST* handler);

void cai_change(LLIST *handler);

struct llist_node *menu_find_by_name(LLIST *handler, const char* name);
