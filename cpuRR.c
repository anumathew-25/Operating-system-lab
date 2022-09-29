#include<stdio.h>
int main(){
    int i,x,limit,total=0,counter=0,timeQuantum;
    int wt=0,tt=0,at[10],bt[10],temp[10];
    float avgwt,avgtt;
    printf("Enter the total number of processes: ");
    scanf("%d",&limit);
    x=limit;
    for(i=0;i<limit;i++){
        printf("Enter the details of the process[%d]:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&at[i]);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        temp[i]=bt[i];
    }
    printf("\nEnter the time quantum:");
    scanf("%d",&timeQuantum);
    printf("\nProcess id \tBurst Time\tTurnaround Time\tWaiting time\n");
    for(total=0,i=0;x!=0;){
        if(temp[i]<=timeQuantum&&temp[i]>0){
            total=total+temp[i];
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-timeQuantum;
            total+=timeQuantum;
        }
        if(temp[i]==0 &&counter==1){
            x--;
            printf("\nP[%d]\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
            wt+=total-at[i]-bt[i];
            tt+=total-at[i];
            counter =0;
        }
        if(i==limit-1){
            i=0;
        }
        else if(at[i+1]<=total){
            i++;
        }
        else{
            i=0;
        }
    }
    avgwt=wt*1.0/limit;
    avgtt=tt*1.0/limit;
    printf("\nAverage waiting time:%f\n",avgwt);
    printf("Average turn around time: %f\n",avgtt);
    return 0;
}