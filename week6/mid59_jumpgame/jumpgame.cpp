#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <array>

class node_t{
    public:
    int index;
    int height;
};

int main(void){
    int N{},K{};
    std::cin>>N>>K;
    std::vector<std::vector<int>> map{};
    map.resize(N);
    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){
            int input{};
            std::cin>>input;
            map.at(i).push_back(input);
        }
    }

    std::vector<std::list<node_t>> graph{};
    graph.resize(N*N);

    int node_index{0};

    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){                             //up down left right
            if((i - 1) >= 0 && map.at(i-1).at(j) <= map.at(i).at(j) + K){
                graph.at(node_index).push_back({node_index - N,map.at(i-1).at(j)});
            }
            if((i + 1 < N) && map.at(i + 1).at(j) <= map.at(i).at(j) + K){
                graph.at(node_index).push_back({node_index + N,map.at(i+1).at(j)});
            }
            if((j - 1 >= 0) && map.at(i).at(j-1) <= map.at(i).at(j) + K){
                graph.at(node_index).push_back({node_index - 1,map.at(i).at(j-1)});
            }
            if((j + 1 < N) && map.at(i).at(j + 1) <= map.at(i).at(j) + K){
                graph.at(node_index).push_back({node_index + 1,map.at(i).at(j+1)});
            }
            node_index++;
        }
    }
    
    std::array<int,400> visited{};
    std::queue<int> Q{};
    Q.push(0);
    while(!Q.empty()){
        int u = Q.front();
        if(visited[u] == 0){
            //printf("u = %d\n",u);
            visited[u] = 1;
            for(auto node : graph.at(u)){
                if(node.height == map[N-1][N-1]){
                    std::cout<<"yes\n";
                    return 0;
                }
                Q.push(node.index);
            }
        }
        Q.pop();
    }
    std::cout<<"no\n";

    return 0;
}