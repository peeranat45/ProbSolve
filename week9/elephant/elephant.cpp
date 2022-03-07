#include <iostream>
#include <vector>

int main(void){
    int N{};
    std::cin>>N;
    if(N == 0 || N == 1 || N == 2){
        std::cout<<0<<std::endl;
        return 0;
    }
    std::vector<int> bananas{};
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        bananas.push_back(input);
    }
    std::vector<int> max{};
    max.resize(N);
    max[0] = 0;
    max[1] = 0;
    max[2] = 0;
    for(int i = 3;i<N;++i){
        // printf("i = %d\n",i);
        printf("%d = %d\n",i-3,max[i-3]);

        max[i] = (max[i-1] > bananas[i] + max[i-3]) ? max[i-1] : bananas[i] + max[i-3];
        // printf("max[%d] = %d\n",i,max[i]);
    } 
    std::cout<<max[N-1]<<std::endl;
    return 0;
}