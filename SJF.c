#include<stdio.h>

int main()
{
	int p[10],at[10],bt[10],ct[10],tat[10],wt[10],bt2[10],n,i,min,flag,count,time=0,condition;
	float avg_tat=0,avg_wt=0;
	
	printf("enter no.of processes:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		p[i]=i+1;
	
	for(i=0;i<n;i++)
	{
		printf("enter arrival times & burst times of P%d\n",i+1);
		scanf("%d",&at[i]);
		scanf("%d",&bt[i]);
		bt2[i]=bt[i];
	}
	condition=i;
	bt[condition]=99999;
	printf("\nGantt Chart:\t");
	
	for(count=0,flag=0;count!=n;count++)
	{
		min=condition;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]<=bt[min] &&bt[i]>0)
			{	
				min=i;
				flag=1;
			}	
		}
		if(flag==1)
		{
			ct[min]=time+bt[min];
			printf("%d-P%d-%d|",time,p[min],ct[min]);
			tat[min]=ct[min]-at[min];
			wt[min]=tat[min]-bt[min];
			avg_tat+=tat[min];
			avg_wt+=wt[min];
			bt[min]=0;
			time=ct[min];
		}
		else
		{
			count--;
			printf("%d-idle-%d|",time,time+1);
			time++;
		}
	}
	printf("\nP.Num\t at\t bt\t ct\t tat\t wt\t");	
	for(i=0;i<n;i++)
		printf("\n%d\t %d\t %d\t %d\t %d\t %d\t",p[i],at[i],bt2[i],ct[i],tat[i],wt[i]);
	printf("\nAverage tat=%.3f \n Average wt=%.3f",avg_tat/n,avg_wt/n);
	
}
