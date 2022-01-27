#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

long long binarySearch_min(long long start,long long end,long long num,long long min);
long long binarySearch_max(long long start,long long end,long long num,long long max);
void printpair(long long min,long long max,long long num);

std::vector<long long> p;

int main(void){
    long long N,B,A;
    std::cin>>N>>A>>B;
    p.resize(N);
    for(int i = 0;i<N;++i){
        std::cin>>p.at(i);
    }
    sort(p.begin(),p.end());
    long long count = 0;
    for(long long i = 0;i<N;++i){
        long long min = binarySearch_min(i,N-1,p.at(i),A);
        long long max = binarySearch_max(i,N-1,p.at(i),B);
        printf("max = %lld, min = %lld,v.at(i) = %lld\n",max,min,p.at(i));
        printpair(min,max,p.at(i));
        if(max > min)
            count += max - min + 1; 
    }
    std::cout<<count<<std::endl;
    return 0;
}


long long binarySearch_min(long long start,long long end,long long num,long long min){
    if(start >= end){
        return end;
    }
    long long mid = (start + end)/2;
    //printf("start = %lld, mid = %lld, end = %lld, num + p.at(mid) = %lld, min = %lld\n",start,mid,end,num + p.at(mid),min);
    if(num == p.at(mid) || num + p.at(mid) < min){
        return binarySearch_min(mid + 1,end,num,min);
    }else if(num + p.at(mid) >= min){
        return binarySearch_min(start,mid,num,min);
    }
    return -1;
}

long long binarySearch_max(long long start,long long end,long long num,long long max){
    if(start > end){
        return start;
    }
    long long mid = (start + end)/2;
    if(num + p.at(mid) <= max){
        return binarySearch_max(mid + 1,end,num,max);
    }else if(num + p.at(mid) > max){
        return binarySearch_max(start,mid - 1,num, max);
    }
    return -1;
}

void printpair(long long min,long long max,long long num){
    for(int i = min;i<=max;++i){
        std::cout<<"("<<num<<","<<p.at(i)<<"), ";
    }
    printf("\n");
}


