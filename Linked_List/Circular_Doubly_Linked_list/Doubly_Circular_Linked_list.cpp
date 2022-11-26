#include<iostream>
using namespace std;

// Again we have to use the concept of tail Pointer Not the use of Start
class CDLL{
    
    struct Node{
          int data;
          Node *prev;
          Node *next;
    };

    public:
    Node *tail;
    
    CDLL(){
        tail=NULL;
    }

    void insertion_at_start(int data);
    void printing_all_elements();
    void insertion_at_last(int data);
    void deletion_at_start();
    void deletion_at_end();
};

void CDLL::deletion_at_end(){
    if(tail==NULL){
        cout<<"Deletion is not possible\n";
        return;
    }

    if(tail->next==tail){
        delete(tail);
        tail=NULL;
        return;
    }

    Node *n=tail->prev;
    n->next=tail->next;
    tail->next->prev=n;

    delete(tail);
    tail=n;
    return;
}

void CDLL::deletion_at_start(){
        if(tail==NULL){
            cout<<"Deletion is not possible\n";
            return;
        }

        if(tail->next==tail){
            delete(tail);
            tail=NULL;
            return;
        }

        Node *n=tail->next;

        tail->next=n->next;
        n->next->prev=tail;

        delete(n);
        return;
}

void CDLL::insertion_at_last(int data){
       
       Node *n=new Node;

       n->data=data;

       if(tail==NULL){
         n->next=n;
         n->prev=n;
         tail=n;
         return;
       }

       n->next=tail->next;
       n->prev=tail;

       tail->next->prev=n;
       tail->next=n;
       
       tail=n;
       return;
}

void CDLL::printing_all_elements(){

    if(tail==NULL){
        cout<<"The list is empty\n";
        return;
    }
    
    Node *t=tail->next;
    while(t!=tail){
        cout<<t->data<<" ";
        t=t->next;
    }

    cout<<tail->data<<endl;
    return;

}

void CDLL::insertion_at_start(int data){
        Node *n=new Node;

        n->data=data;

        if(tail==NULL){
            n->next=n;
            n->prev=n;
            tail=n;
            return;
        }

        n->next=tail->next;
        n->prev=tail;

        tail->next=n;
        tail->next->prev=n;
}



int main(){
    cout<<"Hello"<<endl;
    CDLL cd;
    

    while(true){

        cout<<"Enter 0 to stop\n";
        cout<<"Enter 1 to insert the elements at start of the list\n";
        cout<<"Enter 2 to display all the elements present in the list\n";
        cout<<"Enter 3 to insert the elements at end of the list\n";
        cout<<"Enter 4 to delete the element present at start of the list\n";
        cout<<"Enter 5 to delete the element present at end of the list\n";

        int x;
        cin>>x;

        if(x==0) break;

        switch (x)
        {
        case 1:
            cout<<"Enter the element which needs to inserted at the start of the list\n";
            int y;
            cin>>y;
            cd.insertion_at_start(y);
            break;
        
        case 2:
            cout<<"Displaying all the elements present in the list\n";
            cd.printing_all_elements();
            break;
        
        case 3:
            cout<<"Enter the element which needs to inserted at the end of the list\n";
            int z;
            cin>>z;
            cd.insertion_at_last(z);
            break;
        
        case 4:
            cout<<"Deleting the element present at the start of the list"<<endl;
            cd.deletion_at_start();
            break;
        
        case 5:
            cout<<"Deleting the element present at the end of the list\n";
            cd.deletion_at_end();
            break;
            
        default:
            cout<<"Please enter a valid number\n";
            break;
        }
    }
}