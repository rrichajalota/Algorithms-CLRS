//insertion sort on array

#include <bits/stdc++.h>
using namespace std;

void isort(int ar[]){
	int i,j;
	for (j=1; j< 10; j++){
	  int key= ar[j];
	  i= j-1;
	  while(i >-1 && ar[i]>key){
	    ar[i+1]= ar[i];
	    i=i-1;
	  }
	  ar[i+1]=key;
	}
	for(j=0; j<10; j++)
	  cout<<ar[j]<<" ";
}

int main(){
	int ar[10]={8,3,5,1,6,9,0,2,1,7};
	isort(ar);
	return 0;
}

