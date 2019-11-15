#include<stdio.h>
int main()
{
 	int at[10],bt[10],x[10],p[10],wt[10],tat[10],ct[10],pr[10];
 	int i,j,max,count=0,time,n,flag=0;
	float avg=0,tt=0,end;
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
	{
	   printf("\nEnter  priority of process %d : ",i+1);
	   scanf("%d",&pr[i]);
	}
 	for(i=0;i<n;i++)
 		x[i]=bt[i];
	int condition=i;
  	pr[condition]=9999;
 //printf("time => process number");
 int flag=0;
	for(time=0;count!=n;time++)
	{
	  	max=condition;
	  	flag=0;
		for(i=0;i<n;i++)
	   	{
	   		if(at[i]<=time && pr[i]<pr[max] && bt[i]>0 )
	    			max=i;
	    			flag=1;
   			
  		}
  		if(flag==0)
  		{
  			printf("\n%d\tidle\t%d",time,time+1);	
		} 
 	 	else
  	 	{
	  		bt[max]--;
	  		printf("\n%d\tP%d\t%d",time,p[max],time+1);
	  		//printf("\n%d => p%d",time+1,max);
  		}
  		if(bt[max]==0)
  		{
  			count++;//counting incremented when one of the burst time =0 
   			end=time+1;//completion time for each 
   			ct[max] = end;
   			tat[max] = ct[max]-at[max];
   			wt[max]=tat[max]-x[max];
  		}
	}
 	printf("\npid \t burst \t arrival \twaiting \tturnaround \tcompletion");
 	for(i=0;i<n;i++)
 	{
  		 printf("\n %d \t  %d \t %d\t\t%d   \t\t%d\t\t%d",i+1,x[i],at[i],wt[i],tat[i],ct[i]);
   		avg = avg + wt[i];
   		tt = tt + tat[i];
 	}
 		printf("\n\nAverage waiting time = %f\n",avg/n);
 		printf("\nAverage Turnaround time = %f",tt/n);
return 0;
}
