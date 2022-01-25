#include <iostream>
#include <vector>

int main(void){
    int N{};
    std::cin>>N;
    std::vector<int> v{};
    v.resize(100000);
    int total {0};
    for(int i = 0;i<N;++i){
        int L{};
        std::cin>>L;
        for(int j = 0;j<L;++j){
            int A{},B{};
            std::cin>>A>>B;
            v.at(B - 1) += A;
            total += A;
        }
        std::cout<<total<<std::endl;
        int temp = v.front();
        v.erase(v.begin());
        total -= temp;
    }
}