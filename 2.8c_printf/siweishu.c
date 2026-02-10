#include<stdio.h>
int main(void)
{
	int sum=0;
	
	scanf("%d",&sum);

	printf("千位 ：%d\n",sum/1000);
	printf("百位 ：%d\n",sum/100%10);
	printf("十位 ：%d\n",sum/10%10);
	printf("个位 ：%d\n",sum%10);

	return 0;
} 




