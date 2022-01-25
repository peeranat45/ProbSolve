#include <iostream>
#include <list>
#include <algorithm>

int main(void){
	int commands_num{};
	std::list<int> list_num (2);
	std::cin>>commands_num;
	char command {};
	int num{};
	for(int i = 0;i<commands_num;++i){
		std::cin>>command;
		std::cin>>num;
		// std::list<int>::iterator it = list_num.begin();
		// switch(command){
		// 	 case 'I': list_num.push_front(num); break;
		// 	 case 'D': {
		// 	 	if(num > list_num.size())
		// 	 		break;
		// 	 	for(int j = 0;j<num;j++)
		// 	 		it++;
		// 	 	list_num.erase(it);
		// 	 }
		// }
		// printf("command = %c",);
		if(command == 'I'){
			//std::cout<<"I"<<std::endl;
			list_num.push_front(num);
		}else{
			if(num > list_num.size())
			 		continue;
			std::list<int>::iterator it = list_num.begin();
			for(int j = 0;j<num-1;j++)
		 		it++;
			 list_num.erase(it);
		}
	}
	for(auto num:list_num){
		if(num != 0)
			std::cout<<num<<std::endl;
	}
	return 0;
}