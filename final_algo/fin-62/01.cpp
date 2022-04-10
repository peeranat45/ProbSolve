#include <iostream>
#include <vector>

int main(void){
    int k = 2;
    std::vector<int> input{5,2,2,3,4,5};
    std::vector<int> backtrack{};
    std::vector<int> opt{};
    opt.resize(input.size());
    backtrack.push_back(-1);
    backtrack.resize(input.size());
    opt.at(0) = input.at(0);
    for(int i = 1;i<opt.size();++i){
        int max = input.at(i);
        int back = 0;
        for(int j = 0;j<i;++j){
            if(abs(input.at(j) - input.at(i)) == k ){
                if(max + opt.at(j) > max){
                    max = max + opt.at(j);
                    back = j;
                }
                // max = (max > max + opt.at(j)) ? max : max + opt.at(j);
            }
        }
        opt.at(i) = max;
        backtrack.at(i) = back;
    }
    int max = 0;
    int i = 5;
    for(auto num : opt){
        // printf("opt(i) = %d\n",num);
        max = (max > num) ? max : num;
    }
    std::cout<<max<<std::endl;
    do{

        std::cout<<input.at(i)<<" ";
        i = backtrack.at(i);
        
    }while(i != -1);
    return 0;
    
}