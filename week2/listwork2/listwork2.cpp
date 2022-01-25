#include <iostream>
#include <list>
#include <algorithm>

int main(void){
	int commands_num {};
	std::list<int> list_num {};
	std::cin>>commands_num;
	char command {};
	int input {};
	for(int i = 0;i<commands_num;++i){
		std::cin>>command>>input;
		switch(command){
			case 'A': list_num.push_back(input); continue;
			case 'I': list_num.push_front(input);continue;
			case 'D': {
				if(input > (int)list_num.size())
					continue;
				std::list<int>::iterator it = list_num.begin();
				for(int j = 0;j<input-1;++j)
					it++;
				list_num.erase(it);
			}
		}
	}
	for(auto num:list_num){
		if(num != 0)
			std::cout<<num<<std::endl;
	}
	return 0;
}