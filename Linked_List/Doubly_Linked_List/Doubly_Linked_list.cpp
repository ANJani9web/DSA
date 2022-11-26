#include<iostream>
using namespace std;

class DLL{
    
    struct Node{
          int data;
          Node *next;
          Node *prev;
    };

    public:
    Node *head;
    DLL()
    {head=NULL;}

    void insertion_at_first(int data);
    void Printing_the_elements();
    void insertion_at_last(int data);
    void deletion_at_start();
    void deletion_at_end();

};

void DLL::deletion_at_end(){
     if(head==NULL){
        cout<<"No deletion is possible:\n";
        return;
     }
     
     if(head->next==NULL){
        delete(head);
        head=NULL;
        return;
     }

     Node *t1=head;
     Node *t2=NULL;

     while(t1->next!=NULL){
        t2=t1;
        t1=t1->next;
     }

     delete(t1);
     t2->next=NULL;
     return;

}

void DLL::deletion_at_start(){
    if(head==NULL) {
        cout<<"Deletion is not possible.\n";
        return;
        }
    if(head->next==NULL){
        delete(head);
        head=NULL;
        return;
    }

    Node *t=head->next;
    t->prev=NULL;
    delete(head);
    head=t;
    return;

}

void DLL::insertion_at_last(int data){
    Node *n=new Node;
    n->data=data;
    n->next=NULL;

    if(head==NULL){
         n->prev=NULL;
         head=n;
         return;
    }

    Node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }

    t->next=n;
    n->prev=t;
    
    return;
}

void DLL::Printing_the_elements(){
     if(head==NULL) {
        cout<<"No element is present in the List\n";
        return;
        }
     
     Node *t=head;
     while(t->next!=NULL){
        cout<<t->data<<" ";
        t=t->next;
     }
     cout<<t->data<<endl;
     return;

}

void DLL::insertion_at_first(int data){
     Node *n=new Node;
     n->data=data;
     n->prev=NULL;
     
     Node *t=head;
     if(t==NULL){
           n->next=NULL;
           head=n;
           return;
     }

     n->next=t;
     t->prev=n;
     head=n;
    
     return;
}


int main(){
    cout<<"Hello"<<endl;
    DLL d;
    
    while(true){
        cout<<"Enter 0 for stopping:\n";
        cout<<"Enter 1 for inserting into the list at start:\n";
        cout<<"Enter 2 for showing the elments present in the list:\n";
        cout<<"Enter 3 for inserting into the list at end:\n";
        cout<<"Enter 4 for deleting the elements from the list at start:\n";
        cout<<"Enter 5 for deleting the elements from the list at end:\n";

        int x;
        cin>>x;
        if(x==0) break; 

        switch (x)
        {
        case 1:
            cout<<"Enter the element which has to be inserted:\n";
            int y;
            cin>>y;
            d.insertion_at_first(y);
            break;
        
        case 2:
            cout<<"Showing all the elements present in the list:\n";
            d.Printing_the_elements();
            break;

        case 3:
            cout<<"Enter the element which has to be inserted at end:\n";
            int z;
            cin>>z;
            d.insertion_at_last(z);
            break;
        
        case 4:
            cout<<"Deleting the starting element:\n";
            d.deletion_at_start();
            break;
        
        case 5:
            cout<<"Deleting the end elements:\n";
            d.deletion_at_end();
            break;

        default:
            cout<<"Please enter the valid number\n";
            break;
        }
    }
}