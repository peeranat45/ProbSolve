#include <iostream>
#include <vector>
#include <algorithm>
int main(void){
    std::vector<std::vector<int>> v{};
    int N{},M{};
    std::cin>>N>>M;
    v.resize(N+1);
    for(int i = 2;i<=N;++i){
        int input{};
        std::cin>>input;
        v.at(input).push_back(i);
    }

    for(int i = 0;i<M;++i){
        int A{},B{};
        std::cin>>A>>B;
        if(std::find(v.at(A).begin(),v.at(A).end(),B) != v.at(A).end()){
            std::cout<<A;
        }else if(std::find(v.at(B).begin(),v.at(B).end(),A) != v.at(B).end()){
            std::cout<<B;
        }else{
            std::cout<<-1;
        }
        if(i < M - 1)
            std::cout<<"\n";
    }
    return 0;
}