#include "Food.h"
void print(const void *data)
{
    const struct MENU *p = data;
    printf("%.2f    %s\n", p->price, p->name);
}

int main()
{
    int i = 1;
    struct MENU data; // 存储录入的菜品
    LLIST *handler = NULL;
    handler = menu_crate(sizeof(struct MENU)); // 创建头结点
    if (handler == NULL)
    {
        fprintf(stderr, "llist_create() Is Failed!\n");
        return -1;                                      
    }

    //system("clean");

    cai_insert(handler,&data);
    
    menu_display(handler);
    
    cai_change(handler);

    menu_display(handler);

    

    menu_destroy(handler);

    return 0;
}
