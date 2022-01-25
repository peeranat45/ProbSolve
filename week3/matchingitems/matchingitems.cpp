#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <array>
#include <stdio.h>
int items[1000000];
int main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long N {},Q{};
	std::cin>>N>>Q;
	
	for(long long i = 0;i<N;i++){
		long long input{};
		std::cin>>input;
		items[i] = input;
	}

	for(long long i = 0;i<Q;i++){
		long long X{},Y{};
		std::cin>>X>>Y;
		long long j = 0;
		while(items[j] != 0){
			if(items[j] > items[X] + Y){
				break;
			}
			j++;
		}
		j--;
		std::cout<<j<<'\n';
	}
    return 0;
}