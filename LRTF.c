#include<stdio.h>
int main()
{
 	int at[10],bt[10],x[10],p[10],wt[10],tat[10],ct[10];
 	int i,j,min,count=0,time,n;
	float avg_tat=0,avg_wt=0;
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
  	bt[condition]=-9999;
 //printf("time => process number");
 int flag=0;
	for(time=0;count!=n;time++)
	{
	  	min=condition;;
	  	flag=0;
		for(i=0;i<n;i++)
	   	{
	   		if(at[i]<=time && bt[i]>bt[min] && bt[i]>0 )
	    			min=i;
	    			flag=1;
   			//printf("min:%d\n",min);
  		}
  		if(flag==0)
  		{
  			printf("\n%d\tidle\t%d",time,time+1);	
		} 
 	 	else
  	 	{
	  		bt[min]--;
	  		printf("\n%d\tP%d\t%d",time,p[min],time+1);
	  		//printf("\n%d => p%d",time+1,min);
  		}
  		if(bt[min]==0)
  		{
  			count++;//counting incremented when one of the burst time =0  
   			ct[min] = time+1;
   			tat[min] = ct[min]-at[min];
   			wt[min]=tat[min]-x[min];
  		}
	}
 	printf("\n pid \t at \t bt \t ct \t tat \t wt");
 	for(i=0;i<n;i++)
 	{
  		 printf("\n %d \t  %d \t %d \t %d  \t %d \t%d",p[i],at[i],x[i],ct[i],tat[i],wt[i]);
   		avg_wt = avg_wt + wt[i];
   		avg_tat = avg_tat + tat[i];
 	}
 		printf("\n\nAverage waiting time = %f\n",avg_wt/n);
 		printf("\nAverage Turnaround time = %f",avg_tat/n);
return 0;
}
