/*
********** Code by GOVIND KUMAR (11912057   I.T.) *********************************
---------------------------- PROGRAM-3 --------------------------------------------
Make a program to construct a BST for the following set of names:  
    Arthi Christy Dorothy Fraser Eliza 

    Insert a name "David" into BST.
*/
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

struct Node
{
	char data[100];
	struct Node *left;
	struct Node *right;
};
struct Node *root;

struct Node *new_node(char str[20])           //function to create a new  node
{               
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    strcpy(new->data,str);
    new->left=NULL;
    new->right=NULL; 
    return new;
}

void initialise()           //function to create the BST as given in the question 
{
    root=new_node("Arthi");
    
    root->right=new_node("Christy");
    
    root->right->right=new_node("Dorothy");
    
    root->right->right->right=new_node("Fraser");
    
    root->right->right->right->left=new_node("Eliza");
}

void insert(struct Node* root,char* str)      //function to insert the node into the given binary tree
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp=root;
    while(1)
    {
        if(temp)
        {
            if(strcmp(temp->data,str)>0)         //move to left if node data is greater than the new node
            {
                if(temp->left)
                {
                    temp=temp->left;
                }
                else
                {
                    temp->left=new_node(str);          //if a node is null then create a new node
                    return;
                } 
            }
            else
            {  
                if(temp->right)                   //move to right if node data is smaller than the new node
                {
                    temp=temp->right;
                }
                else
                {
                    temp->right=new_node(str);          //if a node is null then create a new node
                    return;
                }   
            }
        }   
    } 
}

void postorder(struct Node* root)    //printing all string in postorder as given in the question
{
    if(!root)
    {
        return;
    }
    if(root)
    {        
        postorder(root->left);
        postorder(root->right);
        puts(root->data);
    }  
}

void main()
{
    initialise();               //create the binary search tree as given in the question   
    printf("Initially the binary tree in postorder is :\n");
    postorder(root);                     //print the initial BST
    printf("\nNow, after inserting \"David\" into this BST :\n");
    insert(root,"David");           //call insert function
    postorder(root);                 //print the new BST in postorder

}