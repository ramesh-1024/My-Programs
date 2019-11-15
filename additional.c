#include<stdio.h>
void main()
{
	int n,f,time,j,i,min,index,flag1,flag2,fault=0,hit=0;
	scanf("%d %d",&n,&f);
	int frame[f],str[n],ts[f],bit[f];
	for(i=0;i<n;i++)
	scanf("%d",&str[i]);
	for(i=0;i<f;i++)
	frame[i]=-1;
	printf("\n");
	for(i=0;i<f;i++)
	{
		frame[i]=-1;
		bit[i]=0;
	}
	for(i=0;i<n;i++)
	{
		flag1=0;
		flag2=0;
		if(str[i]==-1)
		{
			for(j=0;j<f;j++)
			bit[j]=bit[j]>>1;
			continue;
		}
		for(j=0;j<f;j++)
		{
			if(frame[j]==-1)
			{
				frame[j]=str[i];
				bit[j]=8;
				flag1=1;
				ts[j]=i;
				fault++;
				break;
			}
			else if(frame[j]==str[i])
			{
				bit[j]=bit[j] | 8;
				hit++;
				flag2=1;
				break;
			}
		}
		if(flag1==1 || flag2==1)
		{
			continue;
		}
		min=9999;
		for(j=0;j<f;j++)
		{
			if(bit[j]<min)
			{
				min=bit[j];
				index=j;
			}
			else if(bit[j]==min)
			{
				if(ts[j]<ts[index])
				index=j;
			}
		}
		frame[index]=str[i];
		ts[index]=i;
		fault++;
		for(j=0;j<f;j++)
		printf("%d	",frame[j]);
		printf("\n");
	}
	printf("Page Faults: %d\nPage Hits: %d",fault,hit);
}











