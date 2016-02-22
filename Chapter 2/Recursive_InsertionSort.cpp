// Recursive version of Insertion sort
#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int *ar, int size){
  int i,j;
  if(size >1)
    InsertionSort(ar, size-1);       // takes T(n-1) time
  if(size==1)
    return;
 else{
    j= size-1;
    int key= ar[j];
    i= j-1;
    while( i >= 0 && ar[i] >key){        // while loop is executed for i=0 to i= j-1, thus it is executed atmost j times. j= size-1
       ar[i+1]= ar[i];
       i--; 
    }
    ar[i+1]= key;
  }
}

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
   
    InsertionSort(ar,size);
    cout<<endl;
    for (i= 0; i< size; i++)
       cout<<ar[i]<<" ";  
	return 0;
}
// Recurrence - T(n)= T(n-1) + O(n)