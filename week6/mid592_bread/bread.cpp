#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class BreadStore{
    public:
    int index;
    int price;
    int amount;
};

bool sortFunction(BreadStore a, BreadStore b){
    return a.price < b.price;
}


int main(void){
    int N{},Q{};
    std::vector<BreadStore> breads{};
    std::cin>>N>>Q;
    // breads.resize(N);
    for(int i = 0;i<N;++i){
        int p{},a{},l{};
        std::cin>>l>>p>>a;
        breads.push_back({l,p,a});
        // printf("i = %d\n",i);
    }

    std::sort(breads.begin(),breads.end(),sortFunction);

    for(int i = 0;i<Q;++i){
        int Y{};
        std::cin>>Y;
        // printf("Y = %d\n",Y);
        for(int j = 0;j<breads.size();++j){
            
            if(abs(Y - breads.at(j).index) <= 5 && breads.at(j).amount > 0){
                // printf("diff = %d breads.at(j).index = %d Y = %d\n",Y - breads.at(j).index,breads.at(j).index,Y);
                breads.at(j).amount -= 1;
                std::cout<<breads.at(j).price<<std::endl;
                break;
            }else if(j == breads.size()-1){
                std::cout<<0<<std::endl;
                break;
            }
        }
    }

}