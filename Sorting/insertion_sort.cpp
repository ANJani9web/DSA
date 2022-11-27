#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// We are taking one value from unsorted sub list 
// And then putting it into sorted sub list at right place
// Time Complexity
// Worst Case - O(n*n)
// Best Case - O(n)


int main(){

    cout<<"Enter the size of the array : \n";
    int size;
    cin>>size;

    int *arr=new int [size];

    cout<<"Inserting the elements into the array : \n";

    for(int i=0;i<size;i++) cin>>arr[i];

    // 15 5 20 35 2 42 67 17

    for(int i=1;i<size;i++){       // for unsorted array sub list
        
        int temp = arr[i];
        int j=i-1;
        
        while(j>=0 and arr[j]>temp){  // for making the remaining sub list sorted
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;               // putting the element from unsorted into
                                     // sorted list at right position

    }
    
    cout<<"The elements in the sorted array : ";
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";

}