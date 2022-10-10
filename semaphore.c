/*******************
 * Author:Anu Mathew
 * File:semaphore.c
 * Description:C program to implement producer consumer problem
 * Date:05/10/2022
 * ***************/
#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int full=0;
int empty=10,x=0;

void wait(int *S){
    while(*S<=0);
    (*S)--;
}
void signal(int *S){
    (*S)++;
}

void producer(){
    wait(&empty);
    wait(&mutex);
    x++;
    printf("\nProducer produces item %d",x);
    signal(&full);
    signal(&mutex);
}
void consumer(){
    wait(&full);
    wait(&mutex);
    signal(&empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    signal(&empty);
    signal(&mutex);
}
int main(){
    int option,i;
    for(i=1;i>0;i++){
        printf("\n1.producer\n2.consumer\n3.exit\nEnter your option:");
        scanf("%d",&option);
        switch(option){
            case 1:if((mutex==1)&&empty!=0){
                producer();
            }
            else{
                printf("Buffer is full\n");
            }
            break;

            case 2:if((mutex==1)&&(full!=0)){
                consumer();
            }
            else{
                printf("Buffer is empty\n");
            }
            break;
            
            case 3:exit(0);
            break;

            default:
            printf("Enter a valid option\n");
            break;
        }
    }
    
}