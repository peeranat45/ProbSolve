#include <iostream>
#include <vector>
int something(std::vector<int> y,int start , int end);
std::vector<int> x{1,2,1,-20,3,4,2,1};
int main(void){
    std::vector<int> y{};
    y.resize(x.size());
    for(int i = 0;i<x.size();++i){
        int sum = 0;
        for(int j = 0;j<i;++j){
            sum += x.at(j);
        }
        y.at(i) = sum;
    }

    std::cout<<something(y,0,x.size()-1)<<std::endl;
    // std::cout<<2<<std::endl;

}

int something(std::vector<int> y,int start , int end){
    if(start == end){
        return start;
    }
    int mid=  (start + end)/2;
    int left = something(y,start,mid);
    int right = something(y,mid + 1,end);

    if(y.at(left) > y.at(right)){
        return right;
    }else{
        return left;
    }
}