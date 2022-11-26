#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class SLL{
     private:
     struct Node{
           int data;
           Node * next;
     };
    //  Node *head;

     public:
     Node *head;
     SLL(){
        head=NULL;
     }

     void insertion_at_last(int data);
     void insertion_at_first(int data);
     void print_items();
     void deletion_at_first();
     void deletion_at_last();
};

void SLL::deletion_at_last(){
    Node *t1=head;
    Node *t2=NULL;

    if(t1==NULL) {
        cout<<"No deletion is possible\n";
        return;
    }

    if(t1->next==NULL){
        delete(t1);
        head=NULL;
        return;
    }
    while(t1->next!=NULL){
        t2=t1;
        t1=t1->next;
    }

    delete (t1);
    t2->next=NULL;
    return;
}

void SLL::deletion_at_first(){
    if(head==NULL) 
        {   
            cout<<"Deletion is not possible\n";
            return;
        }
    Node *n;
    n=head;

    head=n->next;
    delete(n);
}

void SLL::print_items(){
    if(head==NULL) {
        cout<<"No element is present in List"<<endl;
        return;
    }
    {
        Node *t=head;
        while(t->next!=NULL){
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<t->data<<endl;
        return;
    }
}

void SLL::insertion_at_last(int data){
      
      Node *t;

      // creating the new node
      Node *n=new Node;
      n->data=data;
      n->next=NULL;
      if(head==NULL) {
        head=n;
        return;
      }

      t=head;
      while(t->next!=NULL){
        t=t->next;
      }
      t->next=n;
      return;

}

void SLL::insertion_at_first(int data){
    Node *n=new Node;
    n->data=data;
    n->next=NULL;

    n->next=head;
    head=n;
}
int main(){
     cout<<"Hello"<<endl;
     SLL s;
    
     while(true){

        cout<<"Enter 0 for stoping\n";
        cout<<"Enter 1 for insertion at start\n";
        cout<<"Enter 2 for insertion at end\n";
        cout<<"Enter 3 for printing all the elements\n";
        cout<<"Enter 4 for deletion at start\n";
        cout<<"Enter 5 for deletion at last\n";

        int x;
        cin>>x;
        if(x==0) break;

        switch (x)
        {
     case 1:
        cout<<"Enter the element to be inserted at first : \n";
        int y;
        cin>>y;
        s.insertion_at_first(y);
        break;

     case 2:
        cout<<"Enter the element to be inserted at last :\n";
        int z;
        cin>>z;
        s.insertion_at_last(z);
        break;
    
     case 3:
        cout<<"Showing the elements present in the linked list :\n";
        s.print_items();
        break;

     case 4:
        cout<<"Deleting the element at start:\n";
        s.deletion_at_first();
        break;
     
     case 5:
        cout<<"Deleting the element at last:\n";
        s.deletion_at_last();
        break;

     default:
        cout<<"Please enter a valid number\n";
        break;
        }

     }
    
}
