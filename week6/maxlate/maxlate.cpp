#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool pairSortSecond(std::pair<int,int> p1,std::pair<int,int> p2){
    return p1.first < p2.first;
}

int main(void){
    int N{};
    std::cin>>N;
    std::vector<std::pair<int,int>> pairs{};
    for(int i = 0;i<N;++i){
        int D{},C{};
        std::cin>>D>>C;
        pairs.push_back({D,C});
    }

    std::sort(pairs.begin(),pairs.end(),pairSortSecond);
    int current_day = 0;
    int max_price = 0;
    for(auto work : pairs){
        current_day += work.second;
        if(current_day - 10 > work.first){
            int temp_price = (current_day - work.first - 10)*1000;
            if(temp_price > max_price){
                max_price = temp_price;
            }
        }
    }
    std::cout<<max_price<<std::endl;
    return 0;
}