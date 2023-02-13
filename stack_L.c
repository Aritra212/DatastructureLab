// Stack Using Linked List....
#include<stdlib.h>
#include<stdio.h>

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();
Nodeptr Push(Nodeptr);
Nodeptr Pop(Nodeptr);
void Display(Nodeptr);

int main(){
    int n;
    Nodeptr start= NULL;

    while(1){
        printf("\n-----------------------------------\n");
        printf("\nEnter '1' to Push Items.");
        printf("\nEnter '2' to Pop Items.");
        printf("\nEnter '3' to display Stack.");
        printf("\nEnter '0' to exit.");
        printf("\nEnter your choice::  ");
        scanf("%d",&n);

        switch(n){
            case 1: start= Push(start);
            break;
            case 2: start= Pop(start);
            break;
            case 3: Display(start);
            break;
            case 0: exit(0);
            default: printf("\nInvalid Choice");
        }
    }
    return 0;
}

Nodeptr CreateNode(){
    Nodeptr address;
    address= (Nodeptr) malloc(sizeof(Nodeptr));
    address->next=NULL;
    return address;
}

Nodeptr Push(Nodeptr start){
    int item;
    Nodeptr temp;
    printf("\nEnter Data: ");
    scanf("%d",&item);
    temp= CreateNode();

    if(start!=NULL){
        temp->next=start;
    }
    start= temp;
    temp->data= item;
    printf("\n%d Inserted sucessfully",item);
    return start;
}

Nodeptr Pop(Nodeptr start){
    Nodeptr temp;
    if(start==NULL){
        printf("\nStack is empty push some items before pop");
    }
    else{
        temp= start;
        start= start->next;
        printf("\n%d deleted sucessfully",temp->data);
        free(temp);
        return start;
    }
}

void Display(Nodeptr start){
    Nodeptr temp;
    if(start== NULL){
       printf("\nStack is empty push some items before display"); 
    }
    else{
        temp= start;
        printf("\nThe Stack elements: ");
        while(temp!=NULL){
            printf(" %d",temp->data);
            temp= temp->next;
        }
    }
}
