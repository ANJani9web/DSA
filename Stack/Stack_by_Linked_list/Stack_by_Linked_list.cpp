#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

// since insertion and deletion in stack is of O(1)
// Therefore, we have to do insertion and deletion at the start of the linked list

struct Node{
     int data;
     Node *next;
};

Node *top=NULL;  // for keeping the record of the current pointer

void push(int data){
      Node *n=new Node;
      n->data=data;
      
      Node *t=top;

      if(top==NULL){
         n->next=NULL;
         top=n;
         return;
      }

      n->next=top;
      top=n;
      return;
}

void pop(){
    if(top==NULL){
        cout<<"Stack Underflow\n";
        return;
    }

    if(top->next==NULL){
        cout<<"The poped element is "<<top->data<<endl;
        delete(top);
        top=NULL;
        return;
    }

    Node*n=top->next;
    cout<<"The poped element is "<<top->data<<endl;
    delete(top);
    top=n;
    return;
}

void peek(){
    if(top==NULL){
        cout<<"Topmost element is not visible\n";
        return;
    }

    cout<<"The topmost element is "<<top->data<<endl;
    return;
}

bool IsEmpty(){
    return(top==NULL);
}

int main(){
      cout<<"Hello"<<endl;

      while(true){
        cout<<"Enter 0 to stop"<<endl;
        cout<<"Enter 1 to push into the Stack"<<endl;
        cout<<"Enter 2 to pop from the Stack\n";
        cout<<"Enter 3 to view Top element of the Stack\n";
        cout<<"Enter 4 to find whether Stack is empty or not\n";
        
        int x;
        cin>>x;

        if(x==0) break;

        switch (x)
        {
        case 1:
            cout<<"Enter the element which has to pushed into the Stack\n";
            int y;
            cin>>y;
            push(y);
            break;
        
        case 2:
            pop();
            break;

        case 3:
            peek();
            break;
        
        case 4:
            if(IsEmpty()) cout<<"The Stack is Empty\n";
            else cout<<"The Stack is not Empty\n";
            break;

        default:
            cout<<"Please enter a valid number\n";
            break;
        }
        
      }
}
