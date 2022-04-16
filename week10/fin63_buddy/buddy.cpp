#include <iostream>
#include <vector>


int main(void){
    int N{};
    std::cin>>N;
    std::vector<int> visited{};
    std::vector<int> buddys{};
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        buddys.push_back(input);
        visited.push_back(0);
    }
    int visited_count = 0;
    while(visited_count < visited.size()){
        int i = 0;
        for(i = 0;i<visited.size();++i){
            if(visited.at(i) == 0){
                break;
            }
        }
        
    }
}