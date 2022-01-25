#include <iostream>
#include <list>
#include <algorithm>
#include <utility>
#include <vector>

int main(void){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
	int commands_num {};
	std::vector<std::list<int>> stations;
	stations.resize(100001);
	std::cin>>commands_num;	
	int i{},j{},x{};
	char command {};
	for(int index = 0;index<commands_num;++index){
		std::cin>>command;
		switch(command){
			case 'N': {
				std::cin>>x>>i;
				stations.at(i).push_back(x);
				//print_terminal(stations);
				continue;
			}
			case 'M':{
				std::cin>>i>>j;
                //stations.at(j).insert(stations.at(j).end(),stations.at(i).begin(),stations.at(i).end());
				std::list<int> ::iterator it = stations.at(j).end();
				stations.at(j).splice(it,stations.at(i));
				stations.at(i).clear();
				continue; //platform[j].splice(platform[j].end(),platform[i]);
				
			}
		}
	}
	for(auto terminal : stations){
		for(auto trains : terminal){
		  if(trains == 0)
				break;
			std::cout<<trains<<"\n";
		}
	}
	return 0;
}