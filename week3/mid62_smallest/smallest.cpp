#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

int main(void){
	int N {},Q{};
	std::cin>>N>>Q;
	std::vector<long> v {};
	for(int i = 0;i<N;++i){
		long input {};
		std::cin>>input;
		v.push_back(input);
	}	
	int T {},k{},j{};
	for(int i = 0;i<Q;++i){
		std::cin>>T;
		switch(T){
			case 1:{
				std::cin>>j;
				long min = LONG_MAX;
				for(int index = 0;index<j;++index){
					if(v.at(index) < min)
						min = v.at(index);
				}
				std::cout<<min<<std::endl;
				break;
			}case 2:{
				std::cin>>k;
				int index = 0;
				while(index < v.size() && v.at(index) >= k )
					++index;
				std::cout<<index<<std::endl;
			}
		}
	}

}