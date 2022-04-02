#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

class road{
    public:
    int A;
    int B;
    int attacker;
};

int main(void){
    int C{};
    std::cin>>C;
    for(int i = 0;i<C;++i){
        int N{},K{};
        std::cin>>N>>K;
        std::vector<road> roads{};
        int count_total {0};
        // roads.resize(N);
        for(int i = 0;i<N;++i){
            int temp_a{},temp_b{};
            std::cin>>temp_a>>temp_b;
            roads.push_back({temp_a,temp_b,-1});
        }
        int count_a{0},count_b{0};
        for(int k = 0;k<roads.size();++k){
            if(count_a - count_b == K){
                // roads.at(k).attacker = 1;
                count_total += roads.at(k).B;
                count_b++;
            }else if(count_b - count_a == K){
                roads.at(k).attacker = 0;
                // count_total += roads.at(k).A;
                count_a++;
            }else{
                // int best = () ? roads.at(k).B : roads.at(k).A;
                int best{};
                if(roads.at(k).A > roads.at(k).B){
                    best = roads.at(k).B;
                    count_b++;

                }else{
                    best = roads.at(k).A;
                    count_a++;
                }
                count_total += best;
            }
        }
        std::cout<<count_total<<std::endl;
    }
}