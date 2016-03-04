//find maximum subarray- using divide and conquer 
/* given an array of integers, find the maximum, contiguous subarray with the largest sum
** input: -9 0 8 -4 -3 -7 2
** output: 0 8 sum= 8
*/
#include <bits/stdc++.h>
using namespace std;

struct result{
   int low;
   int high;
   int sum;
 };
result maxSubarray(int* ar, int low, int high);
result maxcrossing(int *ar,int low, int mid, int high);
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
    //int leftInd, rightInd,sum;
    result res;
    res =maxSubarray(ar,firstInd,lastInd);
      
    cout<<endl;
    for (i= 0; i< size; i++)           //display array entered
       cout<<ar[i]<<" ";
    cout<<endl;
    if(res.low== -1 && res.high== -1){
      cout<<"[]"<<endl;
      cout<<0;
      return 0;
    }
    for (i=res.low; i<= res.high ;i++)  //display max-subarray
       cout<<ar[i]<<" ";
    cout<<"\n"<<res.sum;
	return 0;
}

result maxSubarray(int* ar, int low, int high){
  
  result ret;
  if(low==high){
    ret.low= low;
    ret.high= high;
    ret.sum= ar[low];
    return ret;
  }
  result lret, rret, cret;
  //int llow, lhigh,lsum, rlow,rhigh,rsum,clow,chigh,csum;
  int mid= (low+high)/2;
  
  lret= maxSubarray(ar, low, mid);
  rret= maxSubarray(ar, mid+1, high);
  cret= maxcrossing(ar, low, mid, high);
  
  if((lret.sum >= rret.sum) && (lret.sum>=cret.sum)){
    ret.low= lret.low;
    ret.high= lret.high;
    ret.sum= lret.sum;
    return ret;
  }
  else if((rret.sum >=lret.sum) && (rret.sum>=cret.sum)){
    ret.low= rret.low;
    ret.high= rret.high;
    ret.sum= rret.sum;
    return ret;
  }
  else{
    ret.low= cret.low;
    ret.high= cret.high;
    ret.sum= cret.sum;
    return ret;
  }
}     

result maxcrossing(int *ar,int low, int mid, int high){
  result let, ret,set;
  let.sum= 0;
  int sum=0;
  let.low= -1;
  //int lmax, rmax,sum=0;
  int i,j;
  
  for(i=mid; i>=low; i--){
    sum= sum+ar[i];
    if (sum > let.sum){
       let.sum= sum;
       let.low= i;
    }
  }
  ret.sum=0;
  ret.high= -1;
  sum=0;
   for(j=mid+1; j<=high; j++){
    sum= sum+ar[j];
    if (sum > ret.sum){
       ret.sum= sum;
       ret.high= j;
    }
  }
  set.low= let.low;
  set.high= ret.high;
  set.sum= let.sum+ret.sum;
  return set;
 
}