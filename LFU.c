#include<stdio.h>
int indexof(int *a,int size,int n)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==n)
		return i;
	}
}
void main()
{
	int n,f,time,j,i,min,index,flag1,flag2,hit=0,fault=0;
	scanf("%d %d",&n,&f);
	int frame[f],str[n],ts[f],count[10];
	for(i=0;i<n;i++)
	scanf("%d",&str[i]);
	for(i=0;i<f;i++)
	frame[i]=-1;
	for(i=0;i<10;i++)
	count[i]=0;
	for(i=0;i<n;i++)
	{
		flag1=0;
		flag2=0;
		for(j=0;j<f;j++)
		{
			if(frame[j]==-1)
			{
				fault++;
				frame[j]=str[i];
				ts[j]=i;
				count[str[i]]++;
				flag1=1;
				break;
			}
			else if(frame[j]==str[i])
			{
				hit++;
				count[str[i]]++;
				flag2=1;
				break;
			}
		}
		if(flag1==1 || flag2==1)
		continue;
		min=99999;
		for(j=0;j<f;j++)
		{
			if(count[frame[j]]<min)
			{
				min=count[frame[j]];
				index=j;
			}
			else if(count[frame[j]]==min)
			{
				if(ts[indexof(frame,f,frame[j])]<ts[indexof(frame,f,frame[index])])
				{
					index=j;
				}
			}
		}
		fault++;
		frame[index]=str[i];
			printf("%d\n",frame[index]);
		ts[index]=i;
		count[str[i]]++;
		for(j=0;j<f;j++){
			printf("%d\n",frame[j]);
		}
	}
	printf("hits=%d and faults=%d\n",hit,fault);
}

