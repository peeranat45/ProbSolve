#include <iostream>
#include <vector>

int main(void){
    int X{};
    std::cin>>X;
    int input{};
    std::cin>>input;
    int count{0};
    std::vector<int> years{};
    years.push_back(input);
    while(input != 0){
        count++;
        std::cin>>input;
        years.push_back(input);
    }
    int current_uni = 0;                 // K = 0 C = 1
    int current_year = 2558;
    while(current_year < X){
        if(years.at(0) == current_year){
            years.erase(years.begin());
            current_year++;
            continue;
        }
        current_uni = (current_uni + 1)%2;
        current_year++;
    }
    if(current_uni == 0){
        std::cout<<'K'<<std::endl;
    }else{
        std::cout<<'C'<<std::endl;
    }
    return 0;
}