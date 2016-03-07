/* Counting Sort- basic implementation
** This sorting technique assumes all the elements in the array lie in range [0,...,k].
*/
#include <iostream>
using namespace std;

void countingSort(int *ar, int size, int k);

int main() {
    int size,i,k;   // k stores the range i.e. the max value entered 
    int *ar;
    cin>>size;
    cin>>k;
    ar= new (nothrow) int[size];  // dynamically create an array
   
    if (ar== NULL)
      return 0;

    else{
    for (i=0; i<size; i++)
     cin>>ar[i];
    }

    countingSort(ar,size,k);
    
	return 0;
}
void countingSort(int *ar, int size, int k){
	  int *c = new (nothrow) int[k+1];      // array c[] for temporary storage
    int *b = new (nothrow) int[size];     // array b[] to store output 
    
    int i,j;

    for ( i= 0 ; i<=k ; i++)             // initialize the entire array c[] with 0
      c[i]= 0;

	  for (j=0 ; j < size; j++)            // store the number of occurences of the elements of array ar[] in the corresponding indices of array c[]
      c[ar[j]] = c[ar[j]]+1;             // Eg: if 3 occurs twice and 4 occurs once in ar[], then at the end of the loop c[3]= 2, c[4]= 1

    for ( i= 1; i<=k ; i++)              // The ith position of array c[] will now contain the number of elements less than or equal to i.
      c[i]= c[i]+c[i-1];                 

    for ( j= size-1 ; j >= 0 ; --j){     // loop to store values in sorted order in the array b[].
	  b[c[ar[j]]-1] = ar[j];
	  c[ar[j]] = c[ar[j]]-1;
    }

    for ( j= 0 ; j< size ; j++)         // print the sorted order
        cout<<b[j]<<" ";
}