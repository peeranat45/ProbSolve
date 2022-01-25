#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>


void print_vector(std::vector<std::vector<int>>);
void print_output(std::vector<std::vector<int>> v,int size);
int main(void){
	int size {};
	std::cin>>size;
	std::vector<std::vector<int>> v{};
	for(int i = 0;i<size;++i){				//setup
		v.push_back({-1,i,-1});
	}
	int x{},y{};
	// print_vector(v);
	for(int i = 1;i<size;++i){
		std::cin>>x>>y;
		x--;
		y--;
		// std::cout<<"x = "<<x<<", y = "<<y<<std::endl;
		v.at(x).at(0) = y; // step 1
		int temp = v.at(y).at(2);
		v.at(y).at(2) = x;
		while(v.at(x).at(2) != -1){
			x = v.at(x).at(2);
		}
		v.at(x).at(2) = temp;
		// print_vector(v);
	}
	print_output(v,size);
	return 0;
}

void print_vector(std::vector<std::vector<int>> v){
	for(auto sub_v : v){
		std::cout<<sub_v.at(0)<<" - "<<sub_v.at(1)<<" - "<<sub_v.at(2)<<std::endl;
	}
	std::cout<<"---------------------------------------------------\n";
}


void print_output(std::vector<std::vector<int>> v,int size){
	int start {};
	for(int i = 0;i<size;++i){
		if(v.at(i).at(0) == -1){
			start = v.at(i).at(1);
		}
	}
	while(v.at(start).at(2) != -1){
		std::cout<<v.at(start).at(1) + 1<<" ";
		start = v.at(start).at(2);
	}
	std::cout<<v.at(start).at(1) + 1; //last one missing
}