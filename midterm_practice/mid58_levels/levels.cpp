#include <iostream>
#include <vector>

class requirement{
    public:
    long A;
    long B;
    long C;
};

int main(void){
    long N{},M{};
    std::vector<requirement> level{};
    std::cin>>N>>M;
    for(long i = 0;i<N-1;++i){
        long a{},b{},c{};
        std::cin>>a>>b>>c;
        requirement temp = {a,b,c};
        level.push_back(temp);
    }
    long current_level {0};
    long a{0},b{0},c{0};
    for(long i = 0;i<M;++i){
        if(current_level >= N-1){
            break;
        }
        long a_input{},b_input{},c_input{};
        std::cin>>a_input>>b_input>>c_input;
        if(a_input > a){
            a = a_input;
        }
        if(b_input > b){
            b = b_input;
        }
        if(c_input > c){
            c = c_input;
        }
        if(a >= level.at(current_level).A && b >= level.at(current_level).B && c >= level.at(current_level).C){
            a = 0,b = 0,c = 0;
            current_level++;
        }
    }
        //current_level++; 
    
    std::cout<<current_level+1<<std::endl;
    return 0;
}