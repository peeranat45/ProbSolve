#include <iostream>
#include <vector>
#include <list>
#include <queue>


class node_t{
    public:
    int index;
    int bridge;
                                   // 0 no color , 1 = blakc , 2 = red
};

class node_status{
    public:
    int visited;
    int layer;
};

class node_queue{
    public:
    int index;
    int bridge_visited;
};

void printGraph(std::vector<std::list<node_t>> graph);

int main(void){
    int N{},M{},S{},T{};
    std::cin>>N>>M>>S>>T;
    std::vector<std::list<node_t>> graph{};
    std::vector<node_status> node_list{};
    for(int i = 0;i<N;++i){
        node_list.push_back({0,0});
    }
    graph.resize(N);
    for(int i = 0;i<M;++i){
        int A{},B{},C{};
        std::cin>>A>>B>>C;
        graph.at(A-1).push_back({B-1,C,});
        graph.at(B-1).push_back({A-1,C,});
    }
    printGraph(graph);

    //BFS
    int bridge_cross = 0;
    std::queue<node_queue> Q{};
    std::vector<int> ans{};
    Q.push({S-1,0});
    while(!Q.empty()){
        int num = Q.front().index;
        if(node_list.at(num).visited == 0){
            node_list.at(num).visited = 1;
            ans.push_back(num);
            for(auto node : graph.at(num)){
                // if(bridge_cross == 0 && node.bridge == 1){
                //     Q.push(node.index);
                //     node_list.at(node.index).layer = node_list.at(num).layer + 1;
                //     bridge_cross = 1;
                // }else if(bridge_cross == 0 && node.bridge == 2){
                //     Q.push(node.index);
                //     bridge_cross = 2;
                // }else if(bridge_cross == 0 && node.bridge == 0){
                //     Q.push(node.index);
                // }
                // continue;

                if(Q.front().bridge_visited == 0 && node.bridge == 1 || node.bridge == 2 ){
                    Q.push({node.index,node.bridge});
                    node_list.at(node.index).layer = node_list.at(num).layer + 1;
                }else if(Q.front().bridge_visited == 1 && node.bridge == 1 || node.bridge == 0){
                    Q.push({node.index,node.bridge});
                    node_list.at(node.index).layer = node_list.at(num).layer + 1;
                }else if(Q.front().bridge_visited == 2 && node.bridge == 2 || node.bridge == 0){
                    Q.push({node.index,node.bridge});
                    node_list.at(node.index).layer = node_list.at(num).layer + 1;
                }
            }
        }
        Q.pop();
    }
    for(int i = 0;i<ans.size();++i){
        printf("ans[i] = %d\n",ans.at(i));
        if(ans.at(i) == T - 1){
            std::cout<<node_list.at(T-1).layer<<std::endl;
            return 0;
        }
    }
    std::cout<<-1<<std::endl;
    
    return 0;
}

void printGraph(std::vector<std::list<node_t>> graph){
    int i = 0;
    for(auto lstnode : graph){
        std::cout<<i<<"->";
        for(auto node : lstnode){
            std::cout<<node.index<<","<<node.bridge<<"->";
        }
        i++;
        std::cout<<std::endl;
    }
    //std::cout<<std::endl;
}