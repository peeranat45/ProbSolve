#include <iostream>


int main(void){
	int n = 0;
	std::cin>>n;
	int sum = 0;
	for(int i = 0;i<n;++i){
		int temp = 0;
		std::cin>>temp;
		if(temp > 0){
			sum += temp;
		}
	}
	std::cout<<sum<<std::endl;
	return 0;
}