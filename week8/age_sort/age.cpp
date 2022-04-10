#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

std::vector<int> ages{};
int main(void){
    remove("output4.txt");
    std::ofstream outfile;
    outfile.open("output4.txt",std::ios_base::app);
    int size{};
    std::cin>>size;
    while(size != 0 ){
        
        // std::cin>>size;
        ages.resize(size);
        for(int i = 0;i<size;++i){
            std::cin>>ages.at(i);
        }
        std::sort(ages.begin(),ages.end());
        for(int i = 0;i<size;++i){
            if(i == size-1){
                // printf("i = %d\n",i);
                std::cout<<ages.at(i)<<std::endl;
                // outfile<<"Hello";
                outfile<<ages.at(i)<<std::endl;
            }else{
                std::cout<<ages.at(i)<<" ";
                outfile<<ages.at(i)<<" ";
            }
            // std::cout<<ages.at(i)<<" ";
            
        }
        // std::cout<<std::endl;
        ages.clear();
        std::cin>>size;
    }
}