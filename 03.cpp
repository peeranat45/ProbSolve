#include <iostream>
#include <math.h>

int main(void){
    while(true){
    int input{};
    std::cin>>input;
    int ans = input/pow(2,2);
    ans = ans % 128;
    int tag = input/pow(2,9);
    std::cout<<"index = "<<ans<<", tag = "<<tag<<std::endl;
    }
    return 0;
}
