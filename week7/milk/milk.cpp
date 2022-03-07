#include <iostream>
#include <vector>

class node_t{
    public:
    int name;
    int parent;
    int rank;
};

int find(std::vector<node_t> tree_t, int node);
int unions(std::vector<node_t> &tree_t,int x,int y);
void print_tree(std::vector<node_t> tree_t);

int main(void){
    int N{},Q{};
    std::cin>>N>>Q;
    std::vector<node_t> tree_t{};
    for(int i = 0;i<N;++i){
        tree_t.push_back({i,i,0});
    }
    for(int i = 0;i<Q;++i){
        char command{};
        int X{},Y{};
        std::cin>>command>>X>>Y;
        //printf("command = %c %d %d\n",command,X-1,Y-1);
        int parent_x = find(tree_t,X-1);
        int parent_y = find(tree_t,Y-1);
        switch(command){
            
            case 'q' :{
               // printf("parent_x = %d, parent_y = %d\n",parent_x,parent_y);
                if(parent_x  == parent_y){
                    std::cout<<"yes"<<std::endl;
                }else{
                   std::cout<<"no"<<std::endl;
                }
                break;
            }
            case 'c': {
                int insert_status = unions(tree_t,parent_x,parent_y);
                //std::cout<<"insert_status = "<<insert_status<<std::endl;
                break;
            }
        }
        //print_tree(tree_t);
    }

    return 0;
}

int find(std::vector<node_t> tree_t, int node){
    // int temp_node = node;
    // int count = 0;
    while(tree_t.at(node).parent != node){
        // node = tree_t.at(temp_node).name;
        //printf("temp_node = %d node = %d\n",temp_node,node);
        node = tree_t.at(node).parent;
        // node = tree_t.at(temp_node).name;
        // count++;
        
    }
    return node;
}

int unions(std::vector<node_t> &tree_t,int x,int y){
    // if(parent_x == parent_y && parent_x != -1 && parent_y != -1){
    //     return 0;
    // }
    if(tree_t.at(x).rank == tree_t.at(y).rank){
        tree_t.at(y).parent = x;
        tree_t.at(x).rank += 1;
        return 1;
    }else if(tree_t.at(x).rank > tree_t.at(y).rank){
        tree_t.at(y).parent = x;
        return 1;
    }else if(tree_t.at(x).rank < tree_t.at(y).rank){
        tree_t.at(x).parent = y;
        return 1;
    }
    return 0;
}

void print_tree(std::vector<node_t> tree_t){
    for(auto node : tree_t){
        printf("Name = %d, parent = %d, rank = %d\n",node.name,node.parent,node.rank);
    }
}