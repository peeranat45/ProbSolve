#include <iostream>
#include <vector>


class match{
    public:
    int A;
    int B;
};
int main(void){
    int N{},M{};
    std::cin>>N>>M;
    std::vector<int> colors{};
    colors.resize(N+1);
    for(int i = 1;i<=N;++i){
        colors.at(i) = -1;
    }
    std::vector<match> matches{};
    std::vector<int> counts{};
    counts.resize(100010);
    for(int i = 0;i<M;++i){
        int A{},B{};
        std::cin>>A>>B;
        matches.push_back({A,B});
        counts.at(A) += 1;
        counts.at(B) += 1;
    }
    


    int count{0};
    //printf("Hello World\n");
    for(int i = 0;i<M;++i){
        int A{},B{};
        std::cin>>A>>B;
        //printf("A = %d, B = %d\n",colors.at(A),colors.at(B));
        if(colors.at(A) == -1 && colors.at(B) == -1){
            colors.at(A) = 0;
            colors.at(B) = 1;
        }else if(colors.at(A) == -1){
            colors.at(A) = (colors.at(B) + 1) % 2;
        }else if(colors.at(B) == -1){
            colors.at(B) = (colors.at(A) + 1) % 2;
        }else if(colors.at(A) == colors.at(B)){
            continue;;
        }
        count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}