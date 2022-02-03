#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
    int N{};
    std::cin>>N;
    std::vector<int> v{};
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        v.push_back(input);
    }
    int one_index_pos {};
    for(int i = 0;i<N;++i){
        if(v.at(i) == 1)
            one_index_pos = i;
    }
    int count{};
    int max = 0;
    int index_vector = one_index_pos;
    std::vector<int> different {};
    different.resize(10000);
   // printf("one_index = %d\n",one_index_pos);
    for(int i = 0;i<N;++i){
        //printf("v.at(index_vector) = %d, i + 1 = %d\n",v.at(index_vector),i+1);
        // if(v.at(index_vector) == i + 1){
        //     count++;
        // }
        different.at(v.at(index_vector)-  i + 1) += 1;
        //printf("diffrent = %d\n",different.at(v.at(index_vector) -  i + 1));
        index_vector++;
        index_vector %= N;
        // if(count > max){
        //     max = count;
        // }
    }
    for(int i = 0;i<different.size();++i){
        if(different.at(i) > max){
            max = different.at(i);
        }
    }
    // max = std::max_element(different.begin(),different.end());
    std::cout<<max<<std::endl;
    return 0;
}