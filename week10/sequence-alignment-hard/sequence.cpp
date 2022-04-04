#include <iostream>
#include <vector>
#include <string>

const int infiniti = 999999999;

int main(void){
    std::string X{};
    std::string Y{};
    std::cin>>X>>Y;
    std::vector<std::vector<int>> opt{};
    opt.resize(X.size()+1);
    for(int i = 0;i<opt.size();++i){
        // printf("i = %d\n",i);
        opt.at(i).resize(Y.size()+1);
        opt.at(i).at(0) = i;
    }
    for(int i = 0;i<opt.at(0).size();++i){
        opt.at(0).at(i) = i;
    }

    // std::cout<<20<<std::endl;
    for(int j = 1;j<=Y.size();++j){
        for(int i = 1;i<=X.size();++i){
            int max = 0;
            if(1 + opt.at(i-1).at(j) < 1 + opt.at(i).at(j-1)){
                max = 1 + opt.at(i).at(j-1);
            }else{
                max = 1 + opt.at(i-1).at(j);
            }
            int alpha = 0;
            if(X.at(i-1) == Y.at(j-1)){
                alpha = 2;
            }else{
                alpha = -1;
            }
            if(max < alpha + opt.at(i-1).at(j-1)){
                max = alpha + opt.at(i-1).at(j-1);
            }
            opt.at(i).at(j) = max;
            
        }
    }
    // for(int j = 0;j<=Y.size();++j){
    //     for(int i = 0;i<=X.size();++i){
    //         std::cout<<opt.at(i).at(j)<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    std::cout<<opt.at(X.size()).at(Y.size())<<std::endl;
    return 0;


}