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


int main(){
    
    node * root = new node;
    root = create();

    //        8
    //       /  \
    //      3    5
    //     / \  / \
    //    2  4 6   7
}