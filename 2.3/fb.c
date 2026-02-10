#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fb=0;

	fb=open("/dev/fb0",O_RDWR);
	if(fb<0)
	{
		perror("open()");
		return -1;
	}
	printf("fb=%d\n",fb);
	close(fb);
	return 0;
}
