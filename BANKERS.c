#include<stdio.h>
int main()
{
	int allocation[30][30],max[30][30],need[30][30],avl[30],n,n1,i,j,finish[10],flag=0;
	printf("ente the no. of process and resourses\n");
	scanf("%d",&n);
	scanf("%d",&n1);
	printf("enter the available resourses:\n");
	for(i=0;i<n1;i++)
	{
     	scanf("%d",&avl[i]);
   }
   for(i=0;i<n;i++)
	{
     	finish[i]=0;
    }
    printf("enter the allocation matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n1;j++)
		{
		
     	scanf("%d",&allocation[i][j]);
     }
     printf("\n");
   }
   printf("enter the max matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n1;j++)
		{
		
     	scanf("%d",&max[i][j]);
     }
     printf("\n");
   }
    printf("need matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n1;j++)
		{
		  need[i][j]=max[i][j]-allocation[i][j];
     	 printf("%d\t",need[i][j]);
      }
      printf("\n");
   }
   int h1=0,count=0,r=0,k=0,h[10];
   while(h1<n)
   {
   	  for(i=0;i<n;i++)
	 {
	 	count=0;
	   	for(j=0;j<n1;j++)
	   	{
	   	     if((need[i][j]<=avl[j])&&finish[i]==0)
	   	     {
	   	     	count++;
			}	
		}
		if(count==n1&&finish[i]==0)
     	{
     	   h[k]=i;
     	   k++;
     	   r=0;
     	  while(r<n1)
     	  {
     	   avl[r]=avl[r]+allocation[i][r];
     	   finish[i]=1;
			r++;	
		  }	
          }	
        }
        h1++;
  }
  printf("safe state is:\n");
  j=0;
  while(j<k)
  {
  	printf("%d\t",h[j]);
  	j++;
  }
}
  
