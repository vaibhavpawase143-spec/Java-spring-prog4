#include <stdio.h>

int main() {
    // Fixed values for demonstration purposes
    int n = 3;
    int at[10] = {0, 1, 2};  // Arrival times
    int bt[10] = {5, 3, 2};  // Burst times
    int wt[10], tat[10], ct[10], i;
    float totaltat = 0, totalwt = 0;

    // Calculate completion time of processes
    int currentTime = at[0]; // Start with the arrival time of the first process
    for(i = 0; i < n; i++) {
        if (currentTime < at[i]) {
            currentTime = at[i]; // Wait for the process to arrive
        }
        ct[i] = currentTime + bt[i]; // Completion time is current time + burst time
        currentTime = ct[i]; // Update current time to the end of this process
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        totaltat += tat[i];
    }

    // Calculate Waiting Time
    for(i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        totalwt += wt[i];
    }

    // Print results
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);
    printf("Average Waiting Time: %.2f\n", totalwt / n);

    return 0;
}
