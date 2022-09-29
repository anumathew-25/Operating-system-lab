/***************************
 * Author:Anu Mathew
 * file:cpuPriority.c
 * description:C program to implement cpu scheduling algorithm-priority scheduling
 * date:29/09/2022
 ****************************/
#include<stdio.h>
int main(){
    int bt[10],p[10],wt[10],tt[10],pr[10],i,j,n,total=0,pos,temp,avgwt,avgtt;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the burst time and priority of each process: \n");
    for(i=0;i<n;i++){
        printf("Burst time of p[%d]: ",i+1);
        scanf("%d",&bt[i]);
        printf("Priority of P[%d]:",i+1);
        scanf("%d",&pr[i]);
        p[i]=i+1;
    }
    //sorting
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos])
            pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

    }
    wt[0]=0;
    for(i=0;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        total+=wt[i];
        }
        avgwt=total/n;
        total=0;
        printf("Process\tBurst time\tWaiting time\tTurnaround time\n");
        for(i=0;i<n;i++){
            tt[i]=bt[i]+wt[i];
            total+=tt[i];
            printf("P[%d]\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tt[i]);
        }
        avgtt=total/n;
        printf("\nAverage waiting time: %d",avgwt);
        printf("\nAverage turnaround time: %d",avgtt);
        return 0;
}