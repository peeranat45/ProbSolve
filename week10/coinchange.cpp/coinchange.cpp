#include <iostream>

#include <vector>

int main(void){
    std::vector<int> coin_changes{};
    coin_changes.resize(7489);
    int current = 0;
    coin_changes.at(0) = 1;
    for(int i = 1;i<coin_changes.size();++i){
        if(i % 5 == 0){
            current++;
            coin_changes.at(i) = coin_changes.at(i-1) + current;
        }else{
            coin_changes.at(i) = coin_changes.at(i-1);
        }
    
        
    }
    int input{};
    std::cin>>input;
    do{
        std::cout<<coin_changes.at(input)<<std::endl;
        std::cin>>input;
    }while(input != '\n');
    

}