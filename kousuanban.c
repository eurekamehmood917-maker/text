#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void init(int* s1,int* s2,int* y)
{
	*s1=rand()%10;
	*y=rand()%5;
	*s2=rand()%9+1;
}

int print(int s1,int s2,int y)
{
	switch(y)
	{
		case 0:printf("%d+%d=",s1,s2);return s1+s2;
		case 1:printf("%d-%d=",s1,s2);return s1-s2;
		case 2:printf("%d*%d=",s1,s2);return s1*s2;
		case 3:printf("%d/%d=",s1,s2);return s1/s2;
		case 4:printf("%d %% %d=",s1,s2);return s1%s2;
	}
	
}

int check(int t,int g)
{
	if(t==g)
	{
		printf("bingou,加20分\n");
		return 10;
	}
	else
	{
		printf("error,加0分\n");
		return 0;
	}
}
int main(void)
{
	int s1=0,s2=0;//存储两个操作s1,s2
	int y=0;//存储运算符
	int t=0;//存储计算结果
	int g=0;//存储客户输入的结果
	int i=0;//循环变量
	int score=0;//分数
	srand(getpid());//随机种子
	
	for(i=0;i<10;i++)
	{
		init(&s1,&s2,&y);
		t=print(s1,s2,y);
		scanf("%d",&g);
		score += check(t,g);
	}
	printf("分数: %d\n",score);

	return 0;
}
