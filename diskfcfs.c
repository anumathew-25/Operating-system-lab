/*******************
 * Author:Anu Mathew
 * File:diskfcfs.c
 * Description:C program to implement first come first serve disk scheduing algorithm
 * Date:09/10/2022
 *****************/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int request[10],i,reqNo,totalHeadMovement=0,initial;
    printf("Enter the number of requests: ");
    scanf("%d",&reqNo);
    printf("Enter the request sequence:\n");
    for(i=0;i<reqNo;i++){
        scanf("%d",&request[i]);
    }
    printf("Enter the initial head positon: ");
    scanf("%d",&initial);
    for(i=0;i<reqNo;i++){
        totalHeadMovement+=abs(request[i]-initial);
        initial=request[i];
    }
    printf("Total head movement: %d cylinders",totalHeadMovement);
    return 0;
}