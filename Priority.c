// CPU-Scheduling-Algorithm-In-C
// Priority scheduling(Priority) (Preemptive)  

#include<stdio.h>


/* in this we have two choice one is use the array for a process 
or
use the "Malloc" in that we don't have to given the size of the array before */


/*  Malloc function

    #include<malloc.h>
    
    int n,i,j,pos,temp,*bt,*wt,*tat,*p;

        printf("Enter the number of processes: ");
        scanf("%d",&n);

    p = (int*)malloc(n*sizeof(int));
    bt = (int*) malloc(n*sizeof(int));
    wt = (int*) malloc(n*sizeof(int));
    tat = (int*) malloc(n*sizeof(int));

    In this how many number of processes will be there according to that only the process will be allocated the memory to the program y  
*/

int main()
{
    int n,i,j,pos,temp,bt[10],wt[10],tat[10],p[10],pt[10];
    float avg_wt=0.0,avg_tat=0.0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\n Enter the Brust Time and Priority Time for each process: \n");
    for(i=0;i<n;i++)
    {
        printf("The Burst time of Pid %d : ",i);
        scanf("%d",&bt[i]);
        printf("THe Priority Time of Pid %d : ",i);
        scanf("%d",&pt[i]);
        p[i]=i;
    }

    for(i=0;i<n;i++)
    {
        pos = i;
        for(j=i-1;j<n;j++)
        {
            if(pt[j] < pt[pos])
            {
                pos = j;
            }
        }

        temp =pt[i];
        pt[i] =pt[pos];
        pt[pos] = temp;

        temp = bt[i] ;
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp =p[i];
        p[i] = p[pos];
        p[pos] = temp;

    }

    wt[0] = 0;
    tat[0] =bt[0];

    for(i=1;i<n;i++)
    {
        wt[i] =wt[i-1] +bt[i-1];  // waiting time[p] = waiting time[p-1] + burst time[p-1]
        tat[i] = wt[i] +bt[i];   // waiting time = waiting time + burst time
    }

    for(i=0;i<n;i++)
    {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;

    printf("\n\nProcess\t\tPriority Time\tBrust Time\tWaiting Time\tTurnaround Time\n");
    printf("-----------------------------------------------------------------------\n");

    for(i=0;i<n;i++)
    {
        printf("p%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i],pt[i],bt[i],wt[i],tat[i]);
    }

    printf("\n\nAverage Waiting Time = %f\n", avg_wt);
    printf("Average Turnaround Time = %f\n", avg_tat);

    // this line of code is for gantt chart

    printf("\nGANTT CHART \n");
    printf("-----------------\n");

    for(i=0;i<n;i++)
    {
        printf("%d \t || P%d \t || %d \n ", wt[i] , p[i], tat[i]);
    }

    return 0;
}