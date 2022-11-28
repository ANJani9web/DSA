#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Level of a tree = height of a tree
// Depth of a node : Length of path from root to that node
// Height of a node : Number of edges in longest path from node to leaf
// Level of a node : the number of edges along the unique path between it and the root node
// Level of root = 0

// Full/Proper/Strict Binary Tree - A tree with each node having 0 or 2 node 
   // OR only leaf node has 0 degree else have degree of 2
   // Number of leaf node = Number of internal node + 1

// Complete Binary Tree - All the levels are completely filled (except possibly the last level ) 
//                        and the last level has nodes as left as much as possible

// Perfect Binary Tree - All internal nodes have two children and all leave nodes are at same level
// 

int main(){
   cout<<"Hello"<<endl;

   cout<<"Please enter the height of the tree :\n";
   int height;
   cin>>height;

   int size=pow(2,(height+1))-1;
   
   int *arr=new int[size];
   
   int i=0,j=0;

   for(j=0;j<size;j++){
       
       
   }
}