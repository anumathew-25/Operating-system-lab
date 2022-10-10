/*******************
 * Author:Anu Mathew
 * File:pagelfu.c
 * Description:C program to implement least fequently used page replacement algorithm
 * Date:09/10/2022
 *****************/
#include<stdio.h>
int main(){
    int i,j,k,n,page[20],no,frame[10],move=0,flag,count=0,count1[10]={0},repindex,leastcount;
    printf("Enter the number of pages:");
    scanf("%d",&n);
    printf("Enter the refrence string:\n");
    for(i=0;i<n;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d",&no);
    for(i=0;i<no;i++)
    frame[i]=-1;
    printf("Reference string\tFrames\n");
    for(i=0;i<n;i++){
        printf("%d\t\t\t",page[i]);
        flag=0;
        for(j=0;j<no;j++){
            if(page[i]==frame[j]){
                flag=1;
                count1[j]++;
                printf("\n");
                break;
            }
        }
        if(flag==0&&count<no){
            frame[move]=page[i];
            count1[move]=1;
            move=(move+1)%no;
            count++;
            for(j=0;j<no;j++){
                printf("%d\t",frame[j]);
                //printf("\n");
            }
            printf("\n");
        }
        else if(flag==0){
            repindex=0;
            leastcount=count1[0];
            for(j=1;j<no;j++){
                if(count1[j]<leastcount){
                    repindex=j;
                    leastcount=count1[j];
                }
            }
            frame[repindex]=page[i];
            count1[repindex]=1;
            count++;
            for(j=0;j<no;j++){
                printf("%d\t",frame[j]);
                //printf("\n");
            }
            printf("\n");
        }
    }
    printf("Page fault:%d cylinders",count);
    return 0;
}