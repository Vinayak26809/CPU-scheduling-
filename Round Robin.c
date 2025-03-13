// CPU-Scheduling-Algorithm-In-C
// Round Robin scheduling (RR) (Preemptive)  

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
    int n, i, tempn, count, terminaltime=0, initialtime, qt, flag=0, bt[10], wt[10], tat[10], tempbt[10];
    float avgwt = 0, avgtat = 0;
    printf("\n Enter the number of processes : ");
    scanf("%d", &n);
    tempn = n;

    
    printf("\n Enter the Quantum Time : ");
    scanf("%d", &qt);
    printf("\n Enter the burst time for each process \n\n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time of P%d : ", i);
        scanf("%d", &bt[i]);
        tempbt[i] = bt[i];
        terminaltime += bt[i];
    }

    wt[0] = 0;
    printf("\n GAANT CHART \n");
    printf("\n-------------\n");
    
    for(terminaltime=0, count=0; tempn!=0;) {
        initialtime = terminaltime;
        if(tempbt[count] <= qt && tempbt[count] > 0) {
            terminaltime += tempbt[count];
            tempbt[count] = 0;
            wt[count] = terminaltime - bt[count];
            tat[count] = wt[count] + bt[count];
            flag = 1;
        }
        else if(tempbt[count] > qt) {
            tempbt[count] -= qt;
            terminaltime += qt;
        }
        if(tempbt[count] == 0 && flag == 1) {
            tempn--;
            flag=0;
        }
        if(initialtime != terminaltime) {
            printf(" %d\t|| P%d ||\t%d\n", initialtime, count, terminaltime);
        }
        if(count == n-1)
            count = 0;
        else
            ++count;
    }

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", i, bt[i], wt[i], tat[i]);
    }

    for(i=0; i<n; i++) {
        avgwt += wt[i];
        avgtat += tat[i]; 
    }
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    return 0;
}