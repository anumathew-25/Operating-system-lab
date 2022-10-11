#include<stdio.h>
int main(){
    int bt[10],p[10],wt[10],tt[10],i,j,n,total=0,pos,temp;
    float avgwt,avgtt;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the burst time:");
    for(i=0;i<n;i++){
        printf("Burst time of p[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    //for soring burst times
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos])
                pos=j;
            
        }
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
            
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
    }
        wt[0]=0;

        for(i=1;i<n;i++){
            wt[i]=0;
            for(j=0;j<i;j++)
                wt[i]+=bt[j];

                total+=wt[i];
            
        }
            avgwt=(float)total/n;
            total=0;
            printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround time\n");
            for(i=0;i<n;i++){
                tt[i]=bt[i]+wt[i];
                total+=tt[i];
                printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tt[i]);
            }
            avgtt=(float)total/n;
            printf("Average waiting time : %f",avgwt);
            printf("Average Turnaround Time: %f",avgtt);
        

}