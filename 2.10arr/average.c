#include<stdio.h>

	 int init(int *p,int size);

	void compare(const int *p,int size,int sum);
  int main(void)
{
	int score[10]={0};//定义十个人的成绩,初始化为0
	int size=sizeof(score)/sizeof(*score);//个数size
	int sum = 0;//平均分
	
	 sum = init(score,size);//录入10个学生分数

	compare(score,size,sum);//比较10个学生的分数是否小于平均分

	return 0;
}
	 int init( int *p,int size)
	 {
		 int i=0;
		 int sum=0;
		 for(i=0;i<size;i++)
		 {
			scanf("%d",p+i);
			sum +=p[i];
	     }
		 return sum/10;


	 }

	void compare(const int *p,int size,int sum)
	{
		int i=0;
		for(i=0;i<size;i++)
			if(p[i]<sum)
				printf("%d\n",p[i]);
	}
