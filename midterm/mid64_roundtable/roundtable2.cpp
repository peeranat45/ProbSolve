#include <iostream>
#include <vector>

int main(void){
    int N{};
    std::vector<int> v{};
    int max = 0;
    int current = -1;
    int temp {0};
    std::cin>>N;
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        //printf("Current = %d, input = %d temp = %d\n",current,input,temp);
        
        
        if(current == -1){
            current = input;
            temp++;
            continue;
        }
        //printf("Current = %d, input = %d temp = %d\n",current,input,temp);
        if(input - current == 1){
            temp++;
        }else{
            temp = 0;
        }
        if(input == N){
            current = 0;
        }else{
            current = input;
        }
        if(temp > max){
            max = temp;
        }
        //printf("Current = %d, input = %d temp = %d\n",current,input,temp);
    }
    std::cout<<max<<std::endl;
    return 0;
}