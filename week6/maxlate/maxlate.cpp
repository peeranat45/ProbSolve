#include <iostream>
#include <vector>
#include <utility>

bool pairSortSecond(std::pair<int,int> p1,std::pair<int,int> p2){
    return p1.second < p2.second;
}

int main(void){
    int N{};
    std::cin>>N;
    std::vector<std::pair<int,int>> pairs{};
    for(int i = 0;i<N;++i){
        int D{},C{};
        std::cin>>D>>C;
        pairs.push_back({D,C});
    }

    std::sort(pairs.begin(),pairs.end());
    
    
    
}