#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool pairCompare(std::pair<int,int> p1, std::pair<int,int> p2){
    return p1.second < p2.second;
}

int main(void){
    int test_case{};
    std::cin>>test_case;
    std::cout<<std::endl;
    for(int k = 0;k<test_case;++k){
        std::cout<<std::endl;
        int M{};
        std::cin>>M;
        int L{},R{};
        std::vector<std::pair<int,int>> interval{};
        std::cin>>L>>R;
        while(true){
            //printf("Enter while\n");
            interval.push_back({L,R});
            std::cin>>L>>R;
            if(L == 0 && R == 0)
                break;
        }
        std::sort(interval.begin(),interval.end(),pairCompare);
        std::reverse(interval.begin(),interval.end());
        printf("Start Greedy\n");
        // Greedy Algorthim
        std::pair<int,int> current {0,0};
        std::vector<std::pair<int,int>> ans{};
        int count{0};
        do{
            for(auto pairs : interval){
                if(pairs.first <= current.second){
                    current = pairs;
                    ans.push_back(pairs);
                    count++;
                    goto label1;
                }
                goto label2;
            }
            goto label2;
            label1:
            ;
        }while(current.second < M);
        label2:
        ;
        //printf("End greedy\n");
        // if(ans.at(ans.size()-1).second < M){
        //      std::cout<<0<<std::endl;
        //  }else{
            std::cout<<count<<std::endl;
            for(auto pairs: ans){
                std::cout<<pairs.first<<" "<<pairs.second<<std::endl;
            }
        // }

        

    }
}