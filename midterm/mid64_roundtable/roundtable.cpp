#include <iostream>
#include <vector>
#include <list>


int main(void){
    int N{};
    std::cin>>N;
    std::list<int> food{};
    for(int i = 0;i<N;++i){
        int F{};
        std::cin>>F;
        food.push_back(F-1);
    }
    int max = 0;
    for(int i = 0;i<N;++i){
        int count = 0;
        std::list<int>::iterator it = food.begin();
        for(int j = 0;j<N;++j){
            if(*it == j){
                count++;
            }
            it++;
        }
        if(count > max){
            max = count;
        }
        int temp = food.front();
        food.pop_front();
        food.push_back(temp);
    }
    std::cout<<max<<std::endl;
    return 0;
}