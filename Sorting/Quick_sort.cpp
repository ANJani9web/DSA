#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// We can select any element as PIVOT element
// PIVOT element can be fist, mid, last, second or anyone
// This sorting technique is based on divide and conquer 
// also known as Partition Exchange sort

// Time Complexity
// Worst Case - O(n*n)
// Average Case - O(n log(n))

int partition(int lower,int upper, int a[]){  // backbone of Quick sort

     int pivot=a[lower];                     // Taking the starting element of array as pivot

     int start=lower;
     int end=upper;
     
     while(start<end){

        while(a[start]<=pivot) start++;
        while(a[end]>pivot) end--;

        if(start<end) swap(a[start],a[end]);

     }

     swap(a[lower],a[end]);
     return end;
}

void Quick_Sort(int a[],int lower, int upper){

    if(lower<upper){
        int location=partition(lower,upper,a);

        Quick_Sort(a,lower,location-1);
        Quick_Sort(a,location+1,upper);
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

    Quick_Sort(arr,0,size-1);
    
    cout<<"The elements in the sorted array : ";
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";

}