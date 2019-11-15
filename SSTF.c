#include<stdio.h>
int main()
{
	int sum=0,a[30],head,i,j,n,d,p,min,visit[10];
	printf("enter the number of requests\n");
	scanf("%d",&n);
	printf("enter the header value\n");
	scanf("%d",&head);
	printf("enter the requests\n");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	visit[i]=0;
   }
while(1)
{
	min=999;
	for(i=0;i<n;i++)
	{
		if(abs(head-a[i])<min && visit[i]==0)
		{
			min=abs(head-a[i]);
			p=i;
		}
	}
	if(min==999)
	  break;
	visit[p]=1;
	sum=sum+min;
	head=a[p];
}
	printf("head moves are%d",sum);
}
