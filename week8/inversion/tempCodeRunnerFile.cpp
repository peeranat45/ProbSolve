#include <iostream>
#include <vector>

//Global
long count = 0;


//Function
std::vector<long> inversionSort(std::vector<long> A,long start,long stop);
std::vector<long> merge(std::vector<long> left,std::vector<long> right);

//Main Code
int main(void){
    long N{};
    std::cin>>N;
    std::vector<long> A{};
    for(long i = 0;i<N;++i){
        long input{};
        std::cin>>input;
        A.push_back(input);
    }
    inversionSort(A,0,N-1);
    std::cout<<count<<std::endl;

}

//Function Implement
std::vector<long> inversionSort(std::vector<long> A,long start,long stop){
    //prlongf("Start = %ld,stop = %ld\n",start,stop);
    if(start == stop){
        std::vector<long> temp{};
        temp.push_back(A.at(start));
        return temp;
    }
    
    long mid = (start + stop)/2;
    std::vector<long> left = inversionSort(A,start,mid);
    std::vector<long> right = inversionSort(A,mid+1,stop);

    std::vector<long> sorted = merge(left,right);
    return sorted;

}

std::vector<long> merge(std::vector<long> left,std::vector<long> right){
    
    long index_left = 0;
    long index_right = 0;
    std::vector<long> sorted {};
    while(index_left != left.size() || index_right != right.size()){
       // prlongf("Index_left = %d, Index_right = %d\n",index_left,index_right);
        if(index_right == right.size()){
            sorted.insert(sorted.end(),left.begin(),left.end());
            // sorted.push_back(left.at(index_left));
            // index_left++;
            return sorted;
        }else if(index_left == left.size()){
            sorted.insert(sorted.end(),right.begin(),right.end());
            // sorted.push_back(right.at(index_right));
            // index_right++;
            return sorted;
        }
        else if(left.at(index_left) > right.at(index_right)){  //inverse
            count++;
            sorted.push_back(right.at(index_right));
            index_right++;
        }else{
            sorted.push_back(left.at(index_left));
            index_left++;
        }
    }
    return sorted;
}