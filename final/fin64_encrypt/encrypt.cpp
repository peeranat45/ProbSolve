#include <iostream>
#include <vector>

void printVector(std::vector<int> input);

int main(void){
    //variable
    std::vector<int> input{};
    std::vector<int> after_roll{};
    int N{},S{};
    std::cin>>N>>S;
    input.resize(N);
    after_roll.resize(20);
    for(int i = 0;i<N;++i){
        std::cin>>input.at(i);
    }

    for(int i = 1;N<20;++i){
        input.push_back(i);
        N++;
        }

    // printVector(input);
    // printf("Size of input = %d, Size of after_roll = %d\n",input.size(),after_roll.size());
    for(int i = 0;i<input.size();++i){
        after_roll.at((i+S)%20) = input.at(i);
    }
    // printVector(after_roll);
    for(int i = 0;i<5;++i){
        for(int j = i;j<20;j+=5)
        std::cout<<after_roll.at(j)<<" ";
    }
    std::cout<<std::endl;
}


void printVector(std::vector<int> input){
    for(auto num : input){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
}