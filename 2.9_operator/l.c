#include<stdio.h>
void swap_by_address(int *a, int *b) {
    int temp = *a;  // 解引用获取值
    *a = *b;        // 修改原始变量
    *b = temp;
    printf("函数内交换后: *a=%d, *b=%d\n", *a, *b);
}

int main() {
    int x = 5, y = 10;
    
    printf("调用前: x=%d, y=%d\n", x, y);
    swap_by_address(&x, &y);  // 传递 x,y 的地址
    printf("调用后: x=%d, y=%d\n", x, y);  // x,y 被交换
 
 	int a=2,b=3;
	
    printf("调用前: a=%d, b=%d\n", a, b);
    swap_by_address(&a, &b);  // 传递 x,y 的地址
    printf("调用后: a=%d, b=%d\n", a, b);  // x,y 被交换
    return 0;
}
