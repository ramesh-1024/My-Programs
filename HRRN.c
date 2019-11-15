#include<stdio.h>
int main()
{
	int p[10],at[10],bt[10],ct[10],time=0,i,j,count=0,t,n,target=-1,wt[10],tat[10];
	float sum_wt=0,sum_tat=0,avg_tat,avg_wt;
	printf("enter the no.of processes\n");
	scanf("%d",&n);
	printf("enter the arrival times\n");
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		scanf("%d",&at[i]);
		ct[i]=-1;
	}
	printf("enter burst times\n");
	for(i=0;i<n;i++)
		scanf("%d",&bt[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n-1;j++)
		{
			if(at[j]>at[j+1])
			{
				t=at[j+1];
				at[j+1]=at[j];
				at[j]=t;

				t=bt[j+1];
				bt[j+1]=bt[j];
				bt[j]=t;
				
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;	
			}
		}
	}
	//time=ct[0]=at[0]+bt[0];
	//printf("P%d\t",p[0]);
	while(1)
	{
		target=-1;
		float high_res_ratio=0;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && ct[i]==-1)
			{	
				float val=(time-at[i]+bt[i])/bt[i];
				if(val>high_res_ratio)
				{
					high_res_ratio=val;
					target=i;
				}
			}
		}
	ct[target]=bt[target]+time;
	time=ct[target];
	count++;
	printf("P%d\t",p[target]);
	if(count==n)
	break;
	}
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		sum_tat+=tat[i];
		sum_wt+=wt[i];
	}
	printf("\npnum\tat\tbt\tct\ttat\twt");
	for(i=0;i<n;i++)
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	printf("average tat=%f\naverage wt=%f\n",(sum_tat/n),(sum_wt/n));
}

