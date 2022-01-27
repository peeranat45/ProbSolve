#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

const int MAX_ARR {100010};

int indeg[MAX_ARR];
void printGraph(std::vector<std::list<int>> graph);

int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<std::list<int>> graph{};
    graph.resize(N);
    int num_node_in_graph = N;
    for(int i = 0;i<M;++i){
        int u{},v{};
        std::cin>>u>>v;
        graph.at(u-1).push_back(v-1);
        indeg[v-1] += 1;
    }
    bool topo = false;
    std::queue<int> Q{};
    for(int i = 0;i<N;++i){
        if(indeg[i] == 0){
            Q.push(i);
            topo = true;
        }
    }
    if(!topo){
        std::cout<<"no\n"<<std::endl;
        return 0;
    }
    std::vector<int> output{};
    while(num_node_in_graph){
        int u = Q.front();
        Q.pop();
        //printf("u = %d\n",u);
        //printGraph(graph);
        for(auto node : graph.at(u)){
            indeg[node] -= 1;
            //printf("node = %d, indeg = %d\n",node+1,indeg[node]);
            if(indeg[node] == 0){
                Q.push(node);
            }
        }
        output.push_back(u);
        //graph.erase(graph.begin() + u);
        //printf("---------------\n");
        //printGraph(graph);
        num_node_in_graph -= 1;

    }
    for(auto num : output){
        std::cout<<num + 1<<std::endl;
    }
    return 0;
}

void printGraph(std::vector<std::list<int>> graph){
    int i = 1;
    for(auto node : graph){
        std::cout<<i<<":";
        for(auto num : node){
            std::cout<<num + 1<<"->";
        }
        std::cout<<std::endl;
        i += 1;
    }
}