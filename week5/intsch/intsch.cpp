#include <iostream>
#include <vector>
#include <algorithm>

class work{
    public:
        int fs;
        int fl;
};

bool comparePair(work f1,work f2){
    return f1.fl < f2.fl;
}


int main(void){
    int N{};
    std::cin>>N;
    std::vector<work> work_vector{};
    for(int i = 0;i<N;++i){
        int s{},t{};
        std::cin>>s>>t;
        work_vector.push_back({s,t});
    }
    std::sort(work_vector.begin(),work_vector.end(),comparePair);
    int count = 1;
    work latest = work_vector.at(0);
    for(int i = 1;i<N;++i){
        if(latest.fl <= work_vector.at(i).fs){
            latest = work_vector.at(i);
            count++;
        }
    }
    std::cout<<count<<std::endl;
}