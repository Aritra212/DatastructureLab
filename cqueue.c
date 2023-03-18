#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int queue[MAX], front= -1, rear= -1, item;

void insert(){
    if(front==(rear+1)%MAX)
        printf("\nQueue is full");
    else{
        printf("\nEnter item:: ");
        scanf("%d",&item);
        if(front==-1 && rear== -1)
            front= rear= 0;
        else
            rear= (rear+1)%MAX;
        queue[rear]=item;
        printf("\n%d inserted.",queue[rear]);
    }
}
void dequeue(){
    if(front==-1)
        printf("\nQueue is empty");
    else{
        item= queue[front];
        queue[front]=NULL;
        if(front == rear){
        	front=-1;
		rear=-1;
	   }
	   else
        	front= (front+1)%MAX;
        printf("%d deleted.",item);
    }

}
void display(){
    int i=front,c;
    if(front== -1 && rear== -1)
        printf("\nQueue is empty");
    else{
        printf("\nQueue is : ");
        while(i!=rear){
            if(queue[i]==NULL){
                c=0;
            }
            else{
                printf("%d ",queue[i]);
                i= (i+1)%MAX;
                c++;
            }
        }
        if(c==0){
            printf("\nQueue is empty");
        }
        else{
            printf("%d",queue[rear]);
        }
    }
}

int main(){
    int n;
    while(1){
        printf("\n-------------------------------------\n");
        printf("\nEnter '1' to insert element.");
        printf("\nEnter '2' to delete element.");
        printf("\nEnter '3' to display element.");
        printf("\nEnter '0' to  exit.");
        printf("\nEnter your choice:: ");
        scanf("%d",&n);

        switch(n){
            case 1: insert();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 0: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}
