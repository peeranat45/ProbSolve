#include <iostream>
#include <vector>

std::vector<int> county{1,2,3,2,2,1};

int main(void){
    std::vector<int> opt{};
    opt.resize(county.size());
    opt.at(0) = county.at(0);
    int K = 4;
    for(int i = 1;i<opt.size();++i){
        int min = 0;
        for(int j = 0;j<i;++j){
            int cost = 0;
            int sum = 0;
            for(int k = j;k<i;++k){
                sum += county.at(k);
            }
            cost = abs(sum - K);
            if(cost < min){
                min = cost;
            }
        }
        opt.at(i) = min;
        
    }

    std::cout<<opt.at(county.size()-1)<<std::endl;
    return 0;
}