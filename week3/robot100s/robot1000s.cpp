#include <iostream>
#include <vector>
#include <string>

int main(void){
    std::string commands{};
    std::cin>>commands;
    std::vector<int> command_count{}; // 0 = N , 1 = E , 2 = S, 3 = W
    command_count.resize(4);
    for(auto command : commands){
        if(command == 'N'){
            command_count.at(0) += 1;
        }else if(command == 'E'){
            command_count.at(1) += 1;
        }else if(command == 'S'){
            command_count.at(2) += 1;
        }else if(command == 'W'){
            command_count.at(3) += 1;
        }
    }
    
}


