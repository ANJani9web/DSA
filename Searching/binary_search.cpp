#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// The basic condition for Binary search is 
// The array must be sorted
// This uses divide and conquer method


// Time Complexity - O(log n)
int binary_search(int left,int right,int element,int a[]){
    
    if (left>right) return -1;    // BASE CASE
    
    else {
        int mid=(left+right)/2;

        if(a[mid]==element) return mid;

        if(a[mid]>element) {
            return binary_search(left,mid-1,element,a);
        }
        if(a[mid]<element){
            return binary_search(mid+1,right,element,a);
        }

    } 
}

int main(){

    cout<<"Enter the size of the array : \n";
    int size;
    cin>>size;

    int *arr=new int [size];

    cout<<"Inserting the elements into the array : \n";

    for(int i=0;i<size;i++) cin>>arr[i];
    
    // 15 5 20 35 2 42 67 17
    sort(arr,arr+size);
    cout<<"Enter the element which needs to be searched :\n";
    int element;
    cin>>element;

    int index=binary_search(0,size-1,element,arr);

    if(index==-1) cout<<"The element is not found\n";
    else cout<<"The element is found at the index "<<index<<endl;

}