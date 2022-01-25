#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

int main(void){
    int K{};
    std::cin>>K;
    while(K){
        int N{},M{};
        std::vector<int> color{};
        std::cin>>N>>M;
        color.clear();
        color.resize(N + 1);
        for(int i = 1;i<N+1;++i){
            color.at(i) = -1;
        }
        //printf("-----\n");
        bool bipartite = true;
        for(int i = 0;i<M;i++){
            int u{},v{};
            std::cin>>u>>v;
            if(color.at(u) == -1 && color.at(v) == -1){
                color.at(u) = 0;
                color.at(v) = 1;
                //  printf("color.at(%d) = %d color.at(%d) = %d\n",u,color.at(u),v,color.at(v));
            }else if(color.at(u) == -1){
                color.at(u) = (color.at(v) + 1)%2;
                //  printf("color.at(%d) = %d color.at(%d) = %d\n",u,color.at(u),v,color.at(v));
            }else if(color.at(v) == -1){
                color.at(v) = (color.at(u) + 1)%2;
                //  printf("color.at(%d) = %d color.at(%d) = %d\n",u,color.at(u),v,color.at(v));
            }else if(color.at(v) == color.at(u)){
                // printf("color.at(%d) = %d color.at(%d) = %d\n",u,color.at(u),v,color.at(v));
                bipartite = false;
            }else{
                //  printf("color.at(%d) = %d color.at(%d) = %d\n",u,color.at(u),v,color.at(v));
            }
            // std::cout<<"bipartite = "<<bipartite<<std::endl;
            
        }
        if(bipartite){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        K--;
    }
   return 0;
}