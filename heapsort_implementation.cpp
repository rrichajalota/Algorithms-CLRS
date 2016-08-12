/* 	Heapsort Implementation 

	1.First build a maxheap. O(n) time complexity.
	2.Then swap the maximum element(at index 0) with the last element of the heap. O(1) time
	3.Reduce the heapsize and call maxheapify() for 0th index. O(logn) time 
	4.Repeat the process from step 2 till heapsize > 1.
	
	So overall time-complexity - 
		Initially we build a maxheap which takes O(n) time. Then for every element in the heap, we run a loop which takes O(logn) time.
		Thus, time complexity is O(n) + O(nlogn) = O(nlogn). 
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y){
	int temp= *x;
	*x= *y;
	*y= temp;
}

void maxheapify(vector<int> &inputarr, int index, int heapsize){
	
	int l= 2 * index + 1;
	int r= 2 * index + 2;
	int largest= index;
	
	if( l < heapsize && inputarr[l] > inputarr[largest])
		largest= l;
		
	if( r < heapsize && inputarr[r] > inputarr[largest])
		largest= r;
		
	if(largest != index){
		swap(&inputarr[index], &inputarr[largest]);
		maxheapify(inputarr, largest, heapsize);
	}
	
}

void heapsort(vector<int> &inputarr){
	
	int heapsize= inputarr.size();
	
	for (int i = (heapsize-1)/2 ; i >= 0; --i){	//build maxheap
		maxheapify(inputarr,i, heapsize);
	}
	
	while(heapsize > 1){					// put the max elements at the end of the array
		swap(&inputarr[0], &inputarr[heapsize-1]);
		--heapsize;
		maxheapify(inputarr, 0, heapsize);
	}
}
int main() {
	int size;
	cin>>size;
	vector<int> inputarr(size);
	
	for(int i =0; i < size; i++){
		cin>>inputarr[i];
	}	// inputarr[] = { 5, 3, 6, 1, 0, 7, 4}

	heapsort(inputarr);
	
	cout<<endl;
	
	for(int i= 0; i < size; i++){
		cout<<inputarr[i]<<" ";
	}
	return 0;
}