// Link list Master Program

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode();           // Create a Node
Nodeptr CreateList();           // Create a List of size n
Nodeptr InsertBeg(Nodeptr);     //Insert a node into the Beginning of previously created list
Nodeptr InsertEnd(Nodeptr);     //Insert a node into the End of previously created list
Nodeptr InsertAt(Nodeptr);      //Insert a node At the specific position
Nodeptr DeleteBeg(Nodeptr);     //Delete a node from the Beginning of previously created list
Nodeptr DeleteEnd(Nodeptr);     //Delete a node from the End of previously created list
Nodeptr DeleteAt(Nodeptr);      //Delete a node from a specific position
void Display(Nodeptr);          //Display the Linked List created by the user
Nodeptr ReverseList(Nodeptr);   //Reverse the linked list

int main(){
    int n;
    Nodeptr start= NULL;

    while(1){
        printf("\n--------------------------------------------\n");
        printf("\nEnter '0' to exit");
        printf("\nEnter '1' to Create a List");
        printf("\nEnter '2' for Insert Operation");
        printf("\nEnter '3' for Delete Operation");
        printf("\nEnter '4' to Display Linked List");
        printf("\nEnter '5' to Reverse The Linked List");

        printf("\nEntr your choice:: ");
        scanf("%d",&n);

        switch(n){
            case 1: start=CreateList();
            break;
            case 2:
                printf("\n=======================================");
                printf("\nEnter '0' to Back to previous menu");
                printf("\nEnter '1' to Insert into beginning");
                printf("\nEnter '2' to Insert into end");
                printf("\nEnter '3' to Insert Node At Specified Position");
                printf("\nEntr your choice:: ");
                scanf("%d",&n);
                switch(n){
                    case 0: break;
                    case 1: start= InsertBeg(start);
                    break;
                    case 2: start= InsertEnd(start);
                    break;
                    case 3: start= InsertAt(start);
                    break;
                    default: printf("Invalid Choice");
                }
            break;
            case 3:       
                printf("\n=======================================");
                printf("\nEnter '0' to Back to previous menu");
                printf("\nEnter '1' to Delete from beginning");
                printf("\nEnter '2' to Delete from end");
                printf("\nEnter '3' to Delete Node At Specified Position");
                printf("\nEntr your choice:: ");
                scanf("%d",&n);
                switch(n){
                    case 0: break;
                    case 1: start= DeleteBeg(start);
                    break;
                    case 2: start= DeleteEnd(start);
                    break;
                    case 3: start= DeleteAt(start);
                    break;
                    default: printf("Invalid Choice");
                }
            break;
            case 4: Display(start);
            break;
            case 5: start= ReverseList(start);
            break;
            case 0: exit(0);
            default: printf("Invalid Choice");
        }
    }
}

Nodeptr CreateNode(){
    Nodeptr address;
    address = (Nodeptr) malloc(sizeof(Nodeptr));
    address->next=NULL;
    return address;
}
Nodeptr CreateList(){
    int n,i,d;
    Nodeptr temp, ptr,start=NULL;
    printf("\nEnter number of nodes you want to create:: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        ptr=start;
        temp= CreateNode();
        printf("\n=======================================");
        printf("\nEnter Data for Node %d :: ",i);
        scanf("%d",&d);
        temp->data= d;

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
    printf("\nList Created");
    return start;
}

/////////////////////////////////////////////
///////     Insertion Operations    ////////
///////////////////////////////////////////

Nodeptr InsertBeg(Nodeptr start){
    Nodeptr temp;
    int item;
    printf("\n=======================================");
    printf("\nEnter node item/data: ");
    scanf("%d",&item);
    temp = CreateNode();
    temp->data= item;
    if(start!= NULL){
        temp->next= start;
    }
    start= temp;
    printf("\n%d Inserted sucessfully enter '3' to display",temp->data);
    return start;
}

Nodeptr InsertEnd(Nodeptr start){
    Nodeptr temp, ptr = start;
    int item;

    temp= CreateNode();
    printf("\n=======================================");
    printf("\nEnter Data:: ");
    scanf("%d",&item);
    temp->data= item;

    if(start== NULL){
        start= temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->next= temp;
    }
    printf("\n%d Inserted",temp->data);
    return start;
}
Nodeptr InsertAt(Nodeptr start){
    int n,i;
    Nodeptr ptr= start, temp;

    printf("\n=======================================");
    if(ptr==NULL){
        printf("\nEmpty List insert some node first.");
    }
    else{
        printf("\nEnter Position: ");
        scanf("%d",&n);
        for(i=1;i<n-1;i++){
            if(ptr==NULL){
                break;
            }
            ptr=ptr->next;
        }
        if(ptr!=NULL){
            temp= CreateNode();
            printf("\nEnter Data:: ");
            scanf("%d",&n);
            temp->data= n;

            temp->next= ptr->next;
            ptr->next= temp;
            printf("\n%d Inserted",temp->data);
        }
        else{
            printf("\nInvalid Position");
        }
    }
    return start;
}

////////////////////////////////////////////
////////    Deletion Operations     ///////
//////////////////////////////////////////

Nodeptr DeleteBeg(Nodeptr start){
    Nodeptr temp;
    temp= start;
    printf("\n=======================================");
    if(start==NULL){
        printf("\nThe List is empty insert some data before delete.");
    }
    else{
        start= start->next;
        printf("\n%d is deleted.",temp->data);
        free(temp);
    }
    return start;
}
Nodeptr DeleteEnd(Nodeptr start){
    Nodeptr temp, ptr= start;
    printf("\n=======================================");
    if(start== NULL){
        printf("\nLinked List is empty");
    }
    else{
        if(start->next==NULL){
            temp= start;
            start=NULL;
        }
        else{
            while(ptr->next->next!=NULL){
                ptr= ptr->next;
            }
            temp= ptr->next;
            ptr->next= NULL;
        }
        printf("\n%d deleted",temp->data);
        free(temp);
    }
    return start;
}
Nodeptr DeleteAt(Nodeptr start){
    int n,i;
    Nodeptr ptr=start, temp;

    printf("\n=======================================");
    if(ptr==NULL){
        printf("\nEmpty List insert some node first.");
    }
    else{
        printf("\nEnter Position: ");
        scanf("%d",&n);
        for(i=2;i<n;i++){
            ptr=ptr->next;
            if(ptr==NULL){
                printf("\nInvalid Position");
                break;
            }
        }
        if(n==1){
            temp=start;
            start= start->next;
            printf("\n%d Deleted",temp->data);
            free(temp);
        }
        else if( ptr!=NULL && ptr->next!=NULL){
            printf("%d ",ptr->data);
            temp= ptr->next;
            ptr->next= ptr->next->next;
            printf("\n%d Deleted",temp->data);
            free(temp);
        }
    }
    return start;
}

//////////////////////////////
/////////   Diplay  /////////
////////////////////////////

void Display(Nodeptr start){
    Nodeptr ptr= start;
    printf("\n=======================================");
    if(start== NULL){
        printf("\nNo node to show please insert some nodes before display");
    }
    else{
        printf("\nThe list element(s) is(are) : ");
        while(ptr!=NULL){
            printf("%d",ptr->data);
            if(ptr->next!=NULL){
                printf("-> ");
            }
            ptr= ptr->next;
        }
    }
}

///////////////////////////////////////
/////////////   Reverse    ///////////
/////////////////////////////////////

Nodeptr ReverseList(Nodeptr start){
    Nodeptr a,b,ptr=NULL;

    if(start==NULL){
        printf("\nEmpty List");
    }
    else{
        b=start;
        while(b!=NULL){
            a=b;
            b=b->next;
            a->next=ptr;
            ptr= a;
        }
        start=a;
        Display(start);
    }
    return start;
}
