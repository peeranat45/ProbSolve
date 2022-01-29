#include <iostream>
#include <vector>

int main(void){
    int X{};
    std::cin>>X;
    int count{2558};
    int input{};
    std::vector<int> years{};
    std::cin>>input;
    char uni = 'K';
    while(input !=0){
        years.push_back(input);
        std::cin>>input;
    }
    for(int i = 2558;i<X;++i){
        if(!years.empty() && years.at(0) == i){
            years.erase(years.begin());
            continue;
        }
        if(uni == 'K'){
            uni = 'C';
        }else{
            uni = 'K';
        }
    }
    std::cout<<uni<<std::endl;
    return 0;
}