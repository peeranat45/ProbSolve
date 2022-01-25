#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <queue>

class node_t{
    public:
    int index;
    int x;
    int y;
    int level;
    int visited;
};

void insertGraph(std::vector<node_t> &node_list,std::vector<std::list<int>> &graph,node_t new_node,int max_dis);
void printGraph(std::vector<node_t> node_list,std::vector<std::list<int>> graph);

int main(void){
   int N{},R{};
   std::cin>>N>>R;
   std::vector<node_t> node_list{};
   std::vector<std::list<int>> graph{};
   graph.resize(N+2);
   node_list.push_back({0,0,0,0,0});
   insertGraph(node_list,graph,{1,100,100,-1,0},R);
   for(int i = 2;i<N + 2;++i){
       int xinput{},yinput{};
       std::cin>>xinput>>yinput;
       node_t new_node = {i,xinput,yinput,-1,0};
       insertGraph(node_list,graph,new_node,R);
       //printGraph(node_list,graph);
   }
    
    std::queue<int> Q{};
    Q.push(0);
    while(!Q.empty()){
        int top = Q.front();
        if(node_list.at(top).visited == 0){
            node_list.at(top).visited = 1;
            Q.pop();
            for(int node : graph.at(top)){
                if(node_list.at(node).visited == 0){
                    if(node_list.at(node).level == -1){
                        node_list.at(node).level = node_list.at(top).level + 1;
                        //std::cout<<"i = "<<node<<" level : "<<node_list.at(node).level<<std::endl;
                    }
                    Q.push(node);
                }
            }
            continue;
        }
        Q.pop();
    }
    std::cout<<node_list.at(1).level<<std::endl;
    
    return 0;
}

void insertGraph(std::vector<node_t> &node_list,std::vector<std::list<int>> &graph,node_t new_node,int max_dis){
    node_list.push_back(new_node);
    for(auto node : node_list){
        int dis = pow((node.x - new_node.x ), 2) + pow((node.y - new_node.y),2);
        if(dis <= pow(max_dis,2) && dis != 0){
            graph.at(node.index).push_back(new_node.index);
            graph.at(new_node.index).push_back(node.index);
        }
    }
    
    
}

void printGraph(std::vector<node_t> node_list,std::vector<std::list<int>> graph){
    for(auto node : node_list){
        std::cout<<"i = "<<node.index<<" ("<<node.x<<","<<node.y<<") : ";
        for(auto num : graph.at(node.index)){
            std::cout<<num<<"->";
        }
        std::cout<<std::endl;
    }
}