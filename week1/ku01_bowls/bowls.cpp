#include <iostream>
#include <time.h>

int counts[302];

int main(void){
	// time_t begin,end;
	// time(&begin);
	for(int i = 0;i<302;i++)
		counts[i] = 0;
	int n = 0;
	std::cin>>n;
	for(int i = 0;i<n;i++){
		int temp = 0;
		std::cin>>temp;
		counts[temp] += 1;
	}
	int max = counts[0];
	for(int i = 0;i<302;i++){
		if(counts[i] > max)
			max = counts[i];
	}

	// time(&end);

	// time_t elapsed = end - begin;
	//std::cout<<"Runtime = "<<elapsed<<std::endl;

	std::cout<<max<<std::endl;

	return 0;
}
