#include<stdio.h>

int main(void)
{
	int i=0,j=0;
	
	for(i=0;i<100;i++)//取出0-100的所有的数字
	{
		for(j=2;j<i;j++)//取出0-99之间的所有数字
		{
			if(i%j==0)
				break;
		}
		
		if(i==j)
		
			printf("%d\n",i);
		
	}
	return 0;
}
