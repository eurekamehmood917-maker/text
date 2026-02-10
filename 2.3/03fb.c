#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/fb.h>
#include<sys/mman.h>

int main(void)
{
	int fb=0;
	int ret=0;
	struct fb_var_screeninfo var;
	unsigned char*pc=NULL;
	unsigned int *pi=NULL;
	int color=0;

	srand(getpid());

	fb=open("/dev/fb0",O_RDWR);
	if(fb<0)
	{
		perror("open()");
		return -1;

	}

	ret=ioctl(fb,FBIOGET_VSCREENINFO,&var);
	if(ret<0)
	{
		perror("ioctl90");
		close(fb);
		return -2;

	}

	pc=mmap(0,var.xres*var.yres*var.bits_per_pixel>>3,)
}
