#include <iostream>
#include <vector>

int check(std::vector<int> total_logs, int num);
int main(void){
    int N{},Q{};
    std::cin>>N>>Q;
    std::vector<int> total_logs{};
    std::vector<int> logs{};
    // total_logs.resize(N*N);
    logs.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>logs.at(i);
    }
    
    // opt.at(0) = logs.at(0);
    for(int i = 0;i<logs.size();++i){
        int sum = 0;
        for(int j = i;j<logs.size();++j){
            sum += logs.at(j);
            total_logs.push_back(sum);
        }
    }
// for(int i = 0;i<total_logs.size();++i){
//         std::cout<<total_logs.at(i)<<" ";
//     }
    // std::cout<<std::endl;
    for(int i = 0;i<Q;++i){
        int ask{};
        std::cin>>ask;
        int status = 0;
        if(check(total_logs,ask)){
            std::cout<<"Y";
        }else{
            std::cout<<"N";
        }
        
    }
    std::cout<<std::endl;
    return 0;
}

int check(std::vector<int> total_logs, int num){
    for(int i = 0;i<total_logs.size();++i){
        if(num == total_logs.at(i)){
            return 1;
        }
    }
    return 0;
}