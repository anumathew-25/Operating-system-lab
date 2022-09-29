/***************************
 * Author:Anu Mathew
 * file:cpuFCFS.c
 * description:C program to implement cpu scheduling algorithm-FCFS
 * date:29/09/2022
 ****************************/
#include<stdio.h>
int main(){
    int n,bt[10],wt[10],tt[10],i,j,avgwt=0,avgtt=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the burst time of each process:\n");
    for(i=0;i<n;i++){
        printf("process[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
    }    
        printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
        for(i=0;i<n;i++){
            tt[i]=bt[i]+wt[i];
            avgwt+=wt[i];
            avgtt+=tt[i];
            printf("P[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tt[i]);
        }
        avgwt/=i;
        avgtt/=i;
        printf("\nAverage waiting time:%d",avgwt);
        printf("\nAverage turnaround time: %d",avgtt);
        return 0;
    
}
