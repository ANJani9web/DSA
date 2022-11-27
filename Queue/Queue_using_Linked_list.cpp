#include<iostream>
using namespace std;

// IR - INSERTION at REAR
// DF - DELETION at FRONT
// FIFO Rule - First In First Out

struct Node
{
    int data;
    Node *next;
};

Node *front=NULL;   // deletion at front
Node *rear=NULL;    // insertion at rear

void enqueue(int data){     // O(1)
    Node *n =new Node;
    n->data=data;

    if(front==NULL && rear==NULL){ // queue is empty
             n->next=NULL;
             front=n;
             rear=n;
             return;
    }

    rear->next=n;
    n->next=NULL;
    rear=n;
    return;
}

void dequeue(){     // O(1)

     if(rear==NULL && front==NULL){
        cout<<"Queue is Empty"<<endl;
        return;
     }
     
     if(rear==front){
        cout<<"The dequeued element is "<<front->data<<endl;
        rear=NULL;
        front=NULL;
        return;
     }

     Node *n=front->next;
     cout<<"The dequeued element is "<<front->data<<endl;
     delete(front);
     front=n;
     return;

}

void display(){
    Node *n=front;

    if(rear==NULL) {
        cout<<"Queue is Empty\n";
        return;
    }

    while(n!=rear){
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<rear->data<<endl;
    return;
}

void peek(){

    if(rear==NULL){
        cout<<"Queue is Empty"<<endl;
        return;
    }

    cout<<front->data<<endl;
}

int main(){
    cout<<"Hello"<<endl;

    while(true){
             cout<<"Enter 0 to stop"<<endl;
             cout<<"Enter 1 to enqueue some element in the queue\n";
             cout<<"Enter 2 to dequeue some element from the queue\n";
             cout<<"Enter 3 to display all the elements of the queue\n";
             cout<<"Enter 4 to get the peek element of the queue\n";

             int x;
             cin>>x;
             if(x==0) break;

             switch (x)
             {
             case 1:
                cout<<"Enter the element which has to be inserted\n";
                int y;
                cin>>y;
                enqueue(y);
                break;
             
             case 2:
                dequeue();
                break;
             
             case 3:
                cout<<"Displaying all elements of the Queue\n";
                display();
                break;
             
             case 4:
                cout<<"The front element is \n";
                peek();
                break;

             default:
                cout<<"Please enter a valid number\n";
                break;
             }
        }
}