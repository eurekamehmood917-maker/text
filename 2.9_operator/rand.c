#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
	//srand(time(NULL));
	srand(getpid());
	int i=0;
	int n=0;
	for(i=0;i<10;i++)
	{
	//n=rand()%100;
	n=rand()%900+100;
	printf("%d\n",n);
	}
	return 0;
}
