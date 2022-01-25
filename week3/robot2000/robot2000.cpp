#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
int main(void){
	std::string commands{};
	std::cin>>commands;
	std::vector<char> final {};
	int direction = 0;   // 0 = North, 1 = East , 2 = South , 3 West , 4 = return to 0 0
	for(auto command:commands){
		int command_int {};
		switch(command){
			case 'N': command_int = 0; break;
			case 'E': command_int = 1; break;
			case 'S': command_int = 2; break;
			case 'W': command_int = 3; break;
			case 'Z': command_int = 4; break;
		}
		if(command_int != 4){
			while(direction%4 != command_int){
				final.push_back('R');
				direction++;
			}
			final.push_back('F');
		}else{
			final.push_back('Z');
			direction = 0;
		}
	}
	for(auto ans : final)
		std::cout<<ans;
}