#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

struct pair {
	long index, num;
};

bool comparePair(pair p1,pair p2){
	return p1.num < p2.num;
}

int main(void){
	long N {},count {1};
	std::cin>>N;
	std::vector<pair> v{};
	for(long i = 0;i<4;++i){
		pair max = {0,0};
		for(long j = 0;j<N;++j){
			long input{};
			std::cin>>input;
			if(input > max.num){
				max.index = count;
				max.num = input;
				//prlongf("Max is %d at index %d\n",max.num,max.index);
			}
			count++;
		}
		//printf("Max is %d at index %d\n",max.num,max.index);
		v.push_back(max);
	}
	std::sort(v.begin(),v.begin()+2,comparePair);
	std::sort(v.begin()+2,v.begin()+4,comparePair);
	if(v.at(1).num > v.at(3).num){
		std::cout<<v.at(1).index<<" "<<v.at(3).index<<" ";
	}else{
		std::cout<<v.at(3).index<<" "<<v.at(1).index<<" ";
	}
	std::cout<<v.at(0).index<<" "<<v.at(2).index;
	return 0;
}