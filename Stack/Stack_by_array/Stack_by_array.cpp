#include<iostream>
using namespace std;

// Four operations : push, pop, peek, Isempty
class Stack_arr{
    private:

    int size;   // the length of the array
    int *arr;   // the array
    int top;    // for getting the value of the index

    public:
    Stack_arr(){       // constructor without size
        top=-1;
        size=0;
        arr=new int[size];
    }

    Stack_arr(int size){  // constructor with known size of the array
        this->size=size;
        top=-1;
        arr=new int[size];
    }
    
    void push(int data);
    void pop();
    void peek();
    bool IsEmpty();
};

bool Stack_arr::IsEmpty(){
    return (top==-1);
}

void Stack_arr::push(int data){
        if(top>=size-1) {
            cout<<"Stack Overflow"<<endl;
            return;
        }

        top++;
        arr[top]=data;
}

void Stack_arr::pop(){
    if(top<0) {
        cout<<"Stack Underflow"<<endl;
        return;
    }

    if(top>=size)
    {
        cout<<"Stack Overflow\n";
        return;
    }
    
    cout<<"The poped element is "<<arr[top]<<endl;
    top--;
}

void Stack_arr::peek(){
     if(top<0 || top>=size){
        cout<<"Top Element can not be seen\n";
        return ;
     }
    
    cout<<"The Top element is "<<arr[top]<<endl;
    return;

}
int main(){
    cout<<"Hello"<<endl;
    cout<<"Please enter the size of the Stack :";
    int size;
    cin>>size;

    Stack_arr sa(size);

    while(true){
        cout<<"Enter 0 to stop\n";
        cout<<"Enter 1 to push into the Stack\n";
        cout<<"Enter 2 to pop from the Stack\n";
        cout<<"Enter 3 to peek from the Stack\n";
        cout<<"Enter 4 to find whether Stack is full or not\n";

        int x;
        cin>>x;
        if(x==0) break;

        switch (x)
        {
        case 1:
            cout<<"Enter the element which has to be pushed into the Stack\n";
            int y;
            cin>>y;
            sa.push(y);
            break;

        case 2:
            cout<<"Poping the element from the Stack\n";
            sa.pop();
            break;
        
        case 3:
            cout<<"To see the topmost element of the Stack\n";
            sa.peek();
            break;

        case 4:
            cout<<"To find whether the Stack is full or not\n";
            if(sa.IsEmpty()) cout<<"Stack is empty\n";
            else cout<<"Stack is not empty\n";
            break;

        default:
            cout<<"Please enter a valid number\n";
            break;
        }
    }

}