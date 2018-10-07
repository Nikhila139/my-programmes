#include<stdio.h>
#include<stdlib.h>

int s1[50],s2[50],max=50,top1=-1,top2=-1;

void pushs1(int data);
int pops1();
void pushs2(int data);
int pops2();
void displays1();

void main()
{
	int x,n,i,j,k,a,b,t;
	printf("enter no. of elements");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pushs1(x);
	}
	for(i=0;i<n-1;i++)
	{
		a=pops1();
		for(j=0;j<n-i-1;j++)
		{
			b=pops1();
			if(a>b)
			{
				t=a;
				a=b;
				b=t;
			}
			pushs2(b);
		}
		pushs2(a);
		while((b=pops1())!=0)
		{
			pushs2(b);
		}
		for(j=0;j<n;j++)
		{
			b=pops2();
			pushs1(b);
		}
	}
	displays1();	
}

void pushs1(int data)
{
	if(top1==max-1)
	printf("stack overflow");
	else
	{
		top1++;
		s1[top1]=data;
	}
}

void pushs2(int data)
{
	if(top2==max-1)
	printf("stack overflow");
	else
	{
		top2++;
		s2[top2]=data;
	}
}

int pops1()
{
	int n;
	if(top1==-1)
	{
		return 0;
	}
	else
	{
		n=s1[top1];
		top1--;
		return n;
	}
}

int pops2()
{
	int n;
	if(top2==-1)
	{
		return 0;
	}
	else
	{
		n=s2[top2];
		top2--;
		return n;
	}
}

void displays1()
{
	int i;
	if(top1==-1)
	printf("stack underflow");
	else
	{
		for(i=top1;i>=0;i--)
		printf("%d\t",s1[i]);
		printf("\n");
	}
}

