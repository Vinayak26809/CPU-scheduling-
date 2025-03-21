
#include <stdio.h>
#define MAX_Processes 10
#define MAX_Resources 10

int allocation[MAX_Processes][MAX_Resources];
int request[MAX_Processes][MAX_Resources];
int available[MAX_Resources];
int resources[MAX_Resources];
int work[MAX_Resources];
int marked[MAX_Processes];

int main()
{
    int num_proc, num_res;

    printf("Enter the number of processes: ");
    scanf("%d", &num_proc);

    printf("Enter the number of resources: ");
    scanf("%d", &num_res);

    // Input total resources
    for (int i = 0; i < num_res; i++)
    {
        printf("Enter the total amount of Resource R%d: ", i + 1);
        scanf("%d", &resources[i]);
    }

    // Input request matrix
    printf("Enter the request matrix:\n");
    for (int i = 0; i < num_proc; i++)
    {
        for (int j = 0; j < num_res; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // User Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < num_proc; i++)
    {
        for (int j = 0; j < num_res; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Initialization of the available resources
    for (int j = 0; j < num_res; j++)
    {
        available[j] = resources[j];
        for (int i = 0; i < num_proc; i++)
        {
            available[j] -= allocation[i][j];
        }
    }

    // Mark processes with zero allocation
    for (int i = 0; i < num_proc; i++)
    {
        int count = 0;
        for (int j = 0; j < num_res; j++)
        {
            if (allocation[i][j] == 0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == num_res)
        {
            marked[i] = 1;
        }
    }

    // Initialize work with available
    for (int j = 0; j < num_res; j++)
    {
        work[j] = available[j];
    }

    // Mark processes with requests <= work
    for (int i = 0; i < num_proc; i++)
    {
        int can_be_processed = 1;
        if (marked[i] != 1)
        {
            for (int j = 0; j < num_res; j++)
            {
                if (request[i][j] > work[j])
                {
                    can_be_processed = 0;
                    break;
                }
            }
            if (can_be_processed)
            {
                marked[i] = 1;
                for (int j = 0; j < num_res; j++)
                {
                    work[j] += allocation[i][j];
                }
            }
        }
    }

    // Check for unmarked processes (deadlock)
    int deadlock = 0;
    for (int i = 0; i < num_proc; i++)
    {
        if (marked[i] != 1)
        {
            deadlock = 1;
            break;
        }
    }

    if (deadlock)
    {
        printf("Deadlock detected\n");
    }
    else
    {
        printf("No deadlock possible\n");
    }

    return 0;
}