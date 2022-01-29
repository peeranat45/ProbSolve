#include <iostream>


int main(void){
    int N{};
    std::cin>>N;
    int last_day {0};
    int total_energy{0};
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        if(last_day - input > 10){
            if((last_day - input) * 10 >= 700){
                total_energy += 700;
            }else{
                total_energy += (last_day - input) * 10;
            }
            
        }
        last_day = input;
    }
    std::cout<<total_energy<<std::endl;
    return 0;
}