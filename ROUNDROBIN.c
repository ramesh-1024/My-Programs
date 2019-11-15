#include<stdio.h>
int a[10],n,b[10],p,c[10],d[10],sum=0,t=0,bt[10],tq,q[50],r=-1,f=-1,e[10],pid[10],i=0,j,k=0,temp;
float tat,wt;
int ready()
{
	    for(j=0;j<n;j++)
		{
			if(e[j]<=t)
			{
				q[++f]=pid[j];
				e[j]=9999999;
			}
		}
}
void main()
{
	printf("no of processes:\n");
	scanf("%d",&n);
	printf("\nenter arrival times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		e[i]=d[i]=a[i];
		pid[i]=i;
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<n-i;j++)
		{
			if(e[j]<e[j-1])
			{
				temp=e[j];
				e[j]=e[j-1];
				e[j-1]=temp;
				temp=pid[j];
				pid[j]=pid[j-1];
				pid[j-1]=temp;
			}
		}
	}
	printf("\nenter burst times:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		bt[i]=b[i];
	}
	printf("\nenter time quantum:\n");	
	scanf("%d",&tq);
	printf("Gantt chart:\n\n");
	while(k<n)                     
	{    
		ready();   
		if(r!=f)  
        {
		    p=q[++r];   
			if(b[p]>tq)
			{
				t+=tq;	
				b[p]-=tq;
				ready();
				q[++f]=p;
			}
			else
			{
				t+=b[p];
				b[p]=0;	
				k++;	
				c[p]=t;	
				a[p]=999;
			}
			printf("P%d\t",p+1);
		}
		else
		{
			t=e[k];
			printf("\n");
  			printf(" idle %d \t",t);
		}
	}
	printf("\nct\ttat\twt\t\n");
	for(i=0;i<n;i++)
	{
			printf("%d\t%d\t%d\n",c[i],c[i]-d[i],c[i]-d[i]-bt[i]);
			tat+=c[i]-d[i];
			wt+=c[i]-d[i]-bt[i];
	}
	printf("avg.tat= %f aavg.wt= %f ",tat/n,wt/n);
}
