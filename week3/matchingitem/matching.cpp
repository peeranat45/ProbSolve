#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAXARR 100010

long arr[MAXARR];


int binarySearch(int start,int stop,int num);

int main(void){
	int N,Q;
	std::cin>>N>>Q;
	for(int i = 0;i<N;++i){
		std::cin>>arr[i];
	}
	for(int i  = 0;i<Q;++i){
		int px,x;
		std::cin>>px>>x;
		int ans = binarySearch(0,N-1,arr[px-1] + x);
		if(ans >= N){
			ans = N - 1;
		}
		std::cout<<ans+ 1<<std::endl;
	}
	return 0;
}

int binarySearch(int start,int stop,int num){	
	if(stop < start){
		if(arr[start] > num)
			return start - 1;
		return start;
	}
	int mid = (start + stop)/2;

	if(num > arr[mid]){
		return binarySearch(mid + 1,stop,num);
	}else if(num < arr[mid]){
		return binarySearch(start,mid - 1,num);
	}else{
		return mid;
	}
}	