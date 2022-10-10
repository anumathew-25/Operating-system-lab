/*******************
 * Author:Anu Mathew
 * File:diskCsacn.c
 * Description:C program to implement C-Scan disk scheduling algorithm
 * Date:10/10/2022
 *****************/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int request[10],i,j,reqNo,totalHeadMovement=0,initial,size,move,temp,index;
    printf("Enter the number of Requests: ");
    scanf("%d",&reqNo);
    printf("Enter the request sequence :\n");
    for(i=0;i<reqNo;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&initial);
    printf("Enter the total head size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction (for high 1 and for low 0): ");
    scanf("%d",&move);

    //for c-scan disk scheduling
    //to sort the request array
    for(i=0;i<reqNo;i++){
        for(j=0;j<reqNo-i-1;j++){
            if (request[j]>request[j+1]){
                temp=request[j];
                request[j]=request[j+1];
                request[j+1]=temp;
            }
            
        }
    }
    for(i=0;i<reqNo;i++){
        if(initial<request[i]){
            index=i;
            break;
        }
    }
    //if move towards high value
    if(move==1){
        for(i=index;i<reqNo;i++){
            totalHeadMovement+=abs(request[i]-initial);
            initial=request[i];
        }
        //last movement for max size
        totalHeadMovement+=abs(size-request[i-1]-1);
        //movement to max to min disk
        totalHeadMovement+=abs(size-1-0);
        initial=0;
        for(i=0;i<index;i++){
            totalHeadMovement+=abs(request[i]-initial);
            initial=request[i];
        }
    }
    //if move towards low
    else{
        for(i=index-1;i>=0;i--){
            totalHeadMovement+=abs(request[i]-initial);
            initial=request[i];
        }
        //last movement for min size
        totalHeadMovement+=abs(request[i+1]-0);
        //movement from min to max disk
        totalHeadMovement+=abs(size-1-0);
        initial=size-1;
        for(i=reqNo-1;i>=index;i--){
            totalHeadMovement+=abs(request[i]-initial);
            initial=request[i];
        }
    }
    printf("Total head movement: %d cylinders",totalHeadMovement);
    return 0;
}

