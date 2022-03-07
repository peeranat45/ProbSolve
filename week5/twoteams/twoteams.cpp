#include <iostream>
#include <vector>
#include <list>


int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<int> colors{};
    colors.resize(N+1);
    for(int i = 1;i<=N;++i){
        colors.at(i) = -1;
    }
    int count{0};
    std::vector<std::list<int>> graph{};
    graph.resize(N+1);
    //printf("Hello World\n");
    for(int i = 0;i<M;++i){
        int A{},B{};
        bool matched = false;
        std::cin>>A>>B;
        //printf("A = %d, B = %d\n",colors.at(A),colors.at(B));
        if(A == B){
            break;
        }
        for(auto num : graph.at(A)){
            if(num == B)
                matched = true;
        }   
        if(matched){
            break;
        }
        if(colors.at(A) == -1 && colors.at(B) == -1){
            colors.at(A) = 0;
            colors.at(B) = 1;
        }else if(colors.at(A) == -1){
            colors.at(A) = (colors.at(B) + 1) % 2;
        }else if(colors.at(B) == -1){
            colors.at(B) = (colors.at(A) + 1) % 2;
        }else if(colors.at(A) == colors.at(B)){
            break;
        }
        count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}