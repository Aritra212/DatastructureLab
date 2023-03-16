// Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
typedef struct Node * Nodeptr;

Nodeptr CreateNode(int);
Nodeptr CreateBST();
Nodeptr InsertBST(Nodeptr,int);
void Preorder(Nodeptr);
void Inorder(Nodeptr);
void Postorder(Nodeptr);

int main(){
    int n,d;
    Nodeptr root=NULL;
    while(1){

        printf("\n----------------------------------------------\n");
        printf("\nEnter '0' to exit");
        printf("\nEnter '1' to Create BST");
        printf("\nEnter '2' to Insert a  Node");
        printf("\nEnter '3' to Delete a Node");
        printf("\nEnter '4' to Preorder");
        printf("\nEnter '5' to Inorder");
        printf("\nEnter '6' to Postorder");
        printf("\nEnter Your Choice:: ");
        scanf("%d",&n);
        printf("\n----------------------------------------------\n");
        switch(n){
        	
            case 1: root= CreateBST();
            break;
            case 2: 
                printf("\nEnter Data: "); 
                scanf("%d",&d);
                root= InsertBST(root,d);
            break;
            case 4: Preorder(root);
            break;
            case 5: Inorder(root);
            break;
            case 6: Postorder(root);
            break;
            case 0: exit(0);
            default: printf("\nInvalid Choice!!");
        }
    }
}

Nodeptr CreateNode(int d){
    Nodeptr addr;
    addr= (Nodeptr)malloc(sizeof(Nodeptr));
    addr->left= NULL;
    addr->right= NULL;
    addr->data= d;
    return addr;
}

Nodeptr CreateBST(){
	Nodeptr root=NULL;
	int n,d;
	
	printf("Enter number of nodes you want to insert: ");
	scanf("%d",&n);
	while(n>0){
		printf("Enter data for node : ");
		scanf("%d",&d);
		root= InsertBST(root,d);
		n--;
	}
	printf("BST Created Sucessfully");
	return root;
}
Nodeptr InsertBST(Nodeptr root, int d){
    if(root==NULL){
        root= CreateNode(d);
    }
    else if(d<=root->data){
        root->left= InsertBST(root->left, d);
    }
    else{
        root->right= InsertBST(root->right, d);
    }
    return root;
}

void Preorder(Nodeptr root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Nodeptr root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(Nodeptr root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}
