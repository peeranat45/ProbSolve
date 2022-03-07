#include <iostream>
#include <vector>
#include <utility>

class node_t{
    public:
    int node_index;
    int shortest_dis;
    int parent;
};
 
int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<int> priority_queue{};
    priority_queue.resize(N);
    std::vector<std::vector<std::pair<int,int>>> graph{};
    graph.resize(N);
    for(int i = 0;i<M;++i){
        int A{},B{},W{};
        std::cin>>A>>B>>W;
        graph.at(A-1).push_back({B-1,W});
        graph.at(B-1).push_back({A-1,W});
    }
    
}