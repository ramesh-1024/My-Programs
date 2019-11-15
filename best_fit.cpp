#include<stdio.h>
int main()
{
	int f[20],p[20],n,m,i,j,fit=0,inter_frag_waste=0,exter_frag_waste=0,blk_ind,flag=0,best;
	
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
	for(i=0;i<m;i++)//loop for processes
	{
		for(j=0;j<n;j++)//loop for blocks
		{
			if(p[i]==f[j]&&f[j]!=-1&&p[i]!=-1)
			{
				//inter_frag_waste+=f[j]-p[i]; no need
				f[j]=-1;
				p[i]=-1;//for process tht is alrdy done
				fit=1;//flag bit used to check whthr our process is been or in waiting state
				printf("process--%d-- fits in --%d--block\n",i+1,j+1);
				break;
			}
		}
		best=99999;
		flag=0;
		for(j=0;j<n;j++)//loop for blocks
		{
			if(f[j]<best && f[j]!=-1&&p[i]!=-1&&p[i]<f[j])
			{
				best=f[j];
				blk_ind=j;//finding the min. and best block of memry
				flag=1;//checking whether the proceess fits in best case
			}
		}
		if(flag==1)
		{
			inter_frag_waste+=f[blk_ind]-p[i];
			f[blk_ind]=-1;
			fit=1;
			printf("process--%d-- fits in --%d--block\n",i+1,blk_ind+1);
		}
		if(fit==0)
			printf("process--%d--is waiting\n",i+1);
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
