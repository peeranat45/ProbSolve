#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N{},A{},B{};
    std::cin>>N>>A>>B;
    std::vector<int> p{};
    p.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>p.at(i);
    }

    std::sort(p.begin(),p.end());
    for(int i = 0;i<N;++i){
        std::vector<int>::iterator lower = std::lower_bound(p.begin(),p.end(),p.at(i)+A);
        std::vector<int>::iterator upper = std::upper_bound(p.begin(),p.end(),p.at(i)+B);
        std::cout<<upper-lower<<std::endl;
    }
    
}