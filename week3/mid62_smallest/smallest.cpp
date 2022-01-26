#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
#define MAX_ARR 200010
int student_height[MAX_ARR];
int min_student_height[MAX_ARR];

int binarySearch(int start, int stop,int num);

int main(void){
	int N,Q,min = 99999999;
	std::cin>>N>>Q;
	for(int i = 0;i<N;++i){
		std::cin>>student_height[i];
		if(student_height[i] < min){
			min = student_height[i];
		}
		min_student_height[i] = min;
	}
	for(int i = 0;i<Q;++i){
		int input;
		std::cin>>input;
		switch(input){
			case 1:{
				int temp;
				std::cin>>temp;
				std::cout<<min_student_height[temp-1]<<std::endl;
				break;
			}
			case 2:{
				int temp;
				std::cin>>temp;
				if(temp > min_student_height[0]){
					std::cout<<0<<std::endl;
					break;
				}
				temp = binarySearch(0,N-1,temp);
				std::cout<<temp + 1<<std::endl;
				break;
			}

		}
	}
}

int binarySearch(int start, int stop,int num){
	if(start > stop){
		return stop;
	}
	
	int mid = (start + stop)/2;
	//printf("start = %d, stop = %d, mid = %d, num = %d\n",start,stop,mid,num);
	if(num < min_student_height[mid]){
		return binarySearch(mid + 1,stop,num);
	}else if(num > min_student_height[mid]){
		return binarySearch(start,mid - 1,num);
	}else if(num == min_student_height[mid] && min_student_height[mid + 1] == num){
		return binarySearch(mid + 1,stop,num);
	}else{
		return mid;
	}
	
	return  -1;
}