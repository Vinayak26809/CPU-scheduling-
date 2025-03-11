// CPU-Scheduling-Algorithm-In-C
// First come First served scheduling (FCFS) (Non - Preemptive)  

#include<stdio.h>

/* in this we have two choice one is use the array for a process 
or
use the "Malloc" in that we don't have to given the size of the array before */


/*  Malloc function
    int n,i, *bt,*wt,*tat;

        printf("Enter the number of processes: ");
        scanf("%d",&n);

    bt = (int*) malloc(n*sizeof(int));
    wt = (int*) malloc(n*sizeof(int));
    tat = (int*) malloc(n*sizeof(int));

    In this how many number of processes will be there according to that only the process will be allocated the memory to the program y  
*/

int main()
{
    int pid[10],bt[10],wt[10],i,n,tat[10];
    float avg_tat=0.0 , avg_wt=0.0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("\n Enter the Burst Time for each processes: \n");

    for(i=0;i<n;i++)
    {
        printf("The Burst time for Pid %d : ",i);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;
    tat[0]= bt[0];

    for(i=1;i<n;i++)
    {
        wt[i]= wt[i-1]+bt[i-1]; // waiting time[pid] =waiting time[pid-1]+Burt time[pid-1]
        tat[i]=wt[i]+bt[i];     // turn around time = Waiting time + Burst time
    }

    for(i=0;i<n;i++)
    {
        avg_wt+= wt[i];
        avg_tat+= tat[i];
    }
    avg_wt=avg_wt/n;
    avg_tat=avg_tat/n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    printf("\n ----------------------------------------------------\n");

    for(i=0;i<n;i++)
    {
        printf("Pid%d \t\t %d\t\t %d\t\t %d \n",i,bt[i],wt[i],tat[i]);
    }

    printf("The Average Waiting Time : %f",avg_wt);
    printf("The Average TurnAround Time : %f",avg_tat);


    // to print the gantt chart 
    printf("\n GANTT Chart \n");
    printf("----------------\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t || PID %d\t || %d \n ", wt[i],i,tat[i]);
    }

    return 0;
}