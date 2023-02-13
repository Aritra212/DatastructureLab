// Implement circular linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();
Nodeptr CreateCLL();
Nodeptr InsertBeg(Nodeptr);
Nodeptr InserEnd(Nodeptr);
Nodeptr DeleteBeg(Nodeptr);
Nodeptr DeleteEnd(Nodeptr);
void Display(Nodeptr);

int main(){
    int n;
    Nodeptr head= NULL;
    while(1){
        printf("\n---------------------------------------------\n");
        printf("\nEnter '1' to Create Circular Linked List.");
        printf("\nEnter '2' to Insert node into Beginning of the list.");
        printf("\nEnter '3' to Insert node into end of the list.");

        printf("\nEnter '5' to Delete node from Beginning of the list.");
        printf("\nEnter '6' to Delete node from end of the list.");
        printf("\nEnter '7' to Display Circular Linked List.");
        printf("\nEnter '0' to exit");
        printf("\nEnter your choice:: ");
        scanf("%d",&n);

        switch(n){
            case 1: head= CreateCLL();
            break;
            case 2: head= InsertBeg(head);
            break;
            case 3: head= InserEnd(head);
            break;
            case 5: head= DeleteBeg(head);
            break;
            case 6: head= DeleteEnd(head);
            break;
            case 7: Display(head);
            break;
            case 0: exit(0);
            default: printf("\nInvalid Choice!! Try Again!!");
        }
    }
    return 0;
}
Nodeptr CreateNode(){
    Nodeptr address;
    address= (Nodeptr)malloc(sizeof(Nodeptr));
    address->next= NULL;
    return address;
}
Nodeptr CreateCLL(){
    int i;
    Nodeptr head=NULL,temp;

    printf("\n============= Create Linked List =================");
    printf("\nEnter number of nodes you want to create:: ");
    scanf("%d",&i);
    for(i;i>0;i--){
        temp= CreateNode();

        // insert data
        printf("\nEnter data:: ");
        scanf("%d",&temp->data);

        if(head==NULL){
            head= temp;
            temp->next= head;
        }
        else{
            temp->next=head->next;
            head->next=temp;
            head= temp;
        }
    }
    Display(head);
    return head;
}
Nodeptr InsertBeg(Nodeptr head){
    Nodeptr temp;
    printf("\n============ Insert Into Beginning ==============");
    temp= CreateNode();
    printf("\nEnter data:: ");
    scanf("%d",&temp->data);

    if(head==NULL){
        head= temp;
        temp->next= head;
    }
    else{
        temp->next=head->next;
        head->next=temp;
    }
    Display(head);
    return head;
}
Nodeptr InserEnd(Nodeptr head){
    Nodeptr temp;
    printf("\n=============== Insert Into End ===================");
    temp= CreateNode();
    printf("\nEnter data:: ");
    scanf("%d",&temp->data);

    if(head==NULL){
        head= temp;
        temp->next= head;
    }
    else{
        temp->next=head->next;
        head->next=temp;
        head= temp;
    }
    Display(head);
    return head;
}
Nodeptr DeleteBeg(Nodeptr head){
    Nodeptr temp;
    printf("\n=============== Delete from End ===================");
    if(head==NULL){
        printf("\nNo data to delete");
    }
    else{
        temp=head->next;
        if(temp==head){
            head=NULL;
        }
        else{
            head->next= temp->next;
        }
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    Display(head);
    return head;
}
Nodeptr DeleteEnd(Nodeptr head){
    Nodeptr temp,ptr=head;
    printf("\n=============== Delete from End ===================");
    if(head==NULL){
        printf("\nNo data to delete");
    }
    else{
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        temp=head;
        if(ptr==head){
            head=NULL;
        }
        else{
            ptr->next= head->next;
            head= ptr;
        }
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    Display(head);
    return head;
}
void Display(Nodeptr head){
    Nodeptr ptr;
    printf("\n============= Display Linked List =================");
    if(head==NULL){
        printf("\nNo data to show");
    }
    else{
        printf("\nThe Linked List Contains:: ");
        ptr= head->next;
        while(ptr!=head){
            printf("%d -> ",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
}
