#include <iostream>
#include <vector>
#include <list>
#include <utility>

class node_t{
    public:
    int index;
    std::pair<int,int> x1,x2,x3,x4;
};


int main(void){
    int N,M;
    std::cin>>N>>M;
    std::vector<std::vector<char>> map;
    std::vector<std::vector<node_t>> graph;
    map.resize(N);
    for(int i = 0;i<N;++i){
        for(int j = 0;j<M;++j){
            char input;
            std::cin>>input;
            map.at(i).push_back(input);
        }
    }
    int index_node = 0;
    for(int i = 0;i<N-1;++i){
        for(int j = 0;j<M-1;++j){
            if(map.at(i).at(j) == '.' && map.at(i).at(j+1) == '.' && map.at(i+1).at(j) == '.' && map.at(i+1).at(j+1)){
                std::vector<node_t> node_temp;
                node_t temp = {index_node,std::make_pair(i,j),std::make_pair(i,j+1),std::make_pair(i+1,j),std::make_pair(i+1,j+1)};
            }
        }
    }

}


