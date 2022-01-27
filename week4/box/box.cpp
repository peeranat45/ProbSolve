#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <queue>

void printGraph(std::vector<std::list<int>> graph);

int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<std::vector<char>> map{};
    map.resize(N);
    for(int i = 0;i<N;++i){
        for(int j = 0;j<M;++j){
            char input{};
            std::cin>>input;
            map.at(i).push_back(input);
        }
    }


    std::vector<std::list<int>> graph{};
    graph.resize(N*M);
    int node_index{0};
    std::vector<int> startIndex{};
    std::vector<int> finishIndex{};    
    for(int i = 0;i<N-1;++i){
        for(int j = 0;j<M-1;++j){        
            //printf("i = %d, j = %d, node_index = %d\n",i,j,node_index); 
                    // up down left right
            if(map.at(i).at(j) == '.' && map.at(i).at(j+1) == '.' && map.at(i + 1).at(j) == '.' && map.at(i+1).at(j+1) == '.'){
                //printf("i = %d, j = %d, node_index = %d\n",i,j,node_index); 
                if(i == 0){
                    startIndex.push_back(node_index);
                }
                if(i == N - 2){
                    finishIndex.push_back(node_index);
                }

                if((i-1)>= 0 && map.at(i-1).at(j) == '.' && map.at(i-1).at(j+1) == '.' && map.at(i).at(j) == '.' && map.at(i).at(j+1) == '.'){
                    graph.at(node_index).push_back(node_index - M +1);
                }
                if((i+2) < N && map.at(i+1).at(j) == '.' && map.at(i+1).at(j+1) == '.' && map.at(i+2).at(j) == '.' && map.at(i+2).at(j+1) == '.'){
                    graph.at(node_index).push_back(node_index + M - 1);
                }
                if((j-1)>= 0 && map.at(i).at(j-1) == '.' && map.at(i).at(j) == '.' && map.at(i+1).at(j-1) == '.' && map.at(i+1).at(j) == '.'){
                    graph.at(node_index).push_back(node_index - 1);
                }
                if((j+2) < M && map.at(i).at(j+1) == '.' && map.at(i).at(j+2) == '.' && map.at(i+1).at(j+1) == '.' && map.at(i+1).at(j+2) == '.'){
                    graph.at(node_index).push_back(node_index + 1);
                }
                
            }
            node_index++;
            
        }
        

    }
    //printGraph(graph);

    while(!startIndex.empty()){
        int start = startIndex.front();
        startIndex.erase(startIndex.begin());
        std::queue<int> Q{};
        Q.push(start);
        std::array<int,900> visited{};
        while(!Q.empty()){
            int u = Q.front();
            if(visited[u] == 0){
                visited[u] = 1;
                for(auto node : graph.at(u)){
                    Q.push(node);
                    for(auto final_node : finishIndex){
                        if(node == final_node){
                            std::cout<<"yes\n";
                            return 0;
                        }
                    }
                }
            }
            Q.pop();
        }
    }
    std::cout<<"no\n";
    return 0;

}

void printGraph(std::vector<std::list<int>> graph){
    int index = 0;
    for(auto lst : graph){
        std::cout<<index<<":";
        for(auto node : lst){
            std::cout<<node<<"->";
        }
        index++;
        std::cout<<std::endl;
    }
}