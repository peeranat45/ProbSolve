#include <iostream>
#include <algorithm>
#include <vector>

class opt{
    public:
    int sum_prize;
    int k;
};

int main(void){
    int N{},M{},K{};
    std::cin>>N>>M>>K;
    std::vector<std::vector<int>> table{};
    table.resize(N);
    for(int i = 0;i<N;++i){
        table.at(i).resize(M);
        for(int j = 0;j<M;++j){
            std::cin>>table.at(i).at(j);
        }
    }
    
    //Create opt table
    std::vector<std::vector<opt>> opt_table{};
    opt_table.resize(N);
    for(int i = 0;i<N;++i){
        opt_table.at(i).resize(M);
    }
    //base case
    for(int j = 0;j<M;++j){
        opt_table.at(N-1).at(j).sum_prize = table.at(N-1).at(j);
    }
    for(int i = N-2;i>=0;--i){
        for(int j = M-1;j>=0;--j){
            // printf("i = %d,j = %d --->",i,j);
            int max = 0;
            int current_k = 0;
            if(j+1 < M){
                if(opt_table.at(i+1).at(j+1).k + 1 <= K && opt_table.at(i+1).at(j+1).sum_prize > opt_table.at(i+1).at(j).sum_prize){
                    // printf("  Bottom right  ");
                    max = opt_table.at(i+1).at(j+1).sum_prize;
                    current_k = opt_table.at(i+1).at(j+1).k + 1;
                }else{
                    max = opt_table.at(i+1).at(j).sum_prize;
                    current_k = opt_table.at(i+1).at(j).k;
                    // printf("   Below    ");
                }

            }else{
                    max = opt_table.at(i+1).at(j).sum_prize;
                    current_k = opt_table.at(i+1).at(j).k;
                    // printf("   Below    ");
            }
            // printf("max = %d --> ",max);
            

            if(j-1 >= 0){
                // printf("Bottom left = %d ",opt_table.at(i+1).at(j-1).sum_prize);
                // printf("opt_table.at(i+1).at(j-1).k + 1 = %d ",opt_table.at(i+1).at(j-1).k + 1);
                if(opt_table.at(i+1).at(j-1).k + 1 <= K && opt_table.at(i+1).at(j-1).sum_prize > max){
                    max = opt_table.at(i+1).at(j-1).sum_prize;
                    current_k = opt_table.at(i+1).at(j-1).k + 1;
                    // printf("     Bottom Left    ");
                }
            }
            // printf("final_max = %d\n",max);

            opt_table.at(i).at(j) = {max + table.at(i).at(j),current_k};
        }
    }
    int max = 0;
    for(int j = 0;j<M;++j){
        if(opt_table.at(0).at(j).sum_prize > max){
            max = opt_table.at(0).at(j).sum_prize;
        }
    }
    std::cout<<max<<std::endl;

    // for(int i = 0;i<N;++i){
    //     for(int j = 0;j<M;++j){
    //         printf("(sum_prize = %d, k = %d) ",opt_table.at(i).at(j).sum_prize,opt_table.at(i).at(j).k);
    //     }
    //     std::cout<<std::endl;
    // }
    return 0;


}
