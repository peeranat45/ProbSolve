#include <iostream>
#include <vector>

int main(void){
    int input{};
    // std::cin>>input;
    while(std::cin>>input){
        std::vector<int> arr{};
        arr.resize(input);
        for(int i = 0;i<input;++i){
            int a{};
            std::cin>>a;
            arr.at(i) = a;
        }
        std::vector<int> opt{};
        opt.resize(input);
        std::vector<int> a{};
        a.resize(input);
        std::vector<int> b{};
        b.resize(input);
        int min_a = 1;
        for(int i = 0;i<a.size();++i){
            // int min_a = 1;
            int max = 1;
            for(int j = 0;j<i;++j){
                if(arr.at(i) > arr.at(j)){
                    if(max < a.at(j) + 1){
                        max = a.at(j) + 1;
                    }
                }
            }
            if(min_a < max){
                min_a = max;
            }
            a.at(i) = max;
        }
        // int ax = 1;
        int min_b = 1;
        for(int i = input-1;i>=0;--i){
            // printf("i = %d\n",i);
            int max = 1;
            for(int j = input - 1;j>i;--j){
                if(arr.at(i) > arr.at(j)){
                    if(max < b.at(j) + 1){
                        max = b.at(j) + 1;
                    }
                }
            }
            // printf("b(i) = %d\n",max);
            b.at(i) = max;
            if(max > min_b){
                min_b = max;
            }
        }
        int max = 0;
        if(min_a == 1 || min_b == 1){
            std::cout<<1<<std::endl;
        }else{
            for(int i = 0;i<input;++i){
                if(max < a.at(i) + b.at(i)){
                    max = a.at(i) + b.at(i);
                }
            }
            std::cout<<max-1<<std::endl;
        }
       
        for(int i = 0;i<a.size();++i){
            // printf("a(%d) = %d, b(%d) = %d\n",i,a.at(i),i,b.at(i));
        }

        
        // std::cin>>input;
    }

    
}