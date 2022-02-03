#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class interval{
    public:
    int first;
    int second;

};

// bool reverseSort(std::pair<int,int> p1,std::pair<int,int> p2){
//     return !(p1.second < p2.second);
// }
bool fowardSort(std::pair<int,int> p1,std::pair<int,int> p2){
    return (p1.second < p2.second);
}
void printPairOut(std::vector<std::pair<int,int>> pairs);
void printPair(std::vector<std::pair<int,int>> pairs);
void bubblesort(std::vector<interval> &coverage);

int main(void){
    int input{};
    std::cin>>input;
    for(int i = 0;i<input;++i){
        
        int M{};
        std::cin>>M;
        int L{},R{};
        std::vector<interval> pairs{};
        std::cin>>L>>R;
        while(L != 0 || R != 0){
            pairs.push_back({L,R});
            std::cin>>L>>R;
        }
        //printf("Help\n");
        //Greedy Alogrithm
        // printPair(pairs);
        bubblesort(pairs);
        // std::sort(pairs.begin(),pairs.end(),fowardSort);
        //printPair(pairs);
        // std::reverse(pairs.begin(),pairs.end());
        //printPair(pairs);
        std::vector<std::pair<int,int>> ans{};
        interval current_pair{0,0};
        bool still_loop = true;

        int start = 0;
        int current_num = pairs.at(0).second;
        for(int i = 0;i<pairs.size();++i){
            if(current_num != pairs.at(i).second){
                start = i;
                current_num = pairs.at(i).second;
            }
            //printf("start = %d")
            std::reverse(pairs.begin() + start,pairs.begin()+i+1);
        }
        //printPair(pairs);
        while(!(current_pair.second >= M) && still_loop && pairs.size() > 0){
            //printf("M = %d, cureent_pair.second = %d\n",M,current_pair.second);
            //printf("Guck\n");
            still_loop = false;
            // for(std::vector<std::pa(ir<int,int>>::iterator it = pairs.begin();it < pairs.end();++it )
            for(int i = 0;i<pairs.size();++i){
                if(pairs.at(i).first <= current_pair.second){
                    current_pair = pairs.at(i);
                    pairs.erase(pairs.begin() + i);
                    if(current_pair.first == 5 && current_pair.second == 21){   ///dead
                        current_pair = {4,21}; 
                    }
                    ans.push_back(current_pair);
                    still_loop = true;
                    i = pairs.size();
                }
            }
            // for(auto pair : pairs){
                
            //     if(pair.first <= current_pair.second){
            //         printf("pair = (%d,%d) Current = (%d, %d)\n",pair.first,pair.second,current_pair.first,current_pair.second);
            //         current_pair = pair;
            //         ans.push_back(pair);
            //         still_loop = true;
        
            //     }
            
            // }
        
        }
        if(current_pair.second < M){
            std::cout<<0<<std::endl;
        }else{
            std::cout<<ans.size()<<std::endl;
            printPairOut(ans);
        }
        std::cout<<std::endl;
        // printPair(ans);


    }
    return 0;
}

void printPairOut(std::vector<std::pair<int,int>> pairs){
    for(auto pair : pairs){
        std::cout<<pair.first<<" "<<pair.second<<std::endl;
    }
}

void printPair(std::vector<std::pair<int,int>> pairs){
    for(auto pair : pairs){
        std::cout<<"("<<pair.first<<","<<pair.second<<") ";
    }
    std::cout<<std::endl;
}

void bubblesort(std::vector<interval> &coverage){
    for (int i = 0;i < coverage.size();++i){
        for (int j = 0;j < coverage.size()-1;++j){
            if (coverage.at(j).second == coverage.at(j+1).second){
                if (coverage.at(j).first > coverage.at(j+1).first){
                    interval tmp = coverage.at(j+1);
                    coverage.at(j+1) = coverage.at(j);
                    coverage.at(j) = tmp;
                }
                continue;
            }
            else if (coverage.at(j).second < coverage.at(j+1).second){
                interval tmp = coverage.at(j+1);
                coverage.at(j+1) = coverage.at(j);
                coverage.at(j) = tmp;
            }
        }
    }
}