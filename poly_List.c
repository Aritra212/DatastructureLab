//Polynomial Expression Representation Using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();   //Create a node and return its address
Nodeptr CreatePoly();  //Take input from user and create a linked list containing polynomial terms
void Display(Nodeptr);  //Used to display the expression

int main(){
    int n;
    Nodeptr start=NULL;
    while(1){
        printf("\n-------------------------------------\n");
        printf("\nPress '0' to exit");
        printf("\nPress '1' to Insert Expression");
        printf("\nEnter Your Choice: ");
        scanf("%d",&n);

        switch(n){
            case 1: start= CreatePoly();
            break;
            case 0: exit(0);
            default: printf("Invalid Choice");
        }
    }
}

Nodeptr CreateNode(){
    Nodeptr address;
    address = (Nodeptr)malloc(sizeof(Nodeptr));
    address->next= NULL;
    return address;
}

Nodeptr CreatePoly(){
    int n,i;
    Nodeptr temp, ptr,start=NULL;
    printf("\nEnter number of term you want to Insert:: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        ptr=start;
        temp= CreateNode();
        printf("\n=======================================");
        printf("\nEnter Coeficient for term %d :: ",i);
        scanf("%d",&temp->coef);
        printf("\nEnter Exponent for term %d :: ",i);
        scanf("%d",&temp->exp);

        if(start== NULL){
            start= temp;
        }
        else{
            while(ptr->next!=NULL){
                ptr= ptr->next;
            }
            ptr->next= temp;
        }
    }
    printf("\nExpression Inserted");
    Display(start);
    return start;
}
void Display(Nodeptr start){
    Nodeptr temp = start;
    
    if(temp== NULL){
        printf("\nNo Data to Show");
    }
    else{
        printf("\nThe Polynomial Expression is: ");
        while(temp!=NULL){
            if(temp->exp== 0){
                printf("%d",temp->coef);
            }
            else if(temp->coef==1){
                printf("x^%d",temp->exp);
            }
            else if(temp->exp==1){
                printf("%dx",temp->coef);
            }
            else{
                printf("%dx^%d",temp->coef,temp->exp);
            }
            if(temp->next!=NULL && temp->next->coef >=0){
                printf("+");
            }
            temp= temp->next;
        }
        printf("= 0");
    }
}
