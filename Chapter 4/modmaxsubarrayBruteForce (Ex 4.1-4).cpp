//brute-force way to find maximum subarray (complexity- O(n^2))
#include <bits/stdc++.h>
using namespace std;

//tuple<int, int, int> maxSubarray(int*, int, int);
struct result{
  int lmax;
  int rmax;
  int maxsum;
} res;

result maxSubarray(int *ar, int low, int high);

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
    int leftInd, rightInd, sum;
    res= maxSubarray(ar,firstInd,lastInd);
    cout<<endl;
    for (i= 0; i< size; i++)           //display array entered
       cout<<ar[i]<<" ";
    cout<<endl;
    if (res.lmax== -1 && res.rmax== -1){
      cout<<"[]"<<endl;
      cout<<res.maxsum;
      return 0;
    }
    for (i=res.lmax; i<= res.rmax ;i++)  //display max-subarray
       cout<<ar[i]<<" ";
    cout<<"\n"<<res.maxsum;
	return 0;
}

result maxSubarray(int *ar, int low, int high){
  int i,j;
  result ret;
  ret.maxsum=0;
  ret.lmax= -1; ret.rmax= -1;
  for(i= low; i<=high; i++){
    int sum= ar[i];

    if (sum >= ret.maxsum){
       ret.maxsum=sum;
       ret.lmax=ret.rmax=i;
      } 
 
    for(j=i+1; j<=high; j++){
      sum=sum+ar[j];
      if(sum >=  ret.maxsum){
        ret.maxsum=sum;
        ret.rmax=j;
        ret.lmax=i;
      }
    }
  }
    return ret;
   //return make_tuple(lmax, rmax, maxsum);
}