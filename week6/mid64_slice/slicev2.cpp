#include <iostream>
#include <vector>
#include <algorithm>

void printWood(std::vector<int> wood);

int main(void){
    int M{};
    std::cin>>M;
    std::vector<int> v{};
    std::vector<int> wood{};
    std::vector<int> wood_current_length{};
    wood_current_length.resize(5);
    wood.resize(M+1);
    v.resize(M);
    for(int i = 0;i<M;++i){
        std::cin>>v.at(i);
    }
    int tower_status = 1;
    while(tower_status){
        tower_status = 0;
        for(int i = 0;i<M;++i){
            int height = v.at(i) - 5;
            v.at(i) -= 5;
            //printf("height = %d i = %d\n",height,i);
            if(height >= 0){
                wood_current_length.at(0) += 1;
                wood_current_length.at(1) += 1;
                wood_current_length.at(2) += 1;
                wood_current_length.at(3) += 1;
                wood_current_length.at(4) += 1;
                tower_status = 1;
            }else if(height == -1){
                wood_current_length.at(0) += 1;
                wood_current_length.at(1) += 1;
                wood_current_length.at(2) += 1;
                wood_current_length.at(3) += 1;

                wood.at(wood_current_length.at(4)) += 1;
                wood_current_length.at(4) = 0;
                tower_status = 1;
            }else if(height == -2){
                wood_current_length.at(0) += 1;
                wood_current_length.at(1) += 1;
                wood_current_length.at(2) += 1;
                
                wood.at(wood_current_length.at(4)) += 1;
                wood_current_length.at(4) = 0;
                wood.at(wood_current_length.at(3)) += 1;
                wood_current_length.at(3) = 0;
                tower_status = 1;
            }else if(height == -3){
                wood_current_length.at(0) += 1;
                wood_current_length.at(1) += 1;
                
                wood.at(wood_current_length.at(4)) += 1;
                wood_current_length.at(4) = 0;
                wood.at(wood_current_length.at(3)) += 1;
                wood_current_length.at(3) = 0;
                wood.at(wood_current_length.at(2)) += 1;
                wood_current_length.at(2) = 0;
                tower_status = 1;
            }else if(height == -4){
                wood_current_length.at(0) += 1;
                
                wood.at(wood_current_length.at(4)) += 1;
                wood_current_length.at(4) = 0;
                wood.at(wood_current_length.at(3)) += 1;
                wood_current_length.at(3) = 0;
                wood.at(wood_current_length.at(2)) += 1;
                wood_current_length.at(2) = 0;
                wood.at(wood_current_length.at(1)) += 1;
                wood_current_length.at(1) = 0;
                tower_status = 1;
            }else if(height == -5){
                wood.at(wood_current_length.at(4)) += 1;
                wood_current_length.at(4) = 0;
                wood.at(wood_current_length.at(3)) += 1;
                wood_current_length.at(3) = 0;
                wood.at(wood_current_length.at(2)) += 1;
                wood_current_length.at(2) = 0;
                wood.at(wood_current_length.at(1)) += 1;
                wood_current_length.at(1) = 0;
                wood.at(wood_current_length.at(0)) += 1;
                wood_current_length.at(0) = 0;
                tower_status = 1;
            }
           // printWood(wood);
            
        }
        //printf("---------------------------------\n");
        //printWood(wood);
        wood.at(wood_current_length.at(4)) += 1;
        wood_current_length.at(4) = 0;
        wood.at(wood_current_length.at(3)) += 1;
        wood_current_length.at(3) = 0;
        wood.at(wood_current_length.at(2)) += 1;
        wood_current_length.at(2) = 0;
        wood.at(wood_current_length.at(1)) += 1;
        wood_current_length.at(1) = 0;
        wood.at(wood_current_length.at(0)) += 1;
        wood_current_length.at(0) = 0;
        //printWood(wood);
        //printf("---------------------------------\n");

    }
    int count{0};
    for(int i = 1;i<wood.size();++i){
        if(wood.at(i) != 0)
            count++;
    }
    std::cout<<count<<std::endl;
    for(int i = 1;i<wood.size();++i){
        if(wood.at(i) != 0)
            std::cout<<i<<" "<<wood.at(i)<<std::endl;
    }

    return 0;
}

void printWood(std::vector<int> wood){
    for(int i = 1;i<wood.size();++i){
        printf("woodlength %d : i -> %d\n",i,wood.at(i));
    }
}