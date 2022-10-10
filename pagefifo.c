/*******************
 * Author:Anu Mathew
 * File:pagefifo.c
 * Description:C program to implement first in first out page replacement algorithm
 * Date:09/10/2022
 *****************/
#include<stdio.h>
int main(){
    int i,j,k,length,string[25],frame[10],no,available,count=0;
    printf("Enter the length of reference string: ");
    scanf("%d",&length);
    printf("Enter the reference string:\n");
    for(i=0;i<length;i++){
        scanf("%d",&string[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d",&no);
    for(i=0;i<no;i++){
        frame[i]=-1;
        j=0;
    }
        printf("ref string\tpage frames\n");
        for(i=0;i<length;i++){
            printf("%d\t\t",string[i]);
            available=0;
            for(k=0;k<no;k++)
                if(frame[k]==string[i])
                    available=1;
                    if(available==0){
                        frame[j]=string[i];
                        j=(j+1)%no;
                        count++;
                        for(k=0;k<no;k++){
                            printf("%d\t",frame[k]);
                        }
                    }
                    printf("\n\n");   
        }
    
    printf("\nPage fault:%d cylinders",count);
    return 0;
}