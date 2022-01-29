#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(int start,int end,int num,int check,std::vector<int> p,int func);

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
        int min_index = binarySearch(1,p.size()-1,p.at(j),A,p,0);
        int max_index = binarySearch(1,p.size()-1,p.at(j),B,p,1);

        // if(p.at(max_index) + p.at(j) > B){
        //     max_index -= 1;
        // }
        
        // count += ans;
        if(p.at(min_index) == p.at(max_index)){
            continue;
        }
        printf("p.at(min_index) = %d, p.at(max_index) = %d\n",p.at(min_index),p.at(max_index));
        std::vector<int>::iterator lower = std::lower_bound(p.begin(),p.end(),p.at(min_index));
        std::vector<int>::iterator upper = std::upper_bound(p.begin(),p.end(),p.at(max_index));
        upper -= 1;
        //printf("lower = %d, upper = %d  ",*lower,*upper);
        int ans = upper - lower + 1;
        count += ans;
        //printf("num = %d min = %d max = %d ans = %d\n",p.at(j),min_index,max_index,ans);
        p.erase(p.begin());
        }

    }
    std::cout<<count<<std::endl;
}  




int binarySearch(int start,int end,int num,int check,std::vector<int> p,int func){
    if(start > end ){

        return start;
    }
    
    int mid = (start + end)/2;
    printf("start = %d, mid = %d, end = %d , p.size() = %lu\n",start,mid,end,p.size()); // func = 0 lower, func = 1 upper
    if(start == end){
        if(p.at(mid) + num > mid && func == 1){
            return mid-1;
        }else if(p.at(mid) + num > mid && func == 0){
            return mid;
        }else if(p.at(mid) + num > mid && func == 1){
            return mid + 1;
        }else if(p.at(mid) + num > mid & func == 0){
            return mid;
        }
    }
   
    if(p.at(mid) + num < check){
        return binarySearch(mid+ 1,end,num,check,p,func);
    }else if(p.at(mid) + num >= check){
        return binarySearch(start,mid,num,check,p,func);
    }
    return -1;
}