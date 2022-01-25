#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>

class node_t{
    public:
    int index;
    int height;
};

void printGraph(std::vector<node_t> node_list,std::vector<std::list<int>> graph);

int main(void){
    int N{},K{};
    std::cin>>N>>K;
    std::vector<std::list<int>> graph{};
    std::vector<node_t> node_list{};
    graph.resize(N*N);
    int indexGraph {0};
    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){
            int height{};
            std::cin>>height;
            node_list.push_back({indexGraph,height});
            //std::cout<<"indexGraph = "<<indexGraph<<std::endl;
            
            if(indexGraph - N >= 0){ ///add upper and down
                if(node_list.at(indexGraph - N).height < node_list.at(indexGraph).height || ((node_list.at(indexGraph - N).height - node_list.at(indexGraph).height) <= K)){
                   // printf("Up,down\n");
                    graph.at(indexGraph).push_back(indexGraph - N);
                    if(node_list.at(indexGraph).height - node_list.at(indexGraph - N).height <= K)
                        graph.at(indexGraph - N).push_back(indexGraph);
                }
            }
            //printf("F\n");
           // add left and right
            if(indexGraph%4 != 0){
                if(node_list.at(indexGraph - 1).height < node_list.at(indexGraph).height || node_list.at(indexGraph - 1).height - node_list.at(indexGraph).height <= K){
                    //printf("Left,right\n");
                    graph.at(indexGraph).push_back(indexGraph - 1);
                    if(node_list.at(indexGraph).height - node_list.at(indexGraph - 1).height <= K)
                        graph.at(indexGraph - 1).push_back(indexGraph);
                }
            }
            
            indexGraph++;
        }
        
    }
    //printGraph(node_list,graph);

    //bfs
    std::vector<int> visited{};
    visited.resize(N*N);
    std::queue<int> Q{};
    Q.push(0);
    while(!Q.empty()){
        
        int n = Q.front();
       // printf("n = %d ",n);
        //printf("G");
        if(n == (N*N) - 1 ){
            std::cout<<"yes\n";
            return 0;
        }
        if(visited.at(n) != 1){
            visited.at(n) = 1;
            for(auto index : graph.at(n)){
                Q.push(index);
            }

        }
        Q.pop();
    }
    printf("no\n");
    return 0;
}


void printGraph(std::vector<node_t> node_list,std::vector<std::list<int>> graph){
    for(auto node : node_list){
        std::cout<<node.index<<" : ";
        for(auto num : graph.at(node.index)){
            std::cout<<num<<"->";
        }
        std::cout<<std::endl;
    }
}