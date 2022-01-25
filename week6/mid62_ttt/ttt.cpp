#include <iostream>
#include <list>
#include <vector>


void addEdge(std::vector<std::vector<int>> &graph,int a,int b);

int main(void){
    std::vector<std::vector<int>> graph{};
    
    std::vector<int> prob{};
    std::vector<std::vector<int>> pair{};
    
    int N{},M{};
    std::cin>>N>>M;
    
    graph.resize(N);
    for(int i = 0;i<M;++i){
        int A{},B{};                        //0 = no color, 1 = color 1, 2 = color 2;
        std::cin>>A>>B;
        pair.push_back({A,B});
    }
    for(int j = 0;j<M;++j){
        int status = 0;
        std::vector<int> color{};
        color.resize(N + 1);
       // printf("No %d pair(%d,%d)\n",j,pair.at(j).at(0),pair.at(j).at(1));
            for(int i = 0;i<M;++i){
                if(i == j)
                    continue;
                int A{}, B{};
                A = pair.at(i).at(0);
                B = pair.at(i).at(1);
                //printf("Color.at(A) = %d , Color.at(B) = %d\n",color.at(A),color.at(B));
                if(color.at(A) == 0 && color.at(B) == 0){
                    color.at(A) = 1;
                    color.at(B) = 2;
                // printf("Case 1\n");
                }else if(color.at(A) == 1 && color.at(B) == 0){
                    color.at(B) = 2;
                    //printf("Case 2\n");
                }else if(color.at(A) == 2 && color.at(B) == 0){
                    color.at(B) = 1;
                // printf("Case 3\n");
                }else if(color.at(B) == 1 && color.at(A) == 0){
                    color.at(A) = 2;
                //  printf("Case 4\n");
                }else if(color.at(B) == 2 && color.at(A) == 0){
                    color.at(A) = 1;
                // printf("Case 5\n");
                }else if(color.at(A) == color.at(B)){
                // std::cout<<A<<" "<<B<<std::endl;
                    status = 1;
                    prob.push_back(A);
                    prob.push_back(B);
                }
            }
            if(status == 0){
                std::cout<<pair.at(j).at(0)<<" "<<pair.at(j).at(1)<<std::endl;
                return 0;
            }
       // printf("Color.at(A) = %d , Color.at(B) = %d\n",color.at(A),color.at(B));
    }   
    // int i = 0;
    // while(prob.size() != 2){
    //    // printf("N");
    //     int max = 0;
    //     for(auto num:prob){
    //         if(graph.at(num).size() > max)
    //             max = graph.size();
    //     }
    //    // printf("G");
    //     std::vector<int>::iterator it = prob.begin();
    //     for(auto num:prob){
    //         printf("num = %d",num);
    //         if(graph.at(num).size() < max){
    //             prob.erase(it);
    //             continue;
    //         }
    //         it++;
            
    //     }
    //    // printf("F");
    // }
    // std::cout<<prob.at(0)<<" "<<prob.at(1)<<std::endl;
    return 0;
}

void addEdge(std::vector<std::vector<int>> &graph,int a,int b){
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
}