//find maximum subarray- using divide and conquer 
/* given an array of integers, find the maximum, contiguous subarray with the largest sum
** input: -9 0 8 -4 -3 -7 2
** output: 0 8 sum= 8
*/
#include <bits/stdc++.h>
using namespace std;

/*struct result{
   int low;
   int high;
   int sum;
   result(int a, int b, int c){
   low=a; high=b; sum=c;
   }
 };
*/

tuple<int, int, int> maxSubarray(int*, int, int);
tuple<int, int, int> maxcrossing(int*, int, int, int);

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

tuple<int, int, int> maxSubarray(int* ar, int low, int high){
  
  if(low==high)
    return make_tuple(low, high, ar[low]);

  int llow, lhigh,lsum, rlow,rhigh,rsum,clow,chigh,csum;
  int mid= (low+high)/2;
  
  tie(llow, lhigh,lsum)= maxSubarray(ar, low, mid);
  tie(rlow, rhigh,rsum)= maxSubarray(ar, mid+1, high);
  tie(clow, chigh,csum)= maxcrossing(ar, low, mid, high);
  
  if((lsum >= rsum) && (lsum>=csum))
     return make_tuple(llow, lhigh, lsum);
  else if((rsum >=lsum) && (rsum>=csum))
     return make_tuple(rlow, rhigh, rsum);
  else 
     return make_tuple(clow, chigh, csum);
}

tuple<int, int, int> maxcrossing(int *ar,int low, int mid, int high){
  int lsum= INT_MIN;
  int lmax, rmax,sum=0;
  int i,j;
   
  for(i=mid; i>=low; i--){
    sum= sum+ar[i];
    if (sum > lsum){
       lsum= sum;
       lmax= i;
    }
  }
  int rsum=INT_MIN;
  sum=0;
   for(j=mid+1; j<=high; j++){
    sum= sum+ar[j];
    if (sum > rsum){
       rsum= sum;
       rmax= j;
    }
  }
  return make_tuple(lmax, rmax, lsum+rsum);
 
}