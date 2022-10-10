/*******************
 * Author:Anu Mathew
 * File:bankers.c
 * Description:C program to implement banker's algorithm
 * Date:05/10/2022
 * ***************/
#include<stdio.h>
int main(){
    int max[10][10],need[10][10],alloc[10][10],avail[10],completed[10],safe[10];
    int p,r,i,j,process,count=0;
    printf("Enter the number of processes: ");
    scanf("%d",&p);
    for(i=0;i<p;i++){
        completed[i]=0;
    }
    printf("Enter the number of resources: ");
    scanf("%d",&r);

    printf("Enter the Max matrix for each process: \n");
    for(i=0;i<p;i++){
        printf("Process %d:\n",i+1);
        for(j=0;j<r;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the allocation matrix of each of the process:\n");
    for(i=0;i<p;i++){
        printf("process %d:\n",i+1);
        for(j=0;j<r;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the available resources: \n");
    for(i=0;i<r;i++){
        scanf("%d",&avail[i]);
    }
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    do{
        printf("\nmax matrix: \talloc matrix:\n");
        for(i=0;i<p;i++){
            for(j=0;j<r;j++){
                printf("%d ",max[i][j]);
            }
            printf("\t\t");
            for(j=0;j<r;j++){
                printf("%d ",alloc[i][j]);
            }
            printf("\n");
        }
        process=-1;
        for(i=0;i<p;i++){
            if(completed[i]==0){
                process=i;
                for(j=0;j<r;j++){
                    if(avail[j]<need[i][j]){
                        process=-1;
                        break;
                    }
                }
            }
            if(process !=-1){
                break;
            }
        }
        if(process!=-1){
            printf("\nProcess%d runs to completion",process+1);
            safe[count]=process+1;
            count++;
            for(j=0;j<r;j++){
                avail[j]+=alloc[process][j];
                alloc[process][j]=0;
                max[process][j]=0;
                completed[process]=1;
            }
        }
    }
    while(count!=p &&process !=-1);
    if(count==p){
        printf("\nThe system is in safe state\n");
        printf("Safe sequence:< ");
        for(i=0;i<p;i++){
            printf("P%d ",safe[i]);
        }
        printf(">\n");
    }
    else{
        printf("\nThe system is in unsafe state");
    }
    
return 0;
}