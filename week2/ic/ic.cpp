#include <iostream>
#include <list>
#include <algorithm>

int main(void){
	int commands_num {};
	std::list<int> ic_list {};
	std::cin >> commands_num;
	std::string command {};
	int ic_num {};
	for(int i = 0;i<commands_num;++i){
		std::cin>>command;
		//std::cout<<"i = "<<i<<std::endl;
		// switch(command){
		// 	case "li" : ic_list.push_front(ic_num); continue;
		// 	case "ri" : ic_list.push_back(ic_num); continue;
		// 	case "lr" : {
		// 		std::list<int>::iterator it = ic_list.begin();
		// 		ic_list.push_back(*it);
		// 		ic_list.erase(it);
		// 		continue;
		// 	}
		// 	case "rr" : {
		// 		std::list<int>::iterator it = ic_list.end();
		// 		it--;
		// 		ic_list.push_front(*it);
		// 		ic_list.erase(it);
		// 		continue;
		// 	}
		if(command == "li"){
			std::cin>>ic_num;
			ic_list.push_front(ic_num);
		}else if(command == "ri"){
			std::cin>>ic_num;
			ic_list.push_back(ic_num);
		}else if(command == "lr" && ic_list.size() > 0){
			std::list<int>::iterator it = ic_list.begin();
			ic_list.push_back(*it);
			ic_list.erase(it);
			continue;
		}else if(command == "rr" && ic_list.size() > 0){
			std::list<int>::iterator it = ic_list.end();
			it--;
			ic_list.push_front(*it);
			ic_list.erase(it);
			continue;			
		}
	}
	
	for(auto i: ic_list){
		if(i != 0)
			std::cout<<i<<std::endl;
	}
	return 0;
}