#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(int start,int end,int num,int check,std::vector<int> p);

int main(void){
    int N{},A{},B{};
    std::cin>>N>>A>>B;
    std::vector<int> p{};
    p.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>p.at(i);
    }

    sort(p.begin(),p.end());
    int count = 0;
    int j = 0;
    //printf("Fuck\n");
    for(int i = 0;i<N;++i){
        if(p.size() - 1 != 0){
        int min_index = binarySearch(1,p.size()-1,p.at(j),A,p);
        int max_index = binarySearch(1,p.size()-1,p.at(j),B,p);

        if(p.at(max_index) + p.at(j) > B){
            max_index -= 1;
        }
        int ans = max_index - min_index + 1;  
        count += ans;
        //printf("num = %d min = %d max = %d ans = %d\n",p.at(j),min_index,max_index,ans);
        p.erase(p.begin());
        }

    }
    std::cout<<count<<std::endl;
}  




int binarySearch(int start,int end,int num,int check,std::vector<int> p){
    if(start >= end ){

        return start;
    }

    int mid = (start + end)/2;
   // printf("start = %d, mid = %d, end = %d , p.size() = %lu\n",start,mid,end,p.size());
    if(p.at(mid) + num < check){
        return binarySearch(mid+ 1,end,num,check,p);
    }else if(p.at(mid) + num >= check){
        return binarySearch(start,mid,num,check,p);
    }
    return -1;
}