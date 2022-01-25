#include <iostream>

int main(void){
	int n,k,t;
	std::cin>>n>>k>>t;
	int count = 0;	
	int index = 0;
	do{
		index += k;
		index %= n;
		count++;
		//std::cout<<index<<std::endl;

	}while(index != (t - 1) && index != 0);
	if(index == (t-1))
		count++;
	std::cout<<count;
	return 0;
}

