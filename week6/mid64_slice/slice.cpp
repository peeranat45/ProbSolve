#include <iostream>
#include <vector>

void prlong_wood(std::vector<long> wood);

int main(void){
    long M{};
    std::cin>>M;
    std::vector<long> v{};
    std::vector<long> wood{};
    wood.resize(100010);
    for(long i = 0;i<M;++i){
        long temp{};
        std::cin>>temp;
        v.push_back(temp);
    }
    long status = 1;
    while(status){
        status = 0;
        long count = 0;
        for(long i = 0;i<M;++i){
           // prlongf("v.at(i) = %d  ",v.at(i));
            //prlongf("count = %d\n",count);
            if(v.at(i) <= 0){
                wood.at(count) += 1;
                count = 0;
                continue;
            }else{
                count += 1;
                v.at(i) -= 1;
                status = 1;
            }

        }
        wood.at(count) += 1;
        //prlong_wood(wood);
        //prlongf("-----------------------------------------\n");
    }
   // prlong_wood(wood);
    long count = 0;
    for(long i = 1;i<M;++i){
        if(wood.at(i) == 0)
            continue;
        count++;
        
    }
    std::cout<<count<<std::endl;
    for(long i = 1;i<M;++i){
        if(wood.at(i) == 0)
            continue;
        std::cout<<i<<" "<<wood.at(i)<<std::endl;
    }
}

void prlong_wood(std::vector<long> wood){
    long i = 0;
    for(auto num : wood){
        std::cout<<"long "<<i<<"  = "<<num<<std::endl;
        i += 1;
    }
}