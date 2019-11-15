#include<stdio.h>
int n,i,l2,at[20],bt[20],ct[20],tat[20],wt[20],q1[20],q2[20],btrem,l3,min,flag=0,f2,cpu,cpup=-1,r1=0,q,r2=0,mem,now=0,comp=0;
float awt=0,atat=0;
void fillarr(int l3)

{
	ct[q2[l3]]=cpu;
	tat[q2[l3]]=ct[q2[l3]]-at[q2[l3]];
	wt[q2[l3]]=tat[q2[l3]]-bt[q2[l3]];
	printf("p%d|",q2[l3]+1);
	comp++;	
}
void sjf(int bound)
{
	if(btrem!=0)
	{
		cpup=cpu;
		cpu+=btrem;
		fillarr(now);
		btrem=0;
		printf("p%d|",now);
		now=0;
	}
	f2=0;
	for(l2=now;l2<r2;l2++)
	{
		if(bound==cpu)
		break;
		else if(at[q2[l2]]<=cpu&&ct[q2[l2]]==0)
		{
			f2=1;flag=0;
			cpup=cpu;
			if(bound>cpu+bt[q2[l2]]||bound==0)
			{
				cpu+=bt[q2[l2]];
				fillarr(l2);
			}
			else
			{
				cpu=bound;
				btrem=bt[q2[l2]]-(cpu-cpup);
				printf("p%d|",q2[l2]+1);
				now=l2;
				break;
			}
		}
	}
	if(flag==0&&f2==0)
	{
		printf("idle|");
		cpu++;
		flag=1;
	}
}
void fcfs()
{
	for(i=0;i<r1;i++)
	{
		if(at[q1[i]]<=cpu)
		{
			cpu+=bt[q1[i]];
			ct[q1[i]]=cpu;
			tat[q1[i]]=ct[q1[i]]-at[q1[i]];
			wt[q1[i]]=tat[q1[i]]-bt[q1[i]];
			printf("p%d|",q1[i]+1);
			comp++;
		}
		else
		{
			sjf(at[q1[i]]);
			i--;
		}
	}
}
void main()
{
	printf("Enter the number of processes.\n");
	scanf("%d",&n);
//	printf("Enter queue 1 or 2, at, bt...\n");
	for(i=0;i<n;i++)
	{
		printf(" For Process %d\n",i+1);
		printf("enter queue number\n");
	  	scanf("%d",&q);
	  	if(q==1)
	  	q1[r1++]=i;
	  	else if(q==2)
	  	q2[r2++]=i;
		else
		{
			printf("Entered wrong q no. Enter again.\n");
			i--;
			continue;
		}
		printf("enter arrival time");
		scanf("%d",&at[i]);
		printf("enter burst time");
	  	scanf("%d",&bt[i]);
	  	ct[i]=0;
	}
	for(i=1;i<r1;i++)
	{
		mem=q1[i];
		for(l2=i-1;l2>=0;l2--)
		{
			if(at[q1[l2]]>at[mem])
				q1[l2+1]=q1[l2];
			else
				break;
		}
		q1[l2+1]=mem;
	}
	for(i=1;i<r2;i++)
	{
		mem=q2[i];
		for(l2=i-1;l2>=0;l2--)
		{
			if(bt[q2[l2]]>bt[mem])
				q2[l2+1]=q2[l2];
			else
				break;
		}
		q2[l2+1]=mem;
	}
	for(cpu=0;comp<n;)
	{
		fcfs();
		sjf(0);
	}
	printf("\np  at  bt  ct  tat  wt\n-------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d  %d  %d  %d  %d  %d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
		awt+=wt[i];
		atat+=tat[i];
	}
	awt/=n;
	atat/=n;
	printf("awt....%0.2f\n",awt);
	printf("atat....%0.2f",atat); 
}
