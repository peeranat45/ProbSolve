#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_ARR 1000010

class edge{
    public:
    int A;
    int B;
    int W;
};

bool sortEdge(edge A,edge B) {
    return A.W < B.W;
}


int parent[MAX_ARR];
int rank[MAX_ARR];
std::vector<edge> edges{};

int find(int u);
void unions(int u,int v);

int main(void){
    int N{},M{},K{};
    std::cin>>N>>M>>K;
    for(int i = 1;i<=N;++i){
        parent[i] = i;
    }

    for(int i = 0;i<M;++i){
        int a{},b{},w{};
        std::cin>>a>>b;
        edges.push_back({a,b,0});
    }
    int count {};
    std::sort(edges.begin(),edges.end(),sortEdge);
    for(int i = 0;i<M;++i){
        if(find(edges.at(i).A) != find(edges.at(i).B)){
            unions(edges.at(i).A,edges.at(i).B);
            count += edges.at(i).W;
        }

    }
    for(int i = 0;i<K;++i){
        int A{},B{};
        std::cin>>A>>B;
        if(find(A) == find(B)){
            // printf("find(%d) = %d, find(%d) = %d\n",A,find(A),B,find(B));
            std::cout<<1<<std::endl;
        }else{
            std::cout<<0<<std::endl;
        }
    }
    // std::cout<<count<<std::endl;


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