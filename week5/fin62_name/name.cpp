#include <iostream>
#include <string>

int main(void){
    std::string S{},T{};
    std::cin>>S>>T;
    std::string::iterator sit = S.begin();
    int count = 0;
    for(std::string::iterator it = T.begin(); it != T.end();++it){
        if(*sit == *it){
            sit++;
        }
        if(sit == S.end()){
            sit = S.begin();
            count++;
        }
    }
    std::cout<<count<<std::endl;
}