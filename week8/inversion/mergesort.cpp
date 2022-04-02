#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    std::vector<long long> A{};
    int N{};
    for(int i = 0;i<N;++i){
        long long temp{};
        std::cin>>temp;
        A.push_back(temp);
    }

    std::sort(A.begin(),A.end());
}