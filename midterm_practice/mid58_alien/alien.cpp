#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

int main(void){
    int N{},a{},b{},R{};
    // std::vector<std::pair<int,int>> coor{};
    std::cin>>N>>a>>b>>R;
    int count{0};
    for(int i = 0;i<N;++i){
        int x{},y{};
        std::cin>>x>>y;
        if(pow(x-a,2) + pow(y-b,2) <= pow(R,2)){
            count++;
        }
    }
    std::cout<<count<<std::endl;
    return 0;
}