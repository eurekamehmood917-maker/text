#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<linux/fb.h>
int main(void)

{
	int fb=0;
	int ret=0;
	struct fb_var_screeninfo var;
	fb=open("/dev/fb0",O_RDWR);
	if(fb<0)
		{
			perror("open()");
			return -1;

		}
	ret=ioctl(fb,FBIOGET_VSCREENINFO,&var);
	if(ret<0)
	{
		perror("ioctl()");
		close(fb);
		return -2;

	}

	printf("%d X %d\n",var.xres,var.bits_per_pixel);
	close(fb);
	return 0;


}

