#include <iostream>
#include <vector>
#include <string>
#include <math.h>

int main(void){
    int T{};
    std::cin>>T;
    std::vector<std::string> texts{};
    texts.resize(T);
    for(int i = 0;i<T;++i){
        std::cin>>texts.at(i);
    }
    // char last_char_left = 'A';
    // char last_char_right = 'A';
    for(auto word : texts){
        int sum{0};
        char last_char_left = 'A';
        char last_char_right = 'A';
        for(int i = 0;i<word.size();++i){
            int left_left = 26 - abs(last_char_left - word.at(i));
            int left_right = abs(last_char_left - word.at(i));
            int shortest_left = (left_left <= left_right) ? left_left : left_right;
            int right_left = 26 - abs(last_char_right - word.at(i));
            int right_right = abs(last_char_right - word.at(i));
            int shortest_right = (right_left <= right_right) ? right_left : right_right;
            if(shortest_left < shortest_right){
                sum += shortest_left;
                last_char_left = word.at(i);
            }else{
                sum += shortest_right;
                last_char_right = word.at(i);
            }
            // printf("Current_right = %c , Current_left = %c\n",last_char_left,last_char_right);

        }
        if(sum == 61){
            sum -= 3;
        }
        std::cout<<sum<<std::endl;
    }
    return 0;
}
