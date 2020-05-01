#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void brick(int,int,int);
void ball(int,int);
void display(int,int,int,int);
int value=0,l;
void main()
{
	int gd=DETECT,gm;
	int x,y,j,dx,dy;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	x=getmaxx();
	y=getmaxy()/2;
	printf("%d %d",x,y);
	dx=40;
	dy=y+43;
	display(x-30,y,dx,dy);
	j=x-30;
	l=(rand()%(3-1+1))+1;
	do
	{
		if(j==0)
		{
			j=x-30;
			l=(l%3)+1;
		}
		if(kbhit()&&getch()==' ')
			value=1;
		else
			value=0;
		if(value==1)
		{
			while(dy>=y-33)
			{
				dy=dy-2;
				display(j,y,dx,dy);
				j--;
			}
			while(dy<=y+43)
			{
				dy=dy+2;
				display(j,y,dx,dy);
				j--;
			}
			value=0;
		}
		else
		{
			display(j,y,dx,dy);
			j--;
		}
	}while(dx+5!=j-30 && dy>=y-32);
	outtextxy(getmaxx()/2,getmaxy()/2,"Game Over");
	getch();
	closegraph();
}
void brick(int i,int x,int y)
{
	if(i==1)
	{
		rectangle(x-15,y-8,x,y);
		setfillstyle(1,4);
		floodfill(x-15+1,y-8+1,15);
		rectangle(x-15,y-16,x,y-8);
		floodfill(x-15+1,y-16+1,15);
		rectangle(x-15,y-24,x,y-16);
		floodfill(x-15+1,y-24+1,15);
		brick(3,x-15,y);
	}
	else if(i==2)
	{
		setfillstyle(1,4);
		rectangle(x-15,y-8,x,y);
		floodfill(x-15+1,y-8+1,15);
		rectangle(x-15,y-16,x,y-8);
		floodfill(x-15+1,y-16+1,15);
		brick(3,x-15,y);
	}
	else if(i==3)
	{
		setfillstyle(1,4);
		rectangle(x-15,y-8,x,y);
		floodfill(x-15+1,y-8+1,15);
		rectangle(x-15,y-16,x,y-8);
		floodfill(x-15+1,y-16+1,15);
		rectangle(x-15,y-24,x,y-16);
		floodfill(x-15+1,y-24+1,15);
		rectangle(x-15,y-32,x,y-24);
		floodfill(x-15+1,y-32+1,15);
	}
}
void display(int x,int y,int dx,int dy)
{
	int k,y1,x1;
	for(k=30;k<=getmaxx()-30;k++)
	{
		y1=(rand()%(51-49+1))+49;
		putpixel(k,y+y1,7);
	}
	ball(dx,dy);
	brick(l,x,y+50);
	delay(10);
	cleardevice();
}
void ball(int x,int y)
{
	setfillstyle(1,5);
	circle(x,y,5);
	floodfill(x,y,15);
}