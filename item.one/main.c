#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "work.h"
#include "Food.h"
#include <unistd.h>
#include<math.h>

#define BG_BLUE_SOFT "\033[48;5;30m"   // 淡蓝背景
#define FG_WHITE "\033[38;5;255m"       // 纯白字体
#define BG_CYAN_LIGHT "\033[48;5;188m"  // 浅青背景
#define RESET "\033[0m"

// 终端基础控制码
#define RESET "\033[0m"
#define HIDE_CURSOR "\033[?25l"
#define SHOW_CURSOR "\033[?25h"
#define CLEAR_SCREEN "\033[2J"
#define CURSOR_POS "\033[%d;%dH"
#define CURSOR_HOME "\033[H"

// 烟花配色
#define COLOR_B1 "\033[38;5;39m"   // 极浅蓝
#define COLOR_B2 "\033[38;5;69m"   // 天蓝
#define COLOR_P1 "\033[38;5;141m"  // 浅紫
#define COLOR_P2 "\033[38;5;129m"  // 深紫
const char* colors[] = {COLOR_B1, COLOR_B2, COLOR_P1, COLOR_P2};
#define COLOR_CNT 4


// ========== 全屏+弯曲线条关键参数 ==========
#define CENTER_Y 15               // 垂直全屏中心
#define CENTER_X 40               // 水平全屏中心
#define MAX_RADIUS 70             // 全屏扩散半径
#define LINE_NUM 32               // 32条弯曲线条（铺满全屏）
#define ROT_SPEED 1               // 旋转步长
#define SPEED 25000               // 动画速度
#define MAX_X 500                 // 终端最大宽度
#define MAX_Y 250                 // 终端最大高度
#define CURVE_FACTOR 0.5         // 线条弯曲系数（越大越弯，0.15是自然烟花弧度）

// ===================== 通用清屏函数 =====================
void clear_screen() {
	printf("%s%s", CLEAR_SCREEN, CURSOR_HOME);
	fflush(stdout);
}



// ===================== 弯曲线条烟花动画函数 =====================
void spin_anim(int diffuse) {
	printf("%s%s%s", HIDE_CURSOR, CLEAR_SCREEN, CURSOR_HOME);
	fflush(stdout);

	int radius = diffuse ? 1 : MAX_RADIUS;
	int angle = 0;

	// 主循环：扩散到全屏/汇聚到中心
	while ((diffuse && radius <= MAX_RADIUS) || (!diffuse && radius >= 1)) {
		clear_screen();

		// 绘制32条弯曲的烟花放射线条
		for (int line = 0; line < LINE_NUM; line++) {
			// 基础角度（均分360°）
			int base_angle = angle + (line * 360 / LINE_NUM);
			double base_rad = base_angle * M_PI / 180.0;

			// 绘制单条弯曲线条的粒子链
			for (int step = 1; step <= radius; step++) {
				// 弯曲轨迹计算（核心：添加弧度偏移，模拟烟花弧线）
				double curve_rad = base_rad + (step * CURVE_FACTOR * M_PI / 180.0);
				// 极坐标转直角坐标（带弯曲偏移）
				int x = CENTER_X + step * cos(curve_rad);
				int y = CENTER_Y + step * sin(curve_rad) + (step * step * 0.002); // 二次曲线，更自然

				// 全屏粒子显示范围
				if (x > 0 && x < MAX_X && y > 0 && y < MAX_Y) {
					int color_idx = (step * (COLOR_CNT - 1)) / radius;
					if (color_idx >= COLOR_CNT) color_idx = COLOR_CNT - 1;
					const char* color = colors[color_idx];

					printf(CURSOR_POS, y, x);
					printf("%s.%s", color, RESET);
				}
			}
		}

		fflush(stdout);
		usleep(SPEED);

		// 更新旋转角度和半径
		angle += ROT_SPEED;
		if (angle >= 360) angle = 0;
		radius += diffuse ? 1 : -1;
	}

	// 退出动画收尾
	if (!diffuse) {
		clear_screen();
		printf(CURSOR_POS, CENTER_Y, CENTER_X);
		printf("%s●%s", COLOR_P2, RESET);
		fflush(stdout);
		usleep(500000);

		printf(CURSOR_POS, CENTER_Y + 3, CENTER_X - 6);
		printf("%s程序退出中...%s", COLOR_P1, RESET);
		fflush(stdout);
		usleep(1000000);
	}

	// 恢复终端状态
	clear_screen();
	printf("%s", SHOW_CURSOR);
	fflush(stdout);
}






void pay(QUEUE *q)
{int i=0;
	float num =0;
	float sum = 0;
	struct MENU save;//用来出队结账

	for(i =0;i<10;i++)
	{
		num = de_queue(q,&save);
		sum = sum + num;
	}
	queue_display(q);
	printf("\033[10;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[11;54H %s %s ||                          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[12;54H %s %s ||                          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[13;54H %s %s ||                          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[14;54H %s %s ||   应付款金额: %.2f     %s\n",BG_BLUE_SOFT,FG_WHITE,sum,RESET);
	printf("\033[15;54H %s %s ||                          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[16;54H %s %s ||                          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	printf("\033[17;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
	show_prcode();
}




void kehu(LLIST *handler,QUEUE *q)//进入客户功能
{
	system("clear");//清屏
	int mode = 0;
	int i=1;

	while(i){

		printf("\033[10;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[11;54H %s %s ||  1.查看菜单              ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[12;54H %s %s ||  2.点餐                  ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[13;54H %s %s ||  3.结账                  ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[14;54H %s %s ||  4.退出客户界面          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[15;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[16;54H %s %s选择功能:                      %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);

		scanf("%d",&mode);
		system("clear");
		switch(mode)
		{
			case 1:menu_display(handler);getchar();getchar();break;
			case 2:Order(q,handler);break;
			case 3:pay(q);while(getchar()!='\n');getchar();while(getchar()!='\n');break;
			case 4:--i;break;
			default :printf("\033[16;54H %s %s重新选择功能:                      %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);break;
		}

		system("clear");
	}
}

void shangjia(LLIST *handler,struct MENU *data)//进入商家功能
{
	system("clear");//清屏
	int mode = 0;
	int i=1;
	char find_name[20]={0} ;

	while(i){   
		printf("\033[10;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[11;54H %s %s ||  1.查看菜单              ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[12;54H %s %s ||  2.添加菜品              ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[13;54H %s %s ||  3.修改菜品              ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[14;54H %s %s ||  4.根据菜名查找菜品      ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[15;54H %s %s ||  5.退出商家界面          ||%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[16;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[17;54H %s %s选择功能:                      %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		scanf("%d",&mode);
		if(!(mode>=1&&mode<=5))
		{printf("请重新输入");
			continue;
		}
		system("clear");//清屏
		switch(mode)
		{
			case 1:menu_display(handler);getchar();getchar()/*scanf("%d",&mode)*/;break;
			case 2:getchar();cai_insert(handler,data);break;
			case 3:cai_change(handler);break;
			case 4:printf("请输入查找菜品\n");scanf("%s",find_name);while(getchar()!='\n');menu_find_by_name(handler,find_name);printf("请按回车继续\n");while(getchar()!='\n');break;
			case 5:--i;break;
			default :printf("\033[16;54H %s %s重新选择功能:                      %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);break;
		}
		system("clear");
	}
}

int main(void)
{
	int shenfen =0;//选择身份
	int i =1;//循环变量

	spin_anim(1); // 启动：弯曲线条烟花炸开
				  //客户的头节点
	QUEUE *q =NULL;
	q=queue_create();
	if(q == NULL)
	{
		fprintf(stderr, "queue_create() Is Failed!\n");
		return -1;                                      
	}


	//商家的头节点
	struct MENU data; // 存储录入的菜品
	LLIST *handler = NULL;

	handler = menu_crate(sizeof(struct MENU)); // 创建头结点
	if (handler == NULL)
	{
		fprintf(stderr, "llist_create() Is Failed!\n");
		return -1;
	}



	while(i)
	{	
		system("clear");//清屏	
		printf("\n");
		printf("\033[10;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[11;54H %s %s ||  选择您的身份          ||  %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[12;54H %s %s ||  如果您商家请输入：1   ||  %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[13;54H %s %s ||  如果您客户请输入：2   ||  %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[14;54H %s %s ||  退出程序请输入：3     ||  %s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		printf("\033[15;54H %s %s===============================%s\n",BG_BLUE_SOFT,FG_WHITE,RESET);
		scanf("%d",&shenfen);
		switch(shenfen)
		{
			case 1:shangjia(handler,&data);break;
			case 2:kehu(handler,q);break;
			case 3:--i;break;
			default :printf("输入错误，请重新输入!\n");break;		  
		}
	}	
	spin_anim(0); // 退出：弯曲线条烟花回笼
	return 0;
}

