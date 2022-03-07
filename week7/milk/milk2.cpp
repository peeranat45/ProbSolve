#include <iostream>
#define MAX_ARR 1000010

int parent[MAX_ARR];
int rank[MAX_ARR];

int find(int u);
void unions(int u,int v);

int main(void){
    int n{},q{};
    std::cin>>n>>q;
    for(int i = 0;i<n;++i){
        parent[i] = i;
    }
   // printf("16\n");
    for(int i = 0;i<q;++i){
        char command;
        int x,y;
        std::cin>>command>>x>>y;
        //printf("command = %c, x = %d, y = %d\n",command,x,y);
        if(command == 'c'){
            unions(x-1,y-1);
        }else{
            int temp1 = find(x-1);
            int temp2 = find(y-1);
            if(temp1 == temp2){
                std::cout<<"yes"<<std::endl;
            }else{
                std::cout<<"no"<<std::endl;
            }
        }
    }

}

int find(int u){
    while(parent[u] != u){
        //printf("u = %d\n",u);
        u = parent[u];
    }
    return u;
}

void unions(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(rank[pu] < rank[pv]){
        parent[pu] = pv;
    }else if(rank[pv] < rank[pu]){
        parent[pv] = pu;
    }else{
        parent[pu] = pv;
        rank[pv]++;
    }
}