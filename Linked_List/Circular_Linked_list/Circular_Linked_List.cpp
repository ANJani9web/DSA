#include<iostream>
using namespace std;

// we are keeping a tail pointer instead of tail pointer in circular linked list
// because we do not want to traverse the whole list for inserting at start or at end
class CLL {
   
   struct Node{
       int data;
       Node *next;
   };

   public:
   Node *tail;

   CLL(){
     tail=NULL;
   }

   void insertion_at_start(int data);
   void printing_all_elements();
   void insertion_at_last(int data);
   void deletion_at_start();
   void deletion_at_end();

};

// For this we have to traverse the whole linked list
void CLL::deletion_at_end(){
    if(tail==NULL) {
    cout<<"No deletion of elements is possible\n";
    return;
    }

    if(tail->next==tail){
        delete(tail);
        tail=NULL;
        return;
    }
    
    Node *t1=NULL;
    Node *t2=tail;

    while(t2->next!=tail){
        t1=t2;
        t2=t2->next;
    }

    t1=t2->next;
    t2->next=t1->next;
    tail=t2;
    delete(t1);

}

void CLL::deletion_at_start(){

    if(tail==NULL) {
        cout<<"No deletion of elements is possible\n";
        return;
        }

    if(tail->next==tail){
        delete(tail);
        tail=NULL;
        return;
    }

    Node *t=tail->next;
    tail->next=t->next;

    delete(t);
    return;
}

void CLL::insertion_at_last(int data){
      Node *n=new Node;
      n->data=data;

      if(tail==NULL){
          n->next=n;
          tail=n;
          return;
      }
      
      n->next=tail->next;
      tail->next=n;
      tail=n;

      return;

}

void CLL::printing_all_elements(){
    if(tail==NULL) {
        cout<<"No element is present.\n";
        return;}
    
    Node *t=tail->next;
    while(t!=tail){
        cout<<t->data<<" ";
        t=t->next;
    }

    cout<<tail->data<<endl;
    return;
}

// careful about the tail pointer 
// tail pointer is not going to shift anywhere
void CLL::insertion_at_start(int data){
        Node *n=new Node;

        n->data=data;
        if(tail==NULL){
            n->next=n;
            tail=n;
            return;
        }
        
        n->next=tail->next;
        tail->next=n;
        return;
}

int main(){
    cout<<"hello"<<endl;
    CLL c;
    
    while(true){
        
        cout<<"Enter 0 to stop\n";
        cout<<"Enter 1 to insert into the Circular Linked list at start\n";
        cout<<"Enter 2 to show all the elements present\n";
        cout<<"Enter 3 to insert into the Circular Linked list at end\n";
        cout<<"Enter 4 to delete from the Circular Linked list at start\n";
        cout<<"Enter 5 to delete from the Circular Linked list at end\n";

        int x;
        cin>>x;

        if(x==0) break;

        switch (x)
        {
        case 1:
            cout<<"Enter the element which has to inserted at start\n";
            int y;
            cin>>y;
            c.insertion_at_start(y);
            break;

        case 2:
            cout<<"Printing all the elements present in the Circular linked list\n";
            c.printing_all_elements();
            break;
        
        case 3:
            cout<<"Enter the element which has to inserted at end\n";
            int z;
            cin>>z;
            c.insertion_at_last(z);
            break;
        
        case 4:
            cout<<"Deleting the elements from the start of the Circular Linked list\n";
            c.deletion_at_start();
            break;
        
        case 5:
            cout<<"Deleting the elements from the end of the Circular Linked List\n";
            c.deletion_at_end();
            break;
            
        default:
            cout<<"Please enter a valid number\n";
            break;
        }
    }
}