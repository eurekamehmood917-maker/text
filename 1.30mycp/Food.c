#include "Food.h"

LLIST* menu_crate(int size)
{
    LLIST *handler = NULL;
    handler = malloc(sizeof(LLIST));
    if(handler == NULL)
        return NULL;
    handler->size = size;//存储用户数据域的大小
    handler->head.next = &handler->head;
    return handler;
}

int menu_insert(LLIST* handler,const void *data)
{
    struct llist_node *p = &handler->head;
    struct llist_node *newnode = NULL;

    newnode = malloc(sizeof(struct llist_node) + handler->size);
    if (newnode == NULL)
        return -1;

    memcpy(newnode->data,data,handler->size);

    newnode->next = p->next;
    p->next = newnode;
    
    return 0;
}

void menu_display(LLIST* handler)
{
    struct llist_node *cur = handler->head.next;
    for(; cur != &handler->head; cur = cur->next)
        print(cur->data);
}

// void cai_insert(LLIST *handler,struct MENU* data)
// {
//     int i = 1;
//     while (i == 1)
//     {
//         printf("=== 添加菜品 ===\n");
//         printf("请输入想要添加的菜品以及价格,输入菜品后按回车输入价格\n");
//         printf("菜品名称:\n");
//         scanf("%s", data->name);
//         getchar();
//         printf("价    格:\n");
//         scanf("%f", &data->price);
//         menu_insert(handler, data);
//         printf("是否需要继续输入,输入 1 继续添加,输入其他跳出\n");
//         scanf("%d", &i);
//     }
// }
void cai_insert(LLIST *handler,struct MENU* data)
{
    char i = 'y';

    if(handler == NULL || data == NULL)
    {
        fprintf(stderr,"错误：链表头结点或者菜品数据指针为空\n");
        return;
    }
    
    do{
        printf("=== 添加菜品 ===\n");
        printf("请输入想要添加的菜品以及价格,输入菜品后按回车输入价格\n");
        printf("菜品名称:\n");
        //scanf("%s", data->name);
        fgets(data->name,NAMESIZE,stdin);
        char *n = strchr(data->name, '\n'); // 找到换行符的位置
        if (n != NULL)// 替换为字符串结束符
            *n = '\0';          
        printf("价    格:\n");
        //scanf("%f", &data->price);
        while (scanf("%f", &data->price) != 1) {
            fprintf(stderr, "价格必须是数字，请重新输入！\n");
            while (getchar() != '\n'); // 清理缓冲区的非法字符
            printf("价    格：");
        }
        while (getchar() != '\n');
        menu_insert(handler, data);
        printf("菜品添加成功!\n");
        printf("是否需要继续输入,输入 (y/Y) 继续添加,输入其他跳出\n");
        scanf("%c", &i);
        while (getchar() != '\n');
    }while (i == 'y' || i == 'Y');
}

struct llist_node *menu_find_by_name(LLIST *handler, const char* name)
{
    if(handler == NULL || name == NULL)
        return NULL;
    struct llist_node *cur = handler->head.next;
    struct MENU *item;
    
    for(;cur != &handler->head;cur = cur->next)
    {
        item = (struct MENU *)cur->data;
        if(strcmp(item->name,name) == 0)
        {
            return cur;
        }
    }
    return NULL;
}

void cai_change(LLIST *handler) {

    if (handler == NULL)
    {
        printf("菜单未初始化！\n");
        return;
    }
    char targetName[NAMESIZE];//用来存储名字
    float newPrice;
    char choice;
    do {
        printf("\n=== 修改菜品价格 ===\n");
        if (handler->head.next == &handler->head)//检查是否为空菜单
        {
            printf("当前菜单为空，请先添加菜品！\n");
            return;
        }
        printf("请输入要修改价格的菜品名称: ");
        scanf("%s", targetName);
        struct llist_node *foundNode = menu_find_by_name(handler, targetName);//通过上面实现的查找函数来查找要修改的菜
        if (foundNode == NULL)
        {
            printf("未找到菜品 '%s'，请检查输入是否正确。\n", targetName);
        }
        else
        {
            struct MENU *item = (struct MENU *)foundNode->data;
            // 显示当前信息
            printf("\n找到菜品：%s\n", item->name);
            printf("当前价格：%.2f\n", item->price);
            // 输入新价格
            printf("请输入新的价格: ");
            while (scanf("%f", &newPrice) != 1 || newPrice < 0)
            {
                printf("价格无效！请输入一个有效的正数: ");
                while (getchar() != '\n');  // 清除输入缓冲区
            }
            // 确认修改
            printf("\n确认将 %s 的价格从 %.2f 修改为 %.2f 吗？(y/n): ", 
                   item->name, item->price, newPrice);
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y')
            {
                item->price = newPrice;
                printf("价格修改成功！\n");
            }
            else
            {
                printf("已取消修改。\n");
            }
        }
        
        printf("\n是否继续修改其他菜品？(y/n): ");//询问是否继续修改
        getchar();
        scanf("%c", &choice);
        while (getchar() != '\n');  //清除输入缓冲区
        
    } while (choice == 'y' || choice == 'Y');
}

void menu_destroy(LLIST* handler) {
    struct llist_node *cur = handler->head.next;
    struct llist_node *next;
    
    while (cur != &handler->head) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free(handler);
}

