#include<stdio.h>
int main()
{
  int a[20],n,i,head,sum=0,start,end,j,d;
  printf("enter number of  blocks\n");
  scanf("%d",&n);
  printf("enter the header value\n");
  scanf("%d",&head);
  printf("enter\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
  	for(j=i+1;j<n;j++)
    {
  	  if(a[i]>a[j])
  	  {
  	  	int temp=a[j];
  	  	    a[j]=a[i];
  	  	    a[i]=temp;
		}
    }
  }
  for(i=0;i<n;i++)
  {
  	 if(head<a[i])
  	  break;
  }
  j=i;
  while(j<n)
  {
     if(a[j]>=head)
      {
        d=a[j]-head;
        sum=sum+d;
      }
     head=a[j];
     j++;
  }
  d=199-head;
  //head=199;
  sum=sum+d+199;
  head=0;
  d=a[i-1]-head;
  sum=sum+d;
 printf("the head moves:%d",sum);
}
