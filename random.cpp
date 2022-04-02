#include <iostream>
#include <random>

int main(void){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-1000000000,1000000000);
    std::cout<<100000<<std::endl;
    for(long i = 0;i<100000;++i){
        std::cout<<distr(gen)<<std::endl;
    }
    return 0;
}