#include <iostream>
#include <vector>

int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<int> board{};
    board.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>board.at(i);
    }
    int pos{0};
    for(int i = 0;i<M;++i){
        int dice{};
        std::cin>>dice;
        pos += dice;
        if(pos < 0){
            pos = 0;
        }else if(pos >= N){
            std::cout<<N<<std::endl;
            return 0;
        }
        pos += board.at(pos-1);
        
    }
    if(pos < 0){
        pos = 0;
    }
    std::cout<<pos<<std::endl;
    return 0;
}