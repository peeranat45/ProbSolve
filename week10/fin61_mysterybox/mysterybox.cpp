#include <iostream>
#include <vector>

int main(void){
    std::vector<std::vector<char>> graphs{};
    int size{};
    std::cin>>size;
    graphs.resize(size);
    for(int i = 0;i<size;++i){
        graphs.at(i).resize(size);
        for(int j = 0;j<size;++j){
            char temp{};
            std::cin>>temp;
            graphs.at(i).at(j) = temp;
        }
    }

    //Fuck
    std::vector<char>
    for(int i = 0;i<size*size;++i){
        
    }
}