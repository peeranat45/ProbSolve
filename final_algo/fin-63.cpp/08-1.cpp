#include <iostream>
#include <vector>

std::vector<int> county{1,2,3,2,2,1};

int main(void){
    std::vector<int> opt{};
    opt.resize(county.size());
    opt.at(0) = county.at(0);
    int K = 4;
    for(int i = 0;i<opt.size();++i){
        int choice_a = 0;
        int choice_b = 0;
        int pj = 0;
        for(int j = 0;j<i;j++){
            pj += county.at(j);
        }

        choice_a = abs(K - pj);
        int min = 0;
        for(int j = 0;j<i;++j){
            int choice2_temp = 0;
            int pj_temp = 0;
            for(int k = 0;k<j;++k){
                pj_temp += county.at(k);
            }
            choice2_temp = abs(K-pj_temp) + opt.at(i-j);
            if(choice2_temp < min){
                min = choice2_temp;
            }
        }
        choice_b = min;

        opt.at(i) = (choice_a > choice_b) ? choice_b : choice_a;
    }

    std::cout<<opt.at(6-1)<<std::endl;
}