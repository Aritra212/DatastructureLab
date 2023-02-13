// Queue Implementation using Array

#include<stdio.h>
#include<stdlib.h>

#define M 5
int queue[M],front=-1,rear=-1;

void Enqueue();
void Dequeue();
void Display();

int main(){
    int n;
    while(1){
        printf("\n-----------------------------------------\n");
        printf("\nEnter '1' to Enqueue");
        printf("\nEnter '2' to Dequeue");
        printf("\nEnter '3' to Display");
        printf("\nEnter '0' to exit");
        printf("\nEnter Your Choice:: ");
        scanf("%d",&n);

        switch(n){
            case 1: Enqueue();
            break;
            case 2: Dequeue();
            break;
            case 3: Display();
            break;
            case 0: exit(0);
            default: printf("\nInvalid Choice!!");
        }
    }
}

void Enqueue(){
    if(rear==M-1){
        printf("\nQueue is Full Dequeue some data before enqueue");
    }
    else{
        if(front==-1){
            front=rear=0;
        }
        else{
            rear++;
        }
        printf("\nEnter Data:: ");
        scanf("%d",&queue[rear]);
        printf("\n%d Inserted enter '3' to display",queue[rear]);
    }
}

void Dequeue(){
    int d;
    if(front==-1 || front>rear){
        printf("\nQueue is empty Insert some data bfore Dequeue");
    }
    else{
        d= queue[front];
        front++;
        printf("\n%d Deleted enter '3' to display",d);
    }
}

void Display(){
    int q;
    if(front==-1 || front>rear){
        printf("\nQueue is empty Insert some data bfore Dequeue");
    }
    else{
        q=front;
        printf("\nQueue elements: ");
        while(q<=rear){
            printf("%d ",queue[q]);
            q++;
        }
    }
}
