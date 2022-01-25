#include <iostream>
#include <array>
#include <algorithm>
#include <utility>

const int MAX_ARR {310};

int main(void){
	int L {}, N{};
	std::cin>>L>>N;
	std::array<int,MAX_ARR> arr{};
	for(int i = 0;i<N;++i){
		int A{},B{};
		std::cin>>A>>B;
		for(int j = A;j<B;++j){
			arr.at(j) += 1;
		}
	}
	auto it = arr.begin();
	std::cout<<*std::max_element(it,it + 309);
	return 0;
}