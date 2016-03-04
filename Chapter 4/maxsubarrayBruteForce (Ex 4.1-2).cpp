//brute-force way to find maximum subarray (complexity- O(n^2))
#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> maxSubarray(int*, int, int);

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
    int leftInd, rightInd,sum;

    tie(leftInd,rightInd,sum) =maxSubarray(ar,firstInd,lastInd);
      
    cout<<endl;
    for (i= 0; i< size; i++)           //display array entered
       cout<<ar[i]<<" ";
    cout<<endl;
    for (i=leftInd; i<= rightInd ;i++)  //display max-subarray
       cout<<ar[i]<<" ";
    cout<<"\n"<<sum;
	return 0;
}

tuple<int, int, int> maxSubarray(int *ar, int low, int high){
  int i,j,lmax,rmax;
  int maxsum=INT_MIN;
  for(i= low; i<=high; i++){
    int sum= ar[i];

    if (sum> maxsum){
       maxsum=sum;
       lmax=rmax=i;
      } 
 
    for(j=i+1; j<=high; j++){
      sum=sum+ar[j];
      if(sum>maxsum){
        maxsum=sum;
        rmax=j;
        lmax=i;
      }
    }
  }
   return make_tuple(lmax, rmax, maxsum);
}