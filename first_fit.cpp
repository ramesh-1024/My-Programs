#include<stdio.h>
int main()
{
	int f[20],p[20],n,m,i,j,fit=0,inter_frag_waste=0,exter_frag_waste=0;
	
	printf("enter the no.of blocks to be present in memory:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter memory size of block--%d\n",i+1);
		scanf("%d",&f[i]);
	}
	printf("enter no.of processes:\n");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter mem.size of process--%d\n",i+1);
		scanf("%d",&p[i]);
	}
	for(j=0;j<m;j++)//loop for processes
	{
		for(i=0;i<n;i++)//loop for blocks
		{
			if(p[j]<=f[i] && f[i]!=-1)
			{
				printf("Process--%d--fitted in block--%d--\n",j+1,i+1);
				inter_frag_waste+=f[i]-p[j];
				f[i]=-1;
				fit=1;
				break;	
			}
		}
		if(fit!=1)
			printf("process--%d--is waiting\n",j+1);
		else
			fit=0;
	}
	for(j=0;j<n;j++)
	{
		if(f[j]!=-1)
		{
			exter_frag_waste+=f[j];
		}
	}
	printf("Total memory wasted by internal fragmentation==%d\n",inter_frag_waste);
	printf("Total memory wasted by external fragmentation==%d\n",exter_frag_waste);}
