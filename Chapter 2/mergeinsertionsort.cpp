// insertion sort on small arrays in merge sort
#include <bits/stdc++.h>
using namespace std;

void MergeSort(int*, int, int, int);
void merge(int*, int, int, int); 
void insertionSort(int*, int, int);

int main() {
	int size,i,k;
    int *ar;
    cin>>size;
    ar= new (nothrow) int[size];  // dynamically create an array
   
    if (ar== NULL)
      return 0;

    else{
    for (i=0; i<size; i++)
     cin>>ar[i];
    }
    cin>>k;            // value of k
    int firstInd= 0, lastInd= size-1;

    MergeSort(ar,firstInd,lastInd,k);
    
    cout<<endl;
    for (i= 0; i< size; i++)
       cout<<ar[i]<<" ";  
	return 0;
}
void MergeSort(int *ar, int firstInd, int lastInd, int k){
   
   int size= lastInd- firstInd+1; 
   int mid= (firstInd+lastInd)/2;
  
   if(size > k){
     MergeSort(ar, firstInd, mid,k);
     MergeSort(ar, mid+1, lastInd,k);
     merge(ar, firstInd, mid, lastInd);
  }
  else
    insertionSort(ar,firstInd, lastInd);
 
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

void insertionSort(int *ar, int beg, int end){
 int i,j;
 for (j=beg+1; j<=end; j++){

   int key= ar[j];
   i = j-1;

   while( i>= beg && ar[i]>key){
     ar[i+1]= ar[i];
     i--;
   }
   ar[i+1]= key;  
 }
}
/* a) Insertion sort takes theta of (k^2) time to sort one sublist. Thus to sort n/k sublists it takes theta of (nk) time. {as k^2 * n/k = nk}.
** b) The merge procedure takes theta of n time to merge a sublist. */