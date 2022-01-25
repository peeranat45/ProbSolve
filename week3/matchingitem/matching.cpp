#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAXARR 100010

long arr[MAXARR];

int main(void){
	long N {},Q{};
	std::cin>>N>>Q;
	std::vector<long> items {};
	for(long i = 0;i<N;i++){
		long input{};
		std::cin>>input;
		arr[i] = input;
        std::cout<<"Hello";
	}
    // std::cout<<"Done"<<std::endl;

	for(long i = 1;i<=Q;i++){
		long X{},Y{};
		std::cin>>X>>Y;
		long j {};
		for(j = 0;items.at(X-1) + Y >= items.at(j);++j){
            //std::cout<<"j = "<<j<<std::endl;
        }
		std::cout<<j<<std::endl;
	}
}