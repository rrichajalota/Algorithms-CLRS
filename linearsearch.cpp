//Linear Search
#include <bits/stdc++.h>
using namespace std;

int Lsearch(int *ar, int size, int ele){
 int i=0;
 while(i < size){
  if(ar[i]==ele)
   return i+1;
  else i= i+1;
 }
 return -1;
}

int main(){
int size,i,ele;
int *ar;
cin>>size;
ar= new (nothrow) int[size];  // dynamically create an array
if (ar== NULL)
  return 0;
else{
   for (i=0; i<size; i++)
     cin>>ar[i];
   }
 cin>>ele; //enter the element to be searched 
 cout<<"\n"<<Lsearch(ar,size,ele);  
 return 0;
 }
 // loop invariant: At the start of each iteration of the while loop, the subarray ar[0..i-1] does not contain the element ele 