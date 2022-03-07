#include "probelib.h"
#include <iostream>

int divied(int start,int end);

int main(){
    int size{};
    size = probe_init();
    int answer = divied(0,size-1);
    std::cout<<answer<<std::endl;
    return 0;
}

int divied(int start,int end){
    static int count = 0;
    count+=1;
    // printf("start = %d end  = %d count = %d\n",start,end,count);
    if(start == end){
        probe_answer(start);
        // return start;
    }
    int mid = (start + end)/2;
    int left = probe_check(0,mid);
    if(left == 1){
        divied(start,mid);
    }else{
        divied(mid + 1,end);
    }
    return -1;
}