#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>
#include <vector>

int main(void){
	int input {};
	std::cin>>input;
	while(input != 0){
		while(true){
			std::stack<int> stations_stack {};
			int current_trains = 1;
			bool status = true;
			std::vector<int> check_input_trains {};
			for(int i = 0;i<input;++i){
				int temp {};
				std::cin>>temp;
				if(temp == 0)
					goto input_trains_num;
				check_input_trains.push_back(temp);
			}
			std::vector<int>::iterator input_trains = check_input_trains.begin();
			while((!stations_stack.empty())|| (current_trains < input)){
				if(*input_trains == current_trains && current_trains < input){
					current_trains++;
					input_trains++;
				}else if((!stations_stack.empty())&& *input_trains == stations_stack.top()){
					stations_stack.pop();
					input_trains++;
				}else if(current_trains <= input ){
					stations_stack.push(current_trains);
					current_trains++;
				}else{
					status = false;
					goto status_check;
				}
			}
			status_check:
			if(status == false){
				std::cout<<"No"<<std::endl;
			}else{
				std::cout<<"Yes"<<std::endl;
			}
		}
		
		input_trains_num:
			std::cin>>input;
		printf("\n");
	}
	return 0;
}