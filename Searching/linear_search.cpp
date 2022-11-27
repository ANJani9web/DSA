#include<iostream>
using namespace std;

// Time Complexity 
// Best case - O(1)
// Worst case - O(n)
// Average case - O(n)

int main(){

    cout<<"Enter the size of the array : \n";
    int size;
    cin>>size;

    int *arr=new int [size];

    cout<<"Inserting the elements into the array : \n";

    for(int i=0;i<size;i++) cin>>arr[i];

    // 15 5 20 35 2 42 67 17
    cout<<"Enter the element which needs to be searched :\n";
    int element;
    cin>>element;

    int index=0;
    for(index=0;index<size;index++) {
        if(arr[index]==element){
            cout<<"The element is found at index number "<<index<<endl;
            break;
        }
    }

    if(index==size) cout<<"The element is not found\n";

}