#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 10000010

int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<int> min{};
    std::vector<std::vector<std::pair<int,int>>> graph{}; //<des,dis>
    graph.resize(N);
    for(int i = 0;i<N;++i){
        min.push_back(INF);
    }
    for(int i = 0;i<M;++i){
        int A{},B{},W{};
        std::cin>>A>>B>>W;
        graph.at(A-1).push_back({B-1,W});
        graph.at(B-1).push_back({A-1,W});
    }

    min.at(0) = 0;
    std::vector<int> visited{};
    visited.resize(N);
    std::queue<int> Q{};
    Q.push(0);

    while(!Q.empty()){
        int u = Q.front();
        for(auto node : graph.at(u)){
            if(visited.at(node.first) == 0){
                min[node.first] = (node.second < min[node.first]) ? node.second : min[node.first];
            }
        }
        visited.at(u) = 1;
        Q.pop();
        int min_dis = 9999999;
        for(int  j = 0;j<N;j++){
            if(min.at(j) < min_dis && visited.at(j) == 0){
                min_dis = min.at(j);
                u = j;
            }
        }
        if(min_dis != 9999999){
            Q.push(u);
        }
        
    }
    int sum = 0;
    for(int num : min){
        //std::cout<<num<<std::endl;
        sum += num;
    }
    std::cout<<sum<<std::endl;

    return 0;
}