#include <iostream>
#include <vector>
#include <algorithm>


class contract{
    public:
    int c;
    int p;
    int w;
};


int main(void){
    int K{},N{};
    std::cin>>K>>N;
    std::vector<contract> contract_list{};
    for(int i = 0;i<K;++i){
        int C{},P{},W{};
        std::cin>>C>>P>>W;
        contract_list.push_back({C,P,W});
    }

    std::vector<int> min_each_contract{};
    std::vector<int> product_list{};
    for(int i = 0;i<N;++i){
        int input{};
        std::cin>>input;
        product_list.push_back(input);
    }
    //printf("31\n");
    //std::sort(product_list.begin(),product_list.end());
    int min = 99999999;
    for(int i = 0;i<K;++i){
        int count{1};
        int temp_weight_count{};
        if(contract_list.at(i).w < product_list.at(product_list.size()- 1)){
            continue;
        }
        int pointer_at_product = 0;
        while(pointer_at_product < product_list.size()){
            //printf("temp_weight = %d count = %d product_weight = %d\n",temp_weight_count,count,product_list.at(pointer_at_product));
            temp_weight_count += product_list.at(pointer_at_product);
            if(temp_weight_count > contract_list.at(i).w){
                count++;
                temp_weight_count = 0;
                continue;
            }
            // temp_weight_count += product_list.at(pointer_at_product);
            pointer_at_product++;
        }
        // for(int j = 0;j<N;++j){
        //     printf("temp_weight = %d count = %d\n",temp_weight_count,count);
        //     if(temp_weight_count > contract_list.at(i).w){
        //         count++;
        //         temp_weight_count = 0;
        //     }
        //     temp_weight_count += product_list.at(j);
        // }
        
        int temp_price = contract_list.at(i).c + contract_list.at(i).p * count;
       // printf("count = %d, temp_price = %d\n",count,temp_price);
        if(temp_price < min){
            min = temp_price;
        }
    }
    std::cout<<min<<std::endl;
}