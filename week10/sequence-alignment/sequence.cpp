#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//const int infiniti = 999999999;

int main(void){
    std::string X{};
    std::string Y{};
    std::cin>>X>>Y;

    //Build table
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


    //Find OPT
    // std::cout<<20<<std::endl;
    for(int j = 1;j<=Y.size();++j){
        for(int i = 1;i<=X.size();++i){
            int min = 0;
            if(1 + opt.at(i-1).at(j) > 1 + opt.at(i).at(j-1)){ //check  สอง เงื่อนไขล่าง
                min = 1 + opt.at(i).at(j-1);
            }else{
                min = 1 + opt.at(i-1).at(j);
            }
            int alpha = 0;
            if(X.at(i-1) == Y.at(j-1)){
                alpha = 0;
            }else{
                alpha = 1;
            }
            if(min > alpha + opt.at(i-1).at(j-1)){
                min = alpha + opt.at(i-1).at(j-1);
            }
            opt.at(i).at(j) = min;
            
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