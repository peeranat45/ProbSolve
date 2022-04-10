#include <iostream>
#include <vector>
#include <string>


int main(void){
    std::string substring{};
    std::string inputstring{};
    std::cin>>substring;
    std::cin>>inputstring;
    int count = 0;
    int substring_index = 0;
    for(int i = 0;i<inputstring.size();++i){
        if(inputstring.at(i) == substring.at(substring_index)){
            substring_index++;
            if(substring_index == substring.size()){
                count++;
                substring_index = 0;
            }
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}