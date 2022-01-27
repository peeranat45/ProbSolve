#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <array>

int main(void){
    while(true){
        int m{},n{};
        std::cin>>n>>m;
        if(m == 0 && n == 0)
            return 0;
        std::vector<std::list<int>> graph{};
        std::array<int,100> indeq{};
        graph.resize(n);
        for(int loop = 0;loop<m;++loop){
            int i{},j{};
            std::cin>>i>>j;
            graph.at(i-1).push_back(j-1);
            indeq.at(j-1) += 1;
        }
        std::queue<int> Q{};
        for(int i = 0;i<n;++i){
            if(indeq[i] == 0)
                Q.push(i);
        }
        std::vector<int> output{};
        int node_in_graph_count = n;
        while(node_in_graph_count){
            int u = Q.front();
            Q.pop();
            for(auto node : graph.at(u)){
                indeq.at(node) -= 1;
                if(indeq.at(node) == 0)
                    Q.push(node);
                    
            }
            output.push_back(u);
            node_in_graph_count -= 1;
        }

        for(auto node : output){
            std::cout<<node + 1<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}