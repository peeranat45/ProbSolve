#include <iostream>
#include <vector>

#define MAX_ARR 100010
//Global
long long array[MAX_ARR];


//Function
std::vector<long long> inversionSort(std::vector<long long> A,long long start,long long stop);
std::vector<long long> merge(std::vector<long long> left,std::vector<long long> right);

//Main Code
int main(void){
    long long N{};
    std::cin>>N;
    std::vector<long long> A{};
    for(long long i = 0;i<N;++i){
        long long input{};
        scanf("%lld",&input);
        // std::cin>>input;
        A.push_back(input);
    }
    inversionSort(A,0,N-1);
    

}

//Function Implement
std::vector<long long> inversionSort(std::vector<long long> A,long long start,long long stop){
    if(start >= stop){
        std::vector<long long> temp{};
        temp.push_back(A.at(start));
        return temp;
    }
    
    long long mid = start + (stop - start)/2;
    std::vector<long long> left = inversionSort(A,start,mid);
    std::vector<long long> right = inversionSort(A,mid+1,stop);
    std::vector<long long> sorted = merge(left,right);
    return sorted;

}

std::vector<long long> merge(std::vector<long long> left,std::vector<long long> right){
    
    long long index_left = 0;
    long long index_right = 0;
    std::vector<long long> sorted {};
    while(index_left != (long long)left.size() || index_right != (long long)right.size()){
        if(index_right == (long long)right.size()){
            sorted.insert(sorted.end(),left.begin(),left.end());
            return sorted;
        }else if(index_left == (long long)left.size()){
            sorted.insert(sorted.end(),right.begin(),right.end());
            return sorted;
        }
        else if(left.at(index_left) > right.at(index_right)){ 
            sorted.push_back(right.at(index_right));
            index_right++;
        }else{
            sorted.push_back(left.at(index_left));
            index_left++;
        }
    }
    return sorted;
}