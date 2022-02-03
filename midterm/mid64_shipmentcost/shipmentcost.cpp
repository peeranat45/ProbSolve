#include <iostream>
#include <vector>
#include <list>
#include <queue>

class node_t{
    public:
    int index;
    int level;
    int visited;
};

int main(void){
    int N{},M{},S{},T{};
    std::cin>>N>>M>>S>>T;
    std::vector<std::list<int>> graph{};
    graph.resize(N);
    for(int i = 0;i<M;++i){
        int A{},B{};
        std::cin>>A>>B;
        graph.at(A-1).push_back(B-1);
        graph.at(B-1).push_back(A-1);
    }

    std::vector<int> warehouse_list{};
    for(int i = 0;i<S;++i){
        int input{};
        std::cin>>input;
        warehouse_list.push_back(input-1);
    }

    std::vector<int> factory_list{};
    for(int i = 0;i<T;++i){
        int input{};
        std::cin>>input;
        factory_list.push_back(input-1);
    }

    std::vector<std::vector<int>> ans{};
    ans.resize(N);
    //printf("41\n");
    for(int i = 0;i<S;++i){
        std::vector<int> shortest_path{};
        
        shortest_path.resize(N);
        // for(int j = 0;j<shortest_path.size();++j){
        //     if(j == warehouse_list.at(i))
        //         continue;
        //     shortest_path.at(j) = 99999999;
        // }
        std::queue<int> Q{};
        std::vector<int> visited{};
        visited.resize(N);
        Q.push(warehouse_list.at(i));
        while(!Q.empty()){
            int u = Q.front();
            if(visited.at(u) == 0){
                visited.at(u) = 1;
                for(auto node : graph.at(u)){
                    if(visited.at(node) == 0){
                        //printf("55\n");
                        if(shortest_path.at(node) == 0){
                            int new_shortest_path = shortest_path.at(u) + 1;
                            shortest_path.at(node)  = new_shortest_path;
                        }
                        // int new_shortest_path = shortest_path.at(u) + 1;
                        // shortest_path.at(node)  = new_shortest_path;
                        Q.push(node);
                    }
                }
            }
            Q.pop();
        }
        ans.at(warehouse_list.at(i)) = shortest_path;

    }
    //printf("66\n");
    for(int i = 0;i<T;++i){
        int min = 999999999;
        for(int j = 0;j<S;j++){
            //printf("71 i = %d j = %d\n",i,j);
            int from_a_to_b = ans.at(warehouse_list.at(j)).at(factory_list.at(i));
            //printf("start at = %d to %d distance = %d \n",warehouse_list.at(j),factory_list.at(i),from_a_to_b);  
            if(from_a_to_b < min){
                min = from_a_to_b;
            }
        }
        std::cout<<min<<std::endl;
    }

    return 0;

}