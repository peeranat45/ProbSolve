#include <iostream>
#include <vector>
#include <list>

class DNA{
    public:
    int start;
    int end;
    std::list<int> dna_list;
};

int main(void){
    int N{},L{};
    std::cin>>L>>N;
    std::vector<DNA> dna{};
    int current_dna = 1;
    for(int i = 0;i<L;++i){
        int M{};
        std::cin>>M;
        DNA temp_dna = {current_dna,current_dna+M-1};
        for(int j = current_dna;j<M + current_dna;j++){
            temp_dna.dna_list.push_back(j);
        }
        dna.push_back(temp_dna);
    } 
    std::list<int>::iterator bot_position = dna.at(0).dna_list.begin();
}

void dna_function(std::vector<DNA> dna,std::list<int>::iterator bot_position ,char command,int func){
    if(command == 'B'){
        if(dna.at(0).dna_list.begin() == bot_position){
            return;
        }else{
            bot_position--;
            return;
        }
    }else if(command == 'F'){
        std::list<int>::iterator temp = dna.at(0).dna_list.end();
        temp--;
        if(bot_position == temp){
            return;
        }else{
            bot_position++;
            return;
        }
    }else if(command == 'C'){
        std::list<int> temp_list = 
    }

}