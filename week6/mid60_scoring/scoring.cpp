#include <iostream>
#include <vector>

class score{
    public:
    int no;
    int maximum_score;
    int count;
};

int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<score> score_list{};
    score_list.resize(N);
    for(int i = 0;i<M;++i){
        int A{},S{};
        std::cin>>A>>S; // A=no,B=score
        if(score_list.at(A-1).count >= 5){
            score_list.at(A-1).maximum_score = 0;
        }else if(score_list.at(A-1).maximum_score < S){
            score_list.at(A-1).maximum_score = S;
            score_list.at(A-1).count += 1;
        }else{
            score_list.at(A-1).count += 1;
        }
    }
    int sum{};
    for(int i = 0;i<N;++i){
        sum += score_list.at(i).maximum_score;
        //printf("no = %d, score = %d,count = %d\n",i,score_list.at(i).maximum_score,score_list.at(i).count);
    }
    std::cout<<sum<<std::endl;
    return 0;
}