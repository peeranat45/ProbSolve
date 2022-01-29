#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

class node_t{
    int index;
    char chr;
};

int main(void){
    int N{},Q{};
    std::cin>>N>>Q;
    std::vector<std::vector<char>> map{};
    map.resize(N);
    for(int i = 0;i<N;++i){
        for(int j = 0;i<N;++j){
            char input{};
            map.at(i).push_back(input);
        }
    }

    std::vector<std::list<node_t>> graph{};
    
}