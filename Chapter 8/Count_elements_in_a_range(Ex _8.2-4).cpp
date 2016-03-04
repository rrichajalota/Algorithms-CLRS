/* Given n integers in the range 0 to k, how many integers fall into a range [a,..,b] in O(1) time. 
** Our algorithm should use theta of (n+k) preprocessing time.
** Solution : We use counting sort mechanism as our preprocessing algorithm.
*/
#include <iostream>
using namespace std;

int count(int *ar, int size, int k, int a, int b);

int main() {
    int size,i,k;   // k stores the range
    int a, b, num;
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
    cin>> a>>b; // enter the range
    num =count(ar,size,k, a,b);
    
    cout<<endl;
    for (i= 0; i< size; i++)
       cout<<ar[i]<<" ";  
    cout<<endl;
    cout<<num;
	return 0;
}
int count(int *ar, int size, int k, int a, int b){
	  int *c = new (nothrow) int[k+1];        
    int *d = new (nothrow) int[k+1];
    int i,j;
    for ( i= 0 ; i<=k ; i++)
      c[i]= 0;
	  for (j=0 ; j < size; j++)  //store the number of occurrences of the elements of ar[] in c[]
      c[ar[j]] = c[ar[j]]+1;

    d[0] = c[0];                   //the d[] array stores the number of elements greater than or equal to    
    for ( i= 1; i<=k ; i++)       //the index i 
      d[i]= c[i]+d[i-1];

   return (d[b] - d[a] + c[a]);    //takes O(1) time to compute and return the value
}