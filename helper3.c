#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX_PROCESS 50

typedef struct
{
    char *name;
    int arrival;
    int cpuburst;
    int turnaround;
    int wait;
      int finish;
} Process;
int p = 0;

Process processtable[MAX_PROCESS];
void clearProcessTable()
{
    int i = 0;
    for (i = 0; i < p; i++)
    {
        processtable[i].arrival = 0;
        processtable[i].cpuburst = 0;
        processtable[i].name = 0;
        processtable[i].turnaround = 0;
        processtable[i].wait = 0;
    }
}

void ReadProcessTable(char *filename)
{
    p = 0;
    FILE *ptr;
    ptr = fopen(filename, "r");
    if (ptr == NULL)
    {
        printf("\nCan not open file");
        exit(1);
    }

    int completion_time = 0;
    char str[50];
    while (fgets(str, 30, ptr) != NULL)
    {

        char *ch;
        ch = strtok(str, " ");
        int choice = 1;

        while (ch != NULL)
        {
            switch (choice)
            {
            case 1:
            {
                processtable[p].name = malloc(2 * sizeof(char));
                strcpy(processtable[p].name, ch);
                choice++;
                ch = strtok(NULL, " ");
                break;
            }
            case 2:
            {
                processtable[p].arrival = ((int)*ch - 48);
                choice++;
                ch = strtok(NULL, " ");
                break;
            }
            case 3:
            {

                processtable[p].cpuburst = ((int)*ch - 48);
                choice++;
                ch = strtok(NULL, " ");
                break;
            }
            }
        }
        p++;
    }
}

void PrintProcessTable()
{
    printf("\n\nPrinting process table :");
    int i;
    for (i = 0; i < p; i++)
    {
        printf("\n");
        printf("%s ", processtable[i].name);
        printf("%d ", processtable[i].arrival);
        printf("%d ", processtable[i].cpuburst);
    }
}

void FCFS()
{
    int current_time = 0;
    int completion_time = 0;
    int i, j;
    int min;
    printf("\n\nFCFS running :");
    for (i = 0; i < p; i++)
    {
        min = i;
        for (j = i + 1; j < p; j++)
        {
            // if (processtable[i].arrival == processtable[j].arrival)
            // {

            //     if (processtable[j].cpuburst < processtable[min].cpuburst)
            //     {
            //         Process p = processtable[j];
            //         processtable[j] = processtable[min];
            //         processtable[min] = p;
            //     }
            // }

            if (processtable[j].arrival < processtable[min].arrival)
            {
                Process p = processtable[j];
                processtable[j] = processtable[min];
                processtable[min] = p;
            }
        }

        if (i == 0)
        {
            completion_time = processtable[i].arrival + processtable[i].cpuburst;
            processtable[i].turnaround = completion_time - processtable[i].arrival;
            processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
            printf("\n[%d - %d]       %s     running :", processtable[i].arrival, completion_time, processtable[i].name);
            current_time = completion_time;
            continue;
        }
        if (i > 0 && processtable[i].arrival <= current_time)
        {
            completion_time = current_time + processtable[i].cpuburst;
            processtable[i].turnaround = completion_time - processtable[i].arrival;
            processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
            printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[i].name);
            current_time = completion_time;
        }
        else
        {

            completion_time = processtable[i].arrival + processtable[i].cpuburst;
            processtable[i].turnaround = completion_time - processtable[i].arrival;
            processtable[i].wait = processtable[i].turnaround - processtable[i].cpuburst;
            printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[i].name);
            current_time = completion_time;
        }
    }
    float sum_turn = 0;
    float sum_wait = 0;
    printf("\n\nTurnaround times : ");
    for (i = 0; i < p; i++)
    {
        printf("%s[%d]  ", processtable[i].name, processtable[i].turnaround);
        sum_turn += processtable[i].turnaround;
    }

    printf("\n\nWaiting times    : ");
    for (i = 0; i < p; i++)
    {
        printf("%s[%d]  ", processtable[i].name, processtable[i].wait);
        sum_wait += processtable[i].wait;
    }

    printf("\n\nAverage turnaround time : %f", sum_turn / p);
    printf("\nAverage wait time       : %f", sum_wait / p);
}
void PrintStatistics()
{
    printf("\n\nProcess Statistics:");
    int i;
    for (i = 0; i < p; i++)
    {
        printf("\n");
        printf("%s ", processtable[i].name);
        printf("%d ", processtable[i].arrival);
        printf("%d ", processtable[i].cpuburst);
        printf("%d ", processtable[i].turnaround);
        printf("%d ", processtable[i].wait);
    }
}

void sort(int *a, int *b, int n)
{
    int k, j, key1, key2;
    for (int i = 0; i < n; i++)
    {
        j = i - 1;
        k = i - 1;
        key1 = a[i];
        key2 = b[i];
        while (j >= 0 && key1 < a[j])
        {
            a[j + 1] = a[j];
            b[k + 1] = b[k];
            j--;
            k--;
        }
        a[j + 1] = key1;
        b[k + 1] = key2;
    }
}

void roundrobin(Process processes[], int no_of_processes)
{

    int *at = (int *)malloc(no_of_processes * sizeof(int));
    int *bt = (int *)malloc(no_of_processes * sizeof(int));
    int *bt1 = (int *)malloc(no_of_processes * sizeof(int));
    int *ct = (int *)malloc(no_of_processes * sizeof(int));
    int index, tq, c, r = 0, f = 0;
    int rq[100][2];

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < no_of_processes; i++)
    {
        at[i] = processes[i].arrival;
        bt[i] = processes[i].cpuburst;
        bt1[i] = bt[i];
    }
    printf("\n");

    sort(at, bt, no_of_processes);

    for (int i = 0; i < no_of_processes; i++)
        bt1[i] = bt[i];

    for (int j = 0; j < no_of_processes; j++)
    {
        printf("%d %d\n", at[j], bt[j]);
    }
    printf("\n");

    if (bt[0] > tq)
    {
        c = at[0] + tq;
        bt[0] = bt[0] - tq;
        ct[0] = c;
        rq[r][0] = c;
        rq[r][1] = 0;
        r++;
    }
    else
    {
        c = at[0] + bt[0];
        ct[0] = c;
    }
    int i = 1;
    while (i < no_of_processes)
    {
        if (r != 0 && at[i] <= rq[f][0])
        { //
            if (bt[i] > tq)
            {
                c = c + tq;
                ct[i] = c;
                bt[i] = bt[i] - tq;
                rq[r][0] = c;
                rq[r][1] = i;
                r++;
            }
            else
            {
                c = c + bt[i];
                ct[i] = c;
            }
            i++;
        }
        else if (r == 0)
        {
            if (bt[i] > tq)
            {
                c = c + tq;
                bt[i] = bt[i] - tq;
                rq[r][0] = ct[i];
                rq[r][1] = i;
                r++;
            }
            else
            {
                c = c + bt[i];
                ct[i] = c;
            }
            i++;
        }
        else
        {
            index = rq[f][1];
            f++;
            if (bt[index] > tq)
            {
                c = c + tq;
                ct[index] = c;
                bt[index] = bt[index] - tq;
                rq[r][0] = ct[index];
                rq[r][1] = index;
                r++;
            }
            else
            {
                c = c + bt[index];
                ct[index] = c;
            }
        }
    }
    while (f < r)
    {
        index = rq[f][1];
        f++;
        if (bt[index] > tq)
        {
            c = c + tq;
            ct[index] = c;
            bt[index] = bt[index] - tq;
            rq[r][0] = ct[index];
            rq[r][1] = index;
            r++;
        }
        else
        {
            c = c + bt[index];
            ct[index] = c;
        }
    }

    int *turnaround = (int *)malloc(no_of_processes * sizeof(int));
    for (int i = 0; i < no_of_processes; i++)
    {
        processes[i].finish = ct[i];
        if ((ct[i] - at[i]) <= 0)
        {
            turnaround[i] = 0;
        }
        else
        {
            turnaround[i] = ct[i] - at[i];
        }
        processes[i].turnaround = turnaround[i];
        // turnaround[i]=maximum(0, ct[i]-at[i]);
    }

    int *wait = (int *)malloc(no_of_processes * sizeof(int));
    for (int i = 0; i < no_of_processes; i++)
    {
        if ((turnaround[i] - bt1[i]) <= 0)
        {
            wait[i] = 0;
        }
        else
        {
            wait[i] = turnaround[i] - bt1[i];
        }
        processes[i].wait = wait[i];
    }
    PrintStatistics1(processes, no_of_processes);
    printf("\n");
}

void selection_sort(Process processtable[])
{
    int i = 0;
    int j = 0;
    int min = 0;
    for (i = 0; i < p; i++)
    {
        min = i;
        for (j = i + 1; j < p; j++)
        {
            if (processtable[j].cpuburst < processtable[min].cpuburst)
            {
                Process p = processtable[j];
                processtable[j] = processtable[min];
                processtable[min] = p;
            }
        }
        // printf("%d ",processtable[i].cpuburst);
    }
}

void SRBF()
{
    static int current_time = 0;
    static int completion_time = 0;

    int i = 0;
    int j = 0;
    int k = 0;
    int min = 0;

    int c_arrival[p];
    for (i = 0; i < p; i++)
    {
        c_arrival[i] = processtable[i].arrival;
    }

    for (i = 0; i < p; i++)
    {
        min = i;
        for (j = i + 1; j < p; j++)
        {
            if (c_arrival[j] < c_arrival[min])
            {
                int p = c_arrival[j];
                c_arrival[j] = c_arrival[min];
                c_arrival[min] = p;
            }
        }
    }

    current_time = processtable[0].arrival;

    while (1)
    {
        int count = 0;
        int flag=0;
        selection_sort(processtable);

        for (i = 0; i < p; i++)
        {
            if (processtable[i].cpuburst == 99999)
            {
                count++;
            }
        }
        if (count == p)
        {
            break;
        }

        if (processtable[0].cpuburst == 0)
        {
            processtable[0].cpuburst = 99999;
            continue;
        }
        int arrival = processtable[0].arrival;

        int carrival = 0;
        for (i = 0; i < p; i++)
        {
            if (processtable[i].arrival < arrival && processtable[i].cpuburst != 99999)
            {
                for (j = 0; j < p; j++)
                {
                    if (processtable[i].arrival == c_arrival[j])
                    {
                        carrival = c_arrival[j];
                        break;
                    }
                }
                int end = current_time + processtable[i].cpuburst;
                if (end <= c_arrival[j + 1])
                {
                    if (end == c_arrival[j + 1])
                    {
                        completion_time = end;
                        processtable[i].cpuburst = 0;
                        if (processtable[i].arrival < current_time)
                        {
                            printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[i].name);
                        }
                        if (processtable[i].arrival == current_time)
                        {
                            printf("\n[%d - %d]       %s     running :", processtable[i].arrival, completion_time, processtable[i].name);
                        }
                        current_time = completion_time;
                        flag=1;
                    }
                    if (end < c_arrival[j + 1])
                    {
                        completion_time = current_time + processtable[i].cpuburst;
                        processtable[i].cpuburst = 0;
                        if (processtable[i].arrival < current_time)
                        {
                            printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[i].name);
                        }
                        if (processtable[i].arrival == current_time)
                        {
                            printf("\n[%d - %d]       %s     running :", processtable[i].arrival, completion_time, processtable[i].name);
                        }
                        current_time = c_arrival[j + 1];
                        flag=1;
                        
                    }
                }
                if (end > c_arrival[j + 1])
                {
                    for (k = 0; k < p; k++)
                    {
                        if (processtable[k].arrival == c_arrival[j + 1])
                        {
                            int rem=processtable[i].cpuburst-c_arrival[j+1];
                            if (processtable[k].cpuburst < rem)
                            {
                                processtable[i].cpuburst=rem;
                                completion_time =c_arrival[j + 1];
                                if (processtable[i].arrival < current_time)
                                {
                                    printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[i].name);
                                }
                                if (processtable[i].arrival == current_time)
                                {
                                    printf("\n[%d - %d]       %s     running :", processtable[i].arrival, completion_time, processtable[i].name);
                                }
                                current_time = completion_time;
                                flag=1;
                                break;
                            }else{
                                
                            }
                        }
                    }
                }
            }
        }

        if (processtable[0].cpuburst != 99999 )
        {
            completion_time = current_time + processtable[0].cpuburst;
            processtable[0].cpuburst = 0;
            if (processtable[0].arrival < current_time)
            {
                printf("\n[%d - %d]       %s     running :", current_time, completion_time, processtable[0].name);
            }
            if (processtable[i].arrival == current_time)
            {
                printf("\n[%d - %d]       %s     running :", processtable[0].arrival, completion_time, processtable[0].name);
            }
            current_time = completion_time;
        }
    }
}
int main(int argc, char *argv[])
{
    /* code */

    if (argc == 1)
    {
        printf("\n file(txt) is not passed :\n");
        exit(0);
    }

    if (argc == 2)
    {
        int terminate = 1;

        while (terminate == 1)
        {
            int choice = 0;
            printf("\nCPU Scheduling Simulation");
            printf("\nSelect the scheduling algorithm [1,2,3 or 4]:");
            printf("\n1. First Come First Served (FCFS)");
            printf("\n2. Round Robin (RR)");
            printf("\n3. SRBF");
            printf("\n4. Exit");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
            {
                ReadProcessTable(argv[1]);
                PrintProcessTable();
                FCFS();
                PrintStatistics();

                break;
            }
            case 2:
            {
                clearProcessTable();
                ReadProcessTable(argv[1]);
                PrintProcessTable();
                int n = 0;
                roundrobin(n);
                PrintStatistics();

                break;
            }
            case 3:
            {
                clearProcessTable();
                ReadProcessTable(argv[1]);
                PrintProcessTable();
                SRBF();
                PrintStatistics();

                break;
            }
            case 4:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("\nplease provide correct information");
                break;
            }
            }

            printf("\n\npress any key to continue...");

            getch();
        }
    }

    return 0;
}
