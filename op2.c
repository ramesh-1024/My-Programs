#include<stdio.h>
int distance(int *frame,int size,int n,int ptr)
{
	int i,dist;
	for(dist=0,i=ptr;i<size;i++,dist++)
	{
		if(frame[i]==n)
		return dist;
	}
	return 9999;
}
int maxindex(int *dist,int *entry,int n)
{
	int i,index=0;
	for(i=0;i<n;i++)
	{
		if(dist[index]<dist[i])
		index=i;
		else if(dist[index]==dist[i])
		{
			if(entry[index]>entry[i])
			index=i;
		}
	}
	return index;
}
void main()
{
	int n,f,i,j,flag,index,ts,hit=0,fault=0;
	printf("no. of pages: ");
	scanf("%d",&n);
	printf("give the string");
	int ref[n];
	for(i=0;i<n;i++)
	scanf("%d",&ref[i]);
	printf("no. of frames: ");
	scanf("%d",&f);
	int frame[f],dist[f],entry[f];
	for(i=0;i<f;i++)
	{
		frame[i]=-1;
		dist[i]=0;
		entry[i]=-1;
	}
	for(i=0,ts=0;i<n;i++,ts++)
	{
		flag=0;
		index=-1;
		for(j=0;j<f;j++)
		{
			if(frame[j]==ref[i])
			{
				flag=2;
				index=j;
				break;
			}
			if(frame[j]==-1)
			{
				flag=1;
				index=j;
				break;
			}
		}
		if(flag==2)
		hit++;
		else if(flag==1)
		{
			fault++;
			frame[index]=ref[i];
			entry[index]=ts;
		}
		else
		{
			fault++;
			for(j=0;j<f;j++)
			{
				dist[j]=distance(ref,n,frame[j],i);
			}
			index=maxindex(dist,entry,f);
			frame[index]=ref[i];
			entry[index]=ts;
		}
		for(j=0;j<f;j++)
		printf("%d\t",frame[j]);
		printf("\n\n");
	}
	printf("page faults:	%d\npage hits:	%d",fault,hit);
}






