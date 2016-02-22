// merge sort- basic implementation
/* This sorting procedure follows the divide and conquer paradigm, and thus sorts the list recursively. 
** It has a time complexity of O(n*Logn) and space complexity of O(n) */
#include <bits/stdc++.h>
using namespace std;

void MergeSort(int*, int, int);
void merge(int*, int, int, int); 

int main() {
	int size,i;
    int *ar;
    cin>>size;
    ar= new (nothrow) int[size];  // dynamically create an array
   
    if (ar== NULL)
      return 0;

    else{
    for (i=0; i<size; i++)
     cin>>ar[i];
    }

    int firstInd= 0, lastInd= size-1;

    MergeSort(ar,firstInd,lastInd);
    
    cout<<endl;
    for (i= 0; i< size; i++)
       cout<<ar[i]<<" ";  
	return 0;
}
void MergeSort(int *ar, int firstInd, int lastInd){
    
   if(firstInd < lastInd){
     int mid= (firstInd+lastInd)/2;
     
     MergeSort(ar, firstInd, mid);
     MergeSort(ar, mid+1, lastInd);
     merge(ar, firstInd, mid, lastInd);
  }
}

void merge(int *ar, int firstInd, int mid, int lastInd){
 
 int i,j;
 int size1= mid-firstInd+1;  
 int size2= lastInd- mid;

 int *left= new (nothrow) int[size1+1];  // dynamically create 2 new arrays of size1+1 and size2+1, resptly. 
 int *right= new (nothrow) int[size2+1];

 if( left==NULL && right==NULL)
    return;
 
 for(i=0; i< size1; i++){
   left[i]= ar[firstInd+i];
 }
 for(j=0; j< size2 ;j++){
   right[j]= ar[mid+1+j];
 }
 left[i]= INT_MAX;
 right[j]= INT_MAX;
  
 i=j=0;
 for(int k = firstInd; k<= lastInd; k++){
  
  if (left[i] < right[j]){
    ar[k]= left[i];
    i++;
  }
  else{
    ar[k]= right[j];
    j++;
  }   
 }
}
