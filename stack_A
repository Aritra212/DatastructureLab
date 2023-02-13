// Stack implementation using array

#include<stdio.h>
#include<stdlib.h>

#define M 5
int stack[M],top=-1;

void Push();
void Pop();
void Display();

int main(){
    int n;

    while(1){
        printf("\n--------------------------------\n");
        printf("\nEnter '1' to push element");
        printf("\nEnter '2' to POP element");
        printf("\nEnter '3' to display stack");
        printf("\nEnter '0' to exit");
        printf("\nEnter your choice: ");
        scanf("%d",&n);

        switch(n){
            case 1: Push();
            break;
            case 2: Pop();
            break;
            case 3: Display();
            break;
            case 0: exit(0);
            default: printf("\nInvalid Choice!!");
        }
    }
}

void Push(){
    if(top==M-1){
        printf("\nStack is full POP items before PUSH");
    }
    else{
        top++;
        printf("\nEnter Data: ");
        scanf("%d",&stack[top]);
        printf("\n%d Inserted enter '3' to display",stack[top]);
    }
}

void Pop(){
    int n;
    if(top==-1){
        printf("\nStack is empty PUSH something before POP");
    }
    else{
        n=stack[top];
        top--;
        printf("\n%d Poped from stack enter '3' to display other items",n);
    }
}

void Display(){
    int sp;
    if(top==-1){
        printf("\nStack is empty enter '1' to PUSH data");
    }
    else{
        sp=top;
        printf("\nStack elements: ");
        while(sp>=0){
            printf("%d ",stack[sp]);
            sp--;
        }
    }
}
