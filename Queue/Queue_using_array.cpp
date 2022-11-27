#include<iostream>

using namespace std;

// IR - INSERTION at REAR
// DF - DELETION at FRONT
// FIFO rule - First In First Out

class Queue_arr{
     
     int size;
     int *arr;
     int front;     // deletion from this end
     int rear;      // insertion from this end

     public:
     Queue_arr(){
        size=0;
        arr=new int [size];
        front=-1;
        rear=-1;
     }

     Queue_arr(int size1){
        size=size1;
        arr=new int [size1];
        front=-1;
        rear=-1;
     }

     void enqueue(int data);        // O(1)
     void dequeue();                // O(1)
     void display();
     void peek();                   // The value at front
};

void Queue_arr::peek(){
       if(front==-1 && rear==-1){
           cout<<"The Queue is Empty\n";
           return;
       }

       cout<<arr[front]<<endl;
       return;
}

void Queue_arr::display(){
      if(front==-1 && rear==-1){
        cout<<"Queue is Empty\n";
        return;
      }
      
      for(int i=front;i<=rear;i++){
          cout<<arr[i]<<" ";
      }
      cout<<endl;
      return;
}

void Queue_arr::dequeue(){
     if(front==-1 && rear==-1){
        cout<<"Queue is Empty\n";
        return;
     }

     if(rear==front){
         cout<<"The dequeued element is "<<arr[front]<<endl;
         rear=-1;
         front=-1;
         return;
     }
     
     cout<<"The dequeued element is "<<arr[front]<<endl;
     front++;
     return;
}

void Queue_arr::enqueue(int data){

        if(rear==-1 && front==-1 && size>=1){
            rear++;
            front++;
            arr[rear]=data;
            return;
        }

        if(rear<size-1){
            rear++;
            cout<<"Done : "<<rear<<endl;
            arr[rear]=data;
            return;
        }

        cout<<"Queue Overflow\n";
        return;
}

int main(){
       cout<<"Hello"<<endl;
       
       cout<<"Please enter the size of the array\n";
       int size;
       cin>>size;

       Queue_arr qa(size);
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
                qa.enqueue(y);
                break;
             
             case 2:
                qa.dequeue();
                break;
             
             case 3:
                cout<<"Displaying all elements of the Queue\n";
                qa.display();
                break;
             
             case 4:
                cout<<"The front element is \n";
                qa.peek();
                break;

             default:
                cout<<"Please enter a valid number\n";
                break;
             }
       }
}
