#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// After each pass, one element is placed to its correct position
// That is why it is known as BUBBLE SORT
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

    for(int i=0;i<size-1;i++){
          
          // for updating the bubble sort
          bool flag=false;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=true;
            }
        }
         if(flag==false) break;
    }
    
    cout<<"The elements in the sorted array : ";
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";

}