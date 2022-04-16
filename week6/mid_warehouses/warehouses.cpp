#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> graph{};
int bfs(int start,int find);
int main(void){
    int N{},M{},K{};
    std::cin>>N>>M>>K;
    graph.resize(N);
    for(int i = 0;i<M;++i){
        int A{},B{};
        std::cin>>A>>B;
        graph.at(A-1).push_back(B-1);
        graph.at(B-1).push_back(A-1);
    }

    for(int i = 0;i<K;++i){
        int start{},end{};
        std::cin>>start>>end;
        std::cout<<bfs(start-1,end-1)<<std::endl;
    }
    return 0;


}





int bfs(int start,int find){
    std::vector<int> visited{};
    visited.resize(graph.size());
    std::queue<int> q{};
    q.push(start);
    while(!q.empty()){
        int exact = q.front();
        if(visited[exact] == 0){
            q.pop();
            visited[exact] = 1;
            for(int node : graph.at(exact)){
                if(visited[node] == 0){
                    q.push(node);
                }
            }
            continue;
        }
        q.pop();

    }
    
    if(visited[find] == 1){
        return 1;
    }else{
        return 0;
    }

}