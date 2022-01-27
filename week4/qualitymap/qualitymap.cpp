#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <array>

class node_t{
    public:
    int index;
    char chr;
};

void printGraph(std::vector<std::list<node_t>> graph);

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

    std::vector<std::list<node_t>> graph{};
    graph.resize(N*M);
    std::array<int,900> visited{};
    int node_index = 0;
    for(int i = 0;i<N;++i){                         
        for(int j = 0;j<M;++j){     
            if(map.at(i).at(j) == '#'){
                visited.at(node_index) = 1;
                node_index += 1;
                continue;
            }
            if((i - 1 >= 0) && map.at(i -1).at(j) != '#'){                                     // up down left right
                graph.at(node_index).push_back({node_index - M,map.at(i-1).at(j)});
            }
            if((i + 1 < N) && map.at(i + 1).at(j) != '#'){
                graph.at(node_index).push_back({node_index + M,map.at(i+1).at(j)});
            }
            if((j - 1 >= 0) && map.at(i).at(j-1) != '#'){
                graph.at(node_index).push_back({node_index - 1,map.at(i).at(j-1)});
            }
            if((j + 1 < M) && map.at(i).at(j+1) != '#'){
                graph.at(node_index).push_back({node_index + 1,map.at(i).at(j+1)});
            }
            node_index += 1;                                                
        }
        

    }
    //printGraph(graph);

    int count_node_visited {0};
    int level2 {0};
    int level1 {0};
    std::queue<int> Q{};
    int i = 1;
    while(true){
        int finish = 1;
        for(int i = 0;i<N*M;++i){
            if(visited[i] == 0){
                Q.push(i);
                finish = 0;
                goto label1;
            }
        }
        label1:

        if(finish == 1){
            break;
        }
        int count{0};
        int dollar = 0;
        int astrik = 0;
        //printf("Area %d\n",i);
        ++i;
        while(!Q.empty()){
            int u = Q.front();
            if(visited[u] == 0){
                //printf("u = %d\n",u);
                visited[u] = 1;
                count++;
                for(auto node : graph.at(u)){
                    if(node.chr == '*')
                        astrik = 1;
                    if(node.chr == '$')
                        dollar = 1;
                    Q.push(node.index);
                }
            }
            Q.pop();

        }
        //printf("Count = %d\n",count);
        if(dollar == 1 && astrik == 1){
            level2 += count;
        }else if(dollar == 1 || astrik == 1){
            level1 += count;
        }
    }
    std::cout<<level2<<" "<<level1<<std::endl;
    return 0;
}

void printGraph(std::vector<std::list<node_t>> graph){
    int i = 0;
    for(auto lst : graph){
        std::cout<<i<<" : ";
        for(auto node : lst){
            std::cout<<"("<<node.index<<","<<node.chr<<") ->";
        }
        ++i;
        std::cout<<std::endl;
    }
}
