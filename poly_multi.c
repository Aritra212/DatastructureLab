// Program to mutiply two polynomial expressions using linked list
/* Let's take two polynomial expression as example to know how the following code works
    1st expression- ax^2 + bx + c = 0;
    2nd expression- rx^2 + sx +c = 0;
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int exp;
    struct Node *next;
};
typedef struct Node *Nodeptr;

Nodeptr CreateNode();                   //Create a Node
Nodeptr CreatePoly();                   //Create a Polynomial Expression
Nodeptr Addpoly(Nodeptr, Nodeptr);      //Add two Expressions
Nodeptr PolyMulti(Nodeptr, Nodeptr);    //Multiply two Expressions
void Display(Nodeptr);                  //Display Polynomial Expression

int main(){
    int n;
    Nodeptr l1,l2,mul;
    while(1){
        printf("\n----------------------------------------------\n");
        printf("\n----------- Instertion 1 ---------------");
        l1= CreatePoly();
        printf("\n----------- Instertion 2 ---------------");
        l2= CreatePoly();
        
        printf("\n-------- Before Multiplication ---------");
        Display(l1);
        Display(l2);
        
        ///////// Multiplication  ////////
        mul= PolyMulti(l1,l2);
        printf("\n-------- After Multiplication ---------");
        Display(mul);
        
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
    while(p!=NULL && q!=NULL)
    { 
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


Nodeptr PolyMulti(Nodeptr l1, Nodeptr l2){
    Nodeptr p,q,temp1,temp2,mul=NULL,ptr;   // 'mul' pointer holds the address of resultant link list
    p=l1;   // p= ax^2 + bx + c = 0;
    while(p!=NULL){
        temp2=NULL;
        q=l2;   //q= rx^2 + sx +c = 0;
        while(q!=NULL)  // this loop multiply every term of q with each term of p once at a time (i.e. ax^2 * q )
        {
            ////// Create a new node and store the result to a linked list //////
            temp1=CreateNode();

            temp1->coef= p->coef * q->coef; //storing the result coeficient of mutiplication into new node
            temp1->exp= p->exp + q->exp;    //storing the result exponent of mutiplication into new node
            
            //insertion of new node
            ptr=temp2;
            if(temp2==NULL){
                temp2= temp1;
            }
            else{
                while(ptr->next!=NULL){
                    ptr= ptr->next;
                }
                ptr->next= temp1;
            }
            q=q->next;
        }
        
        /* After performing multipliction of one term of p with every term of q we create a linked list and store the starting address to 'temp2'
           Now we just need to Add two polynomial expression to remove multiple terms which has same exponets
           
           mul= mul+temp2 => mul= (ar.x^4 + as.x^3 + ac.x^2)+(br.x^3 + bs.x^2 + bc.x)
                          => mul= ar.x^4 + (as+br)x^3 + (ac+bs)x^2 + bc.x   [reduced expression]
                          
           (***After the first execution of the above loop we don't need to do this step , just store the address stored in 'temp2' into 'mul',
            because for first excution mull=0 so mul=mul+tem2 => mul=temp2) */
        
        if(mul==NULL){
            mul=temp2;
        }
        else{
            mul= AddPoly(mul,temp2);
        }
        p=p->next;
    }
    return mul;
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
