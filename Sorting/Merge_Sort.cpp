#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// We firstly have to merge_sort the array until we get each element seperated
// 

// Time Complexity
// Worst Case - O(nlogn)
// Best Case - O(nlogn)
// for merge function - O(x+y)

void merge(int a[],int lower, int mid, int upper){

    int i=lower;      // for first array
    int j=mid+1;   // for second array
    int k=lower;     // for storing the elements of both arrays

    int *final=new int[upper-lower+1];
    while(i<=mid and j<=upper){
        
        if(a[i]<=a[j]){
           final[k]=a[i];
           i++;
           k++;
        }

        else{
            final[k]=a[j];
            k++;
            j++;
        }
    }

    if(i>mid){
        while(j<=upper){
            final[k]=a[j];
            k++;
            j++;
        }
    }

    else if(j>upper){
        while(i<=mid){
            final[k]=a[i];
            i++;
            k++;
        }
    }

    for(k=lower;k<=upper;k++){
        a[k]=final[k];
    }
}

void merge_sort(int a[],int lower,int upper){

    int mid=(lower+upper)/2;
    if(lower<upper){
           merge_sort(a,lower,mid);   // dividing
           merge_sort(a,mid+1,upper);  // dividing
           merge(a,lower,mid,upper);   // merging the divided array
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

    merge_sort(arr,0,size-1);
    
    cout<<"The elements in the sorted array : ";
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";

}