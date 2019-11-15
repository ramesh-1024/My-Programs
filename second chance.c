#include<stdio.h>

int f1,n,r[25],rb[6]={0,0,0,0,0,0},f[6]={-1,-1,-1,-1,-1,-1},i,j,k,ptr=0,f=0;

int fun()
{
	if(rb[ptr]==0)
	return ptr;
	else
	{
		rb[ptr]=0;
		ptr=(ptr+1)%f1;
		fun();	
	}
}

void main()
{
	printf("enter no of framess\n");
	sanf("%d",&f1);
	printf("ref string len & string");
	scanf("%d",&n);
	for(i=0;i<n;s())
}
