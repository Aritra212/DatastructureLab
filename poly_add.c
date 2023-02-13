// Program to add two polynomial expressions using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
};
typedef struct Node *Nodeptr;

Nodeptr CreateNode();               //Create a Node
Nodeptr CreatePoly();               //Create a Polynomial Expression
Nodeptr AddPoly(Nodeptr, Nodeptr);  //Add two Expressions
void Display(Nodeptr);              //Display Polynomial Expression

int main(){
    int n;
    Nodeptr l1,l2,sum;
    while(1){
        printf("\n----------------------------------------------\n");
        printf("\n----------- Instertion 1 ---------------");
        l1= CreatePoly();
        printf("\n----------- Instertion 2 ---------------");
        l2= CreatePoly();
        
        printf("\n---------- Before Addition ------------");
        Display(l1);
        Display(l2);
        
        ///////// Addition  ////////
        sum= AddPoly(l1,l2);
        printf("\n---------- After Addition ------------");
        Display(sum);
        
        //////// Handle Exit Condition  //////////
        printf("\nEnter '0' to exit: ");
        scanf("%d",&n);
        if(n == 0){
            exit(0);
        }
    }
    return 0;
}
Nodeptr CreateNode(){
    Nodeptr address;
    address = (Nodeptr)malloc(sizeof(Nodeptr));
    address->next= NULL;
    return address;
}
Nodeptr CreatePoly(){
    int n,i;
    Nodeptr temp,ptr,start=NULL;
    printf("\nEnter no of terms: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        ptr=start;
        temp=CreateNode();
        
        printf("\n=======================================");
        printf("\nEnter Coeficient for term %d :: ",i);
        scanf("%d",&temp->coef);
        printf("\nEnter Exponent for term %d :: ",i);
        scanf("%d",&temp->exp);

        if(start==NULL){
            start=temp;
        }
        else{
            while(ptr->next!=NULL){
                ptr= ptr->next;
            }
            ptr->next= temp;
        }
    }
    printf("\nExression Inserted");
    return(start);
}

Nodeptr AddPoly(Nodeptr l1, Nodeptr l2){
    int a,e;
    Nodeptr p,q,ptr,sum=NULL,temp;   
    /* 'sum' is used as the starting pointer of a list which contains the result of addition operation.
    'ptr' is used to traverse the result linked list and 'temp' is used to hold newly created node.
    'p' & 'q' is used to traverse the two expression list in one time */
    
    p=l1;
    q=l2;
    while(p!=NULL && q!=NULL){ 
        if(p->exp == q->exp){
            a= p->coef+ q->coef;
            e= p->exp;
            p=p->next;
            q= q->next;
        }
        else if(p->exp > q->exp){
            a= p->coef;
            e= p->exp;
            p=p->next;
        }
        else{
            a= q->coef;
            e= q->exp;
            q=q->next;
        }
        
        ////// Create a new node and store the result to the sum linked list //////
        temp=CreateNode();
        temp->coef=a;
        temp->exp=e;
        ptr=sum;
        if(sum==NULL){
            sum= temp;
        }
        else{
            while(ptr->next!=NULL){
                ptr= ptr->next;
            }
            ptr->next= temp;
        }
    }
    if(p!=NULL){
        if(sum==NULL){
            sum=p;
        }
        else{
            temp->next= p;
        }
    }
    if(q!=NULL){
        if(sum==NULL){
            sum=q;
        }
        else{
            temp->next= q;
        }
    }
    return sum;
}

void Display(Nodeptr start){
    Nodeptr temp=start;
    if(temp==NULL){
        printf("\nNo Data to show");
    }
    else{
        printf("\nThe polynomial expression is: ");
        while(temp!=NULL){
            if(temp->coef!=0){
                if(temp->exp==0){
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
            }
            temp= temp->next;
        }
        printf("= 0");
    }
}
