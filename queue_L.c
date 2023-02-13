//  Queue Implementation Using Linked List....

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();
Nodeptr Insert(Nodeptr);
Nodeptr Dequeue(Nodeptr);
void Display(Nodeptr);

int main(){
    int n;
    Nodeptr start= NULL;

    while(1){
        printf("\n-----------------------------------\n");
        printf("\nEnter '1' to insert element.");
        printf("\nEnter '2' to delete element.");
        printf("\nEnter '3' to display Queue.");
        printf("\nEnter '0' to exit.");
        printf("\nEnter your choice::  ");
        scanf("%d",&n);

        switch(n){
            case 1: start= Insert(start);
            break;
            case 2: start= Dequeue(start);
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
    Nodeptr address = (Nodeptr) malloc(sizeof(Nodeptr));
    address->next= NULL;
    return address;
}

Nodeptr Insert(Nodeptr start){
    Nodeptr temp, ptr= start;
    
    temp= CreateNode();
    printf("\nEnter data: ");
    scanf("%d",&temp->data);

    if(start==NULL){
        start=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->next= temp;
    }
    printf("\n%d Inserted sucessfully",temp->data);
    return start;
}

Nodeptr Dequeue(Nodeptr start){
    Nodeptr temp=start;

    if(temp== NULL){
        printf("\nQueue is empty..");
    }
    else{
        start= temp->next;
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    return start;
}

void Display(Nodeptr start){
    Nodeptr temp= start;
    if(temp== NULL){
        printf("\nQueue is empty..");
    }
    else{
        printf("\nThe Queue is:");
        while (temp!=NULL)
        {
            printf(" %d",temp->data);
            temp= temp->next;
        }
    }
}
