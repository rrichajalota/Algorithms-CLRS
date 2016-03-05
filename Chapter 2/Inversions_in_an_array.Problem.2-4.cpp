// number of inversions in an array
#include <bits/stdc++.h>
using namespace std;

int MergeSort(int*, int, int, int);
int merge(int*, int, int, int); 
int insertionSort(int*, int, int);

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

    int inv=MergeSort(ar,firstInd,lastInd,k);
    
    cout<<endl;
    cout<<inv<<endl;
    for (i= 0; i< size; i++)
       cout<<ar[i]<<" ";  
	return 0;
}
int MergeSort(int *ar, int firstInd, int lastInd, int k){
   int inv=0, inv1=0, inv2=0;
   int size= lastInd- firstInd+1; 
   int mid= (firstInd+lastInd)/2;
  
   if(size > k){
     inv=MergeSort(ar, firstInd, mid,k);
     inv=MergeSort(ar, mid+1, lastInd,k);
     inv1=inv1+merge(ar, firstInd, mid, lastInd);
  }
  else
    inv2=inv2+insertionSort(ar,firstInd, lastInd);
  return inv1+inv2;
}

int merge(int *ar, int firstInd, int mid, int lastInd){
 int inv=0;
 int i,j;
 int size1= mid-firstInd+1;  
 int size2= lastInd- mid;

 int *left= new (nothrow) int[size1];  //dynamically create 2 new arrays of size1+1 and size2+1, resptly. 
 int *right= new (nothrow) int[size2];

 if( left==NULL && right==NULL)
    return 0;
 
 for(i=0; i< size1; i++){
   left[i]= ar[firstInd+i];
 }
 for(j=0; j< size2 ;j++){
   right[j]= ar[mid+1+j];
 }
// left[i]= INT_MAX;
 //right[j]= INT_MAX;
  
 i=j=0;
 int k = firstInd;
  while( k <=lastInd && i < size1 && j < size2){
    if (left[i] <= right[j]){
      ar[k]= left[i];
       i++; k++;
    }
  else if(left[i] > right[j]){
    inv= inv+ size1-i;
    ar[k]= right[j];
    j++; k++;
  }
}
 while( k<=lastInd && i == size1 && j < size2){
      ar[k]= right[j];
      j++; k++;
   }
while( k<=lastInd && j == size2 && i < size1){
      ar[k]= left[i];
      i++; k++;
  }
return inv;
}

int insertionSort(int *ar, int beg, int end){
 int inv=0;
 int i,j;
 for (j=beg+1; j<=end; j++){

   int key= ar[j];
   i = j-1;

   while( i>= beg && ar[i]>key){
     inv++;
     ar[i+1]= ar[i];
     i--;
   }
   ar[i+1]= key;  
 }
return inv;
}
/* a) Insertion sort takes theta of (k^2) time to sort one sublist. Thus to sort n/k sublists it takes theta of (nk) time. {as k^2 * n/k = nk}.
** b) The merge procedure takes theta of n time to merge a sublist. */