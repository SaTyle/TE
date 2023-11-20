#include<stdio.h>

int main() {
    int cnt, j, n, t, remain, flag = 0, tq;
    int wt = 0, tat = 0, at[10], bt[10], rt[10]; // Variables for waiting time, turnaround time, arrival time, burst time, remaining time

    // Input total number of processes
    printf("Enter Total Number of Processes:\t ");
    scanf("%d", &n);
    remain = n;

    // Input arrival time and burst time for each process
    for (cnt = 0; cnt < n; cnt++) {
        printf("Enter Arrival Time and Burst Time for Process Number %d: ", cnt + 1);
        scanf("%d", &at[cnt]);
        scanf("%d", &bt[cnt]);
        rt[cnt] = bt[cnt]; // Remaining time initially equals burst time
    }

    // Input time quantum for Round Robin scheduling
    printf("Enter Time Quantum:\t");
    scanf("%d", &tq);

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

    // Perform Round Robin scheduling
    for (t = 0, cnt = 0; remain != 0;) {
        if (rt[cnt] <= tq && rt[cnt] > 0) {
            t += rt[cnt];
            rt[cnt] = 0;
            flag = 1;
        } else if (rt[cnt] > 0) {
            rt[cnt] -= tq;
            t += tq;
        }

        // Calculate waiting time and turnaround time for each process
        if (rt[cnt] == 0 && flag == 1) {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", cnt + 1, t - at[cnt], t - at[cnt] - bt[cnt]);
            wt += t - at[cnt] - bt[cnt];
            tat += t - at[cnt];
            flag = 0;
        }

        // Move to the next process in a circular manner
        if (cnt == n - 1)
            cnt = 0;
        else if (at[cnt + 1] <= t)
            cnt++;
        else
            cnt = 0;
    }

    // Calculate and display average waiting time and average turnaround time
    printf("\nAverage Waiting Time= %f\n", wt * 1.0 / n);
    printf("Avg Turnaround Time = %f", tat * 1.0 / n);

    return 0;
}
