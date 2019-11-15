#include<stdio.h>
int main()
{
	int head,a[30],i,j,n,d,sum=0;
	printf("enter the number of requests\n");
	scanf("%d",&n);
	printf("enter the header value\n");
	scanf("%d",&head);
	printf("enter the requests\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	i=0;
	while(i<n)
	{
		d=abs(head-a[i]);
		sum=sum+d;
		head=a[i];
		
		i++;
	}
	printf("number of head moves are%d",sum);
}
