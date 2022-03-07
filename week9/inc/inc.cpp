#include <iostream>
#include <vector>
#include <algorithm>
int main(void){
    int N{};
    std::cin>>N;
    std::vector<int> numbers{};
    numbers.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>numbers.at(i);
    }

    std::vector<int> DP{};
    std::vector<int> previous_number{};
    DP.resize(N);
    previous_number.resize(N);
    
    for(int i = 0;i<N;++i){
        int max = 0;
        for(int k = 0;k<i;++k){
            // int temp = 
            // printf("i = %d,number.at(k) = %d < number.at(i) = %d\n",i,numbers.at(k),numbers.at(i));
            if(numbers.at(k) < numbers.at(i) && DP.at(k) >= max){
                // printf("DP.at(k)  = %d, numbers.at(k) = %d i =%d\n",DP.at(k),numbers.at(k),i);
                 previous_number.at(i) = k;
                max = DP.at(k);
                
            }
            // printf("previous_number.at(i) = %d\n",previous_number.at(i));
        }
        // printf("previous_number.at(%d)) = %d\n",i,previous_number.at(i));
        DP.at(i) = max + 1;
    }
    int max_seq = DP.at(0);
    int lastest_num = {0};
    for(int i = 0;i<N;++i){
        // printf("DP(%d) = %d\n",i,DP.at(i));
        if(DP.at(i) > max_seq){
            max_seq = DP.at(i);
            lastest_num = i;
        }
    }
    int count = max_seq;
    std::vector<int> ans{};
    while(count != 0){
        
        // std::cout<<numbers.at(lastest_num)<<" ";
        ans.push_back(numbers.at(lastest_num));
        lastest_num = previous_number.at(lastest_num);
        
        count--;
    }
    std::cout<<max_seq<<std::endl;

    std::sort(ans.begin(),ans.end());
    for(auto num : ans){
        std::cout<<num<<" ";
    }

    return 0;
}