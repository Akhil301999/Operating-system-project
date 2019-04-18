#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<time.h> 
#include<conio.h>
#define Marrival_timeX 32767  


void delay(double number_of_seconds) 
{
    double milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
}

struct process
{
	int arrival_time;  // arrival time     
	int burst_time;    // burst time    
	int pid;           // process id     
	int queue;         // queue it belongs     
	int completion_time;  // completion time   
	int w;
	int t;
	int temp_b;
};

void printScenario(struct process p[],int len)
{
	printf("\n\n--------------------------------------------------------------------------------------------------------------------------- \n");
	printf("    |  Process    |    Arrival Time    |   Burst Time  |      Completion Time     |     Waiting Time     |   Turn-Around Time \n");
	printf("    -------------------------------------------------------------------------------------------------------------------------- \n");
	for(int i=0;i<len;i++)
	{
		printf("        P%d                 %d                   %d               %d                       %d                      %d\n",p[i].pid,p[i].arrival_time,p[i].temp_b,p[i].completion_time,p[i].w,p[i].t);
	}
} 

void printQueue(int a[],int n)
{
	printf(" Queue 2 : \n");
	for(int i=0;i<n;i++)
	printf(" %d",a[i]);
	printf("\n");
}

int main()
{
	int n;
	int MAX;
	double wait_time = 0, turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;
	printf("\n\n\n\n -----------  | Question 10 : Multilevel Queue : SRTF [Pre-emptive] +  Round Robin (Time Quantum = 2 Units) |  -----------\n\n");
	printf("\n | Enter the number of processes  | :  ");
	scanf("%d",&n);
	struct process p[n+1];
	for(int i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("\n | Enter The Arrival Time of Process P%d  | :  ",i+1);
		scanf("%d",&p[i].arrival_time);
		printf("\n | Enter The Burst Time of Process P%d  | : ",i+1);
		scanf("%d",&p[i].burst_time);
		if(i%2==0)
		p[i].queue=1;
		else
		p[i].queue=2;
		p[i].completion_time=0;
		p[i].t=0;
		p[i].temp_b=p[i].burst_time;
	}	
	p[n].burst_time=MAX;
	system("cls");
	//delay(0.5);
	printf("\n\nProcessing");
	//delay(0.5);
	printf(".");
	//delay(0.5);
	printf(".");
	//delay(0.5);
	printf(".");
	
	int q2[n/2];
	int kq=0;
	for(int i=1;i<n;i+=2)
	{
		q2[kq++]=i;
	} 
	int time=0;int count=0;
	int min=n;int run=-1;
	int cc=0;
	while(count != n)
	{
		min = n;
		for(int i=0;i<n;i++)
		{
			if(p[i].arrival_time <= time)
			{
				if(p[i].queue == 1 && p[i].burst_time>0)
				{
					// queue 1 : SRTF Pre-emptive
					if(p[i].burst_time < p[min].burst_time)
					{
						min = i;
						run = min;
					}
				}
			}
		}
		if(min == n) // No queue 1
		{
			for(int i=0;i<n/2;i++)
			{
				if(p[q2[i]].burst_time==0)
				continue;
				run = q2[i];
				// shifting;
				for(int j=i+1;j<n/2;j++)
				{
					q2[j-1]=q2[j];
				}
				q2[(n/2)-1]=run;
				break;
			}
		}
		p[run].burst_time--;
		if(p[run].burst_time == 0)
		{
		 	count++;
		 	p[run].completion_time = time + 1;
            wait_time = wait_time + p[run].completion_time - p[run].arrival_time - p[run].temp_b;
            turnaround_time = turnaround_time + p[run].completion_time - p[run].arrival_time;
		}
		time++;
	}
    for(int i=0;i<n;i++)
    {
    	p[i].w = p[i].completion_time - (p[i].arrival_time + p[i].temp_b);
    	p[i].t = p[i].completion_time - (p[i].arrival_time);
	}
    average_waiting_time = wait_time / n; 
    average_turnaround_time = turnaround_time / n;
    printScenario(p,n);
    printf("\n\n     --- | Average Waiting Time | : ---\t| %lf |\n", average_waiting_time);
    printf("\n     --- | Average Turn-Around Time | : ---\t| %lf |\n", average_turnaround_time);
    getch();
}
