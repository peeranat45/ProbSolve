#include <iostream>

#include <vector>

int main(void){
    std::vector<int> coin_changes{};
    coin_changes.resize(7489+1);
    int current = 0;
    coin_changes.at(0) = 1;
    std::vector<int> coin{1,5,10,25,50};
    for(int i = 0;i<coin.size();++i){
        for(int j = 1;j<coin_changes.size();++j){
            if(j >= coin.at(i) && j - coin.at(i) >= 0){
                coin_changes.at(j) += coin_changes.at(j-coin.at(i));
            }
        }
    }
    // std::cout<<coin_changes.at(11)<<std::endl;
    // std::cout<<coin_changes.at(26)<<std::endl;
    // for(int i = 1;i<coin_changes.size();++i){
    //     if(i % 5 == 0){
    //         current++;
    //         coin_changes.at(i) = coin_changes.at(i-1) + current;
    //     }else{
    //         coin_changes.at(i) = coin_changes.at(i-1);
    //     }
    
        
    // }
    int input{};
    // std::cin>>input;
    while(std::cin>>input){
        std::cout<<coin_changes.at(input)<<std::endl;
        // std::cin>>input;
    }
    

}