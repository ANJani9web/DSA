#include<iostream>
using namespace std;

struct node
{
   int data;
   node *left;
   node *right;
};

node * create(){
     
     node * n= new node;
     cout<<"Enter 0 to stop \n";  // Entering 0 for stopping or enter the NULL Pointer 
     int x;
     cin>>x;

     if(x==0) return NULL;

     n->data=x;

     cout<<"Enter left child of "<<x<<endl;
     n->left=create();

     cout<<"Enter right child of "<<x<<endl;
     n->right=create();

     return n;
}

void Inorder(node *root){

    if(root==NULL) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);

}

void Preorder(node *root){

    if(root==NULL) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}

void Postorder(node *root){

    if(root==NULL) return;

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";

}

int main(){
    
    node * root = new node;
    root = create();

    //        8
    //       /  \
    //      3    5
    //     / \  / \
    //    2  4 6   7

    cout<<"Printing Inorder Traversal of the tree : \n";
    Inorder(root);
    cout<<endl;

    cout<<"Printing Preorder Traversal of the tree : \n";
    Preorder(root);
    cout<<endl;

    cout<<"Printing Postorder Traversal of the tree : \n";
    Postorder(root);
    
}