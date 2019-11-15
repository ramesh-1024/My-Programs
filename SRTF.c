#include<stdio.h>
int main()
{
 	int at[10],bt[10],x[10],p[10],wt[10],tat[10],ct[10];
 	int i,j,min,count=0,time,n,flag=0;
	float avg_wt=0,avg_tat=0,end;
 	printf("\nEnter the number of Processes: ");
 	scanf("%d",&n);
 	for(i=0;i<n;i++)
  		 p[i]=i+1;
	for(i=0;i<n;i++)
	{
	   printf("\nEnter arrival time of process %d : ",i+1);
	   scanf("%d",&at[i]);
	}
	for(i=0;i<n;i++)
	{
	   printf("\nEnter burst time of process %d : ",i+1);
	   scanf("%d",&bt[i]);
	}
 	for(i=0;i<n;i++)
 		x[i]=bt[i];
	int condition=i;
  	bt[condition]=9999;

	for(time=0,flag=0;count!=n;time++)
	{
	  	min=condition;
		for(i=0;i<n;i++)
	   	{
	   		if(at[i]<=time && bt[i]<=bt[min] && bt[i]>0 )
	    			min=i;
	    			flag=1;
  		}
  		if(flag==0)
  		{
  			printf("\n%d\tidle\t%d",time,time+1);	
		} 
 	 	else
  	 	{
	  		bt[min]--;
	  		printf("\n%d\tP%d\t%d",time,p[min],time+1);
  		}
  		if(bt[min]==0)
  		{
  			count++;//counting incremented when one of the burst time =0 
   			ct[min] = time+1;
   			tat[min] = ct[min]-at[min];
   			wt[min]=tat[min]-x[min];
  		}
	}
 	printf("\npid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 	for(i=0;i<n;i++)
 	{
  		 printf("\n %d \t  %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],at[i],wt[i],tat[i],ct[i]);
   		avg_wt = avg_wt + wt[i];
   		avg_tat = avg_tat + tat[i];
 	}
 		printf("\n\nAverage waiting time = %f\n",avg_wt/n);
 		printf("\nAverage Turnaround time = %f",avg_tat/n);
return 0;
}
